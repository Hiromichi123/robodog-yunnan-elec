# Local safety perception: not field-validated

The node is OFF by default (`local_safety:=false`). Starting it without
`calibration_validated:=true` publishes only invalid diagnostic snapshots. Setting
that boolean is an operator assertion after measurement, not calibration itself.

Before enforce-mode motion, measure and validate:

- body/lidar/camera optical TFs, including conflicting camera TF parents;
- timestamps and synchronization (no implicit receive-time substitution);
- front, side, turn-sweep and stopping-path coverage;
- actual ground z in startup-navigation frame and collision-height range;
- `self_half_length`, `self_half_width`, `self_min_z`, `self_max_z`: a measured
  3-D robot-only envelope. Never expand this box to hide environment obstacles.
- footprint/leg-wheel envelope, uncertainty margin, reaction latency and braking
  distance in the controller (separate from self-return exclusion).

Six height bands plus floor evidence must be observed before an XY cell becomes
free. **The initial underbody footprint may never have been observed and can
therefore remain unknown. With the controller's initial-footprint seed disabled,
this intentionally blocks starting.** That is an explicit field-validation gate,
not a demonstrated ready-to-drive feature. Do not change unknown to free simply
to make the robot move. Any narrowly scoped initial occupied-footprint exception
requires independent operator verification and must not clear surrounding blind
space or override detected occupied cells.

Free evidence expires to unknown; occupied evidence survives expiry until three
new positive same-band clearing frames. Sparse clouds, low obstacles, glossy
surfaces and occluded floor can cause conservative blocking. These sensors do not
provide guaranteed detection of transparent objects or drop-offs.

`LocalSafetyMap.valid` means sensor/coordinate freshness and declared calibration
passed; it does NOT mean the whole map or any arbitrary path is free. Consumers
must inspect every required footprint cell, and must reject unknown cells.
