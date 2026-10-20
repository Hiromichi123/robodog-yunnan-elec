# One coherent near-field snapshot. Invalid snapshots MUST stop enforced motion.
# header.stamp is the oldest contributing sensor acquisition time, not publish time.
std_msgs/Header header
string session_id
# Identity of the immutable startup configuration. Missing/mismatched identity is invalid.
string config_revision
uint64 sequence
bool valid
string reason
nav_msgs/OccupancyGrid grid
float32 observation_age_s
