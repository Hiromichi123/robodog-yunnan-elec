#!/usr/bin/env python3
"""Read aircraft thrust; actions require explicit --enable-actions and dog opt-in."""
import argparse
import json
import math
import os
from pathlib import Path
import re
import tempfile
import time
import uuid


class ThrustGate:
    def __init__(self, state, emit, now=time.time):
        self.path=Path(state);self.emit=emit;self.now=now
        self.highest={}
        self.consumed={}
        if self.path.exists():
            value=json.loads(self.path.read_text(encoding='utf-8'))
            if not isinstance(value,dict):raise ValueError('Invalid dedup journal; refusing actions')
            self.consumed=value

    def persist(self):
        self.path.parent.mkdir(parents=True,exist_ok=True)
        fd,name=tempfile.mkstemp(dir=str(self.path.parent))
        try:
            with os.fdopen(fd,'w',encoding='utf-8') as out:
                json.dump(self.consumed,out,allow_nan=False);out.flush();os.fsync(out.fileno())
            os.replace(name,self.path)
            directory=os.open(str(self.path.parent),os.O_RDONLY)
            try:os.fsync(directory)
            finally:os.close(directory)
        finally:
            if os.path.exists(name):os.unlink(name)

    def receive(self,value):
        if not isinstance(value,dict):return 'invalid'
        if value.get('version')!=1 or type(value.get('version')) is not int:return 'invalid'
        run=value.get('run_id');session=value.get('session');seq=value.get('seq')
        if not isinstance(run,str) or not re.fullmatch('[a-f0-9]{32}',run):return 'invalid'
        try:
            if not isinstance(session,str) or str(uuid.UUID(session))!=session:return 'invalid'
        except (ValueError,AttributeError):return 'invalid'
        if type(seq) is not int or seq<0:return 'invalid'
        for k in ('thrust','at','expires_at'):
            x=value.get(k)
            if type(x) not in (int,float) or not math.isfinite(x):return 'invalid'
        now=self.now();at=value['at'];end=value['expires_at']
        if not 0<=value['thrust']<=1:return 'invalid'
        if not 0<end-at<=.751 or at>now+.1 or now>=end or now-at>.75:return 'stale'
        key=session+'/'+run
        if seq<=self.highest.get(key,-1):return 'duplicate'
        self.highest[key]=seq
        if value.get('stage')!='takeoff' or value.get('armed') is not True or value.get('connected') is not True:return 'not_takeoff'
        if value['thrust']<.43:return 'below_threshold'
        if key in self.consumed:return 'consumed'
        # Commit before publish: crash may omit an action, never duplicate one.
        self.consumed[key]=dict(at=at,seq=seq,thrust=value['thrust'])
        self.persist()
        self.emit(dict(value,event_id=key))
        return 'triggered'


def main():
    import fcntl
    parser=argparse.ArgumentParser()
    parser.add_argument('--enable-actions',action='store_true',help='Publish internal getdown events; dog_node also requires opt-in')
    parser.add_argument('--state',default=str(Path.home()/'.local/state/takeoff-link/consumed.json'))
    parser.add_argument('--input-topic',default='/uav/takeoff/thrust')
    parser.add_argument('--event-topic',default='/dog/takeoff_getdown')
    args,ros_args=parser.parse_known_args()
    import rclpy
    from rclpy.node import Node
    from std_msgs.msg import String
    from rclpy.context import Context
    # Isolate Foxy discovery on domain 43; dog controls retain domain 0.
    rclpy.init(args=ros_args, domain_id=43);node=Node('takeoff_thrust_receiver')
    dog_context=None;dog_node=None
    if args.enable_actions:
        dog_context=Context();rclpy.init(args=[],context=dog_context,domain_id=0)
        dog_node=Node('takeoff_thrust_dog_relay',context=dog_context)
    singleton=None
    if args.enable_actions:
        lock=Path(args.state+'.lock');lock.parent.mkdir(parents=True,exist_ok=True)
        singleton=lock.open('a');fcntl.flock(singleton,fcntl.LOCK_EX|fcntl.LOCK_NB)
    publisher=dog_node.create_publisher(String,args.event_topic,10) if dog_node else None
    def emit(value):
        if publisher.get_subscription_count()==0:
            node.get_logger().error('No opted-in dog receiver; event consumed without action. Check dog state manually.')
            return
        msg=String();msg.data=json.dumps(value,ensure_ascii=False,allow_nan=False);publisher.publish(msg)
        node.get_logger().warn('Takeoff threshold event published; getdown completion requires dog status, not this log')
    gate=ThrustGate(args.state,emit) if args.enable_actions else None
    health={'at':0.0,'count':0,'value':{}}
    def report():
        age=time.time()-health['at']
        ready=publisher is not None and publisher.get_subscription_count()>0
        if age>2:
            node.get_logger().warn('No fresh aircraft thrust; getdown link NOT ready')
        else:
            v=health['value']
            node.get_logger().info('Thrust link samples=%s thrust=%s stage=%s armed=%s age=%.3fs dog_subscriber=%s' %
                (health['count'],v.get('thrust'),v.get('stage'),v.get('armed'),age,ready))
        if publisher is not None and not ready:
            node.get_logger().error('No opted-in dog subscriber; getdown link NOT ready')
    timer=node.create_timer(5.0,report)
    def receive(msg):
        try:
            if len(msg.data.encode())>8192:return
            value=json.loads(msg.data)
            if not isinstance(value,dict):return
            at=value.get('at')
            if type(at) in (int,float) and math.isfinite(at) and -.1<=time.time()-at<=.75:
                health.update(at=at,count=health['count']+1,value=value)
            if gate:
                result=gate.receive(value)
                if result=='triggered':node.get_logger().info('Threshold >=0.43 consumed once for '+value['run_id'])
            else:
                # Separate ephemeral journal: monitor must not consume production run IDs.
                node.get_logger().info('MONITOR ONLY '+json.dumps(value,ensure_ascii=False))
        except (ValueError,TypeError,OSError) as exc:
            node.get_logger().error('Rejected thrust / journal error: '+str(exc))
    sub=node.create_subscription(String,args.input_topic,receive,10)
    node.get_logger().info('Actions ENABLED' if gate else 'Read-only monitor: no dog event publisher')
    try:rclpy.spin(node)
    finally:
        node.destroy_node();rclpy.shutdown()
        if dog_node:dog_node.destroy_node()
        if dog_context:rclpy.shutdown(context=dog_context)
        if singleton:singleton.close()


if __name__=='__main__':main()
