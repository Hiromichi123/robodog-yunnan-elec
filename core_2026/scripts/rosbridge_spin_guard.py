"""Project-owned guard for rclpy's subscription-destruction wait-set race."""
from collections import deque
import time


def wait_set_destruction(error):
    if 'destruction was requested' not in str(error):
        return False
    tb = error.__traceback__
    while tb is not None:
        code = tb.tb_frame.f_code
        if code.co_name == '_wait_for_ready_callbacks' and code.co_filename.endswith('/rclpy/executors.py'):
            return True
        tb = tb.tb_next
    return False


def spin_guarded(executor, stop, context_ok, invalid_handle, report_failure,
                 warn, recoverable=wait_set_destruction, clock=time.monotonic):
    """Report fatal exits to the event loop instead of leaving an inert WS server."""
    retries = deque()
    try:
        while not stop.is_set() and context_ok():
            try:
                executor.spin_once(timeout_sec=0.1)
            except invalid_handle as error:
                if stop.is_set() or not context_ok():
                    return
                now = clock()
                while retries and now - retries[0] > 10.0:
                    retries.popleft()
                if not recoverable(error) or len(retries) >= 5:
                    raise
                retries.append(now)
                # The failed generator references entities removed by unsubscribe.
                # rclpy recreates it on the next spin_once when it is None.
                executor._cb_iter = None
                executor.wake()
                warn('Recovering destroyed-subscription wait set (%d/5)' % len(retries))
                if stop.wait(min(0.05 * 2 ** (len(retries) - 1), 0.4)):
                    return
        if not stop.is_set():
            raise RuntimeError('ROS context ended while WebSocket server was running')
    except Exception as error:
        report_failure(error)
