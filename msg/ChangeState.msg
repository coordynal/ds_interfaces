uint8 DISABLED=0
uint8 ENABLED=1
uint8 ESTOP=2
uint8 UNKNOWN=3

uint8 old_control_state
uint8 control_state # new control state
string slave_id "" # target to change the state for. If empty, applies to all slaves.
