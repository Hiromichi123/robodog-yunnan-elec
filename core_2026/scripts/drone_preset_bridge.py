#!/usr/bin/env python3
"""Listen only at startup. Never execute a flight without an explicit request."""
import json
from pathlib import Path
import queue
import sys
import threading
import time
import re

# The shared HTTP client is part of the board's web repository.
sys.path.insert(0,str(Path.home()/'web'))
from drone_client import DroneClient


def valid_id(value):
    return isinstance(value,str) and re.fullmatch('[a-f0-9]{32}',value)


class Bridge:
    def __init__(self, client, publish):
        self.client,self.publish=client,publish
        self.lock=threading.RLock()
        self.active=None
        self.cancelled=set()
        self.statuses={}
        self.work=queue.PriorityQueue()
        self.counter=0

    def receive(self, text):
        try:
            data=json.loads(text)
            if not isinstance(data,dict) or not valid_id(data.get('request_id')):
                return
            key=data['request_id']
            action=data.get('action')
            if action not in ('execute','cancel'):
                return
            with self.lock:
                self.counter+=1
                if action=='cancel':
                    self.cancelled.add(key)
                    self.work.put((0,self.counter,data))
                    return
                if key in self.cancelled:
                    return
                if key in self.statuses:
                    self.publish(self.statuses[key]);return
                if self.active and self.active!=key:
                    self.emit(key,'failed','另一个无人机任务正在执行');return
                self.active=key
                self.emit(key,'preparing','已收到已确认预设请求，等待飞机')
                self.work.put((1,self.counter,data))
        except (ValueError,TypeError):
            return

    def emit(self,key,phase,message,**extra):
        status=dict(request_id=key,phase=phase,message=message,at=time.time(),**extra)
        self.statuses[key]=status
        self.publish(status)

    def process(self):
        try:
            _,_,data=self.work.get(timeout=.1)
        except queue.Empty:
            return
        key=data['request_id'];action=data.pop('action')
        try:
            if action=='cancel':
                result=self.client.call('cancel',{'request_id':key})
            else:
                if key in self.cancelled:
                    result=self.client.call('cancel',{'request_id':key})
                else:
                    result=self.client.call('execute',data)
            self.accept(key,result)
        except Exception as exc:
            # Never repeat execute after an ambiguous HTTP result.
            self.emit(key,'intervention','指令结果未知，需要核实飞机：'+str(exc))
            if action=='execute':
                with self.lock:
                    self.cancelled.add(key);self.counter+=1
                    self.work.put((0,self.counter,{'action':'cancel','request_id':key}))

    def accept(self,key,result):
        if result.get('request_id')!=key:
            raise ValueError('无人机请求 ID 不匹配')
        phase=result.get('phase','intervention')
        self.emit(key,phase,result.get('message',''),run_id=result.get('run_id'))
        if phase in ('done','cancelled','failed') and self.active==key:
            self.active=None

    def poll(self):
        with self.lock:
            key=self.active
        if key:
            try:self.accept(key,self.client.call('status?request_id='+key))
            except Exception as exc:self.emit(key,'intervention','飞机状态失联，不能确认降落：'+str(exc))


def main():
    import rclpy
    from rclpy.node import Node
    from std_msgs.msg import String
    rclpy.init()
    node=Node('drone_preset_bridge')
    pub=node.create_publisher(String,'/dog/drone/status',10)
    def publish(value):
        msg=String();msg.data=json.dumps(value,ensure_ascii=False);pub.publish(msg)
    bridge=Bridge(DroneClient(),publish)
    sub=node.create_subscription(String,'/dog/drone/request',lambda m:bridge.receive(m.data),10)
    def worker():
        last=0
        while rclpy.ok():
            bridge.process()
            if time.monotonic()-last>.5:
                last=time.monotonic();bridge.poll()
    threading.Thread(target=worker,daemon=True).start()
    try:rclpy.spin(node)
    finally:node.destroy_node();rclpy.shutdown()


if __name__=='__main__':main()
