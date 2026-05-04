#pragma once

#define TOPIC_HEARTBEAT "master_node/heartbeat"
#define TOPIC_CHANGE_STATE "master_node/change_state"
#define TOPIC_MASTER_CONNECT "master_node/connect"

#define SERVICE_CHANGE_CONTROL_STATE "master_node/change_control_state"
#define SERVICE_CHANGE_CONNECTION "master_node/change_connection"
#define SERVICE_REQUEST_SLAVE_LIST "master_node/request_slave_list"

enum ControlState {
    DISABLED = 0,
    ENABLED = 1,
    ESTOP = 2,
    UNKNOWN = 3,
};
