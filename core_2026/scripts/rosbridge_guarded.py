#!/usr/bin/env python3
"""Run the installed rosbridge node with a supervised, bounded ROS spin guard.

The installed environment is read-only; keep ROS parameters/remappings on argv.
"""
import asyncio
from pathlib import Path
import runpy
import signal
import sys
import threading

from rosbridge_spin_guard import spin_guarded


async def async_main():
    import rclpy
    from rclpy.executors import SingleThreadedExecutor
    from rclpy.exceptions import InvalidHandle

    upstream = Path(sys.prefix) / 'lib/rosbridge_server/rosbridge_websocket'
    node_type = runpy.run_path(str(upstream), run_name='jxg_rosbridge_upstream')['RosbridgeWebsocketNode']
    # Track this node's listeners without patching the installed package on disk.
    server_globals = node_type._start_server.__globals__
    upstream_http_server = server_globals['HTTPServer']
    servers = []

    class TrackedHTTPServer(upstream_http_server):
        def __init__(self, *args, **kwargs):
            super().__init__(*args, **kwargs)
            servers.append(self)

    server_globals['HTTPServer'] = TrackedHTTPServer
    rclpy.init(args=sys.argv, signal_handler_options=rclpy.signals.SignalHandlerOptions.NO)
    node = node_type()
    if node.use_events_executor:
        node.destroy_node()
        rclpy.shutdown()
        raise RuntimeError('The guarded wrapper requires SingleThreadedExecutor')
    executor = SingleThreadedExecutor()
    executor.add_node(node)
    loop = asyncio.get_running_loop()
    done = asyncio.Event()
    stop = threading.Event()
    failures = []

    def failed(error):
        def deliver():
            failures.append(error)
            done.set()
        loop.call_soon_threadsafe(deliver)

    def request_stop():
        stop.set()
        done.set()

    signals = (signal.SIGINT, signal.SIGTERM)
    for signum in signals:
        loop.add_signal_handler(signum, request_stop)
    worker = threading.Thread(target=spin_guarded,
                              args=(executor, stop, node.context.ok, InvalidHandle,
                                    failed, node.get_logger().warning),
                              name='jxg-rosbridge-spin', daemon=True)
    worker.start()
    try:
        await done.wait()
    finally:
        # Close the transport first: fatal executor errors must never leave an
        # apparently connected browser waiting forever for ROS callbacks.
        stop.set()
        for server in servers:
            server.stop()
        for server in servers:
            try:
                await asyncio.wait_for(server.close_all_connections(), timeout=2.0)
            except asyncio.TimeoutError:
                pass  # Process exit is the final bounded transport cleanup.
        executor.wake()
        executor.shutdown(timeout_sec=2.0)
        worker.join(timeout=2.0)
        if not worker.is_alive():
            node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
        for signum in signals:
            loop.remove_signal_handler(signum)
    if worker.is_alive():
        raise RuntimeError('rosbridge executor did not stop within the shutdown deadline')
    if failures:
        # asyncio.run closes its loop; process exit closes listener and clients.
        raise RuntimeError('rosbridge ROS executor failed; closing WebSocket server') from failures[0]


def main():
    asyncio.run(async_main())


if __name__ == '__main__':
    main()
