#pragma once

#define TOPIC_HEARTBEAT "master_node/heartbeat"
#define TOPIC_CONTROL_CHANGE "master_node/control_change"
#define TOPIC_MASTER_CONNECT "master_node/connect"

#define SERVICE_CHANGE_CONTROL_STATE "master_node/change_control_state"
#define SERVICE_NEW_CONNECTION "master_node/new_connection"

enum ControlState {
    DISABLED = 0,
    ENABLED = 1,
    ESTOP = 2,
    UNKNOWN = 3,
};
