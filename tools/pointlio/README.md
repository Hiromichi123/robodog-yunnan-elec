# Independent MID360 driver and on-demand SLAM

- `jxg-lidar.service` owns the MID360 driver; it starts at boot independently of Web/rosbridge and SLAM.
- `pointlio_run.sh` owns only SLAM, pose/TF, local safety, and optional recording/reconstruction. Stopping it leaves raw lidar/IMU running.
- Web SLAM process matching must exclude `livox_ros_driver2_node`.

## Deployment on brain

Copy `lidar_driver_run.sh` to `~/lidar_driver_run.sh` (executable), `check_lidar_ready.py` to `~/pointlio_local/`, and patch the deployed `pointlio_inner.sh`/`pointlio_run.sh` to match the driver split. Preserve local mapper affinity/thread settings. Existing `~/rosrun.sh` and `~/pointlio_local/check_lidar_input.py` are required.

After gracefully stopping the old combined SLAM stack, install `deploy/brain/systemd/jxg-lidar.service` to `/etc/systemd/system/`, run `systemctl daemon-reload` and `systemctl enable --now jxg-lidar`. Then start SLAM through Web. Do not run two drivers against the same UDP ports.

## Diagnostics

`systemctl status jxg-lidar` and `journalctl -u jxg-lidar -n 100` show driver errors. The SLAM preflight requires two actual nonempty lidar messages and two IMU messages within 15 seconds; merely advertising topics is not enough. `Restart=always` retries exited drivers after 5 seconds, but does not detect a live driver that stops publishing.

## 2026-10-30 deployment

Backup: `~/backups/lidar-split-20261030-131752/`. Source/deployed mapper performance settings intentionally remain different. Web assets have version `2026103001`. Tested SLAM stop/start leaves the sole driver PID unchanged and raw topics publishing. Cold boot has not been tested.

To disable boot startup only: `sudo systemctl disable jxg-lidar` (does not stop the running driver). For a full rollback, first gracefully stop SLAM, then stop/disable the independent driver and restore the backed-up scripts and Web files; restart Web before restoring the old combined stack. Never start the old combined stack while the independent driver is still running.
