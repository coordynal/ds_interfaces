#include "rclcpp/rclcpp.hpp"

#include "ds_interfaces/Constants.hpp"
#include "ds_interfaces/msg/change_state.hpp"
#include "ds_interfaces/msg/heartbeat.hpp"
#include "ds_interfaces/msg/master_broadcast.hpp"
#include "ds_interfaces/msg/string_array.hpp"
#include "ds_interfaces/srv/change_connection.hpp"
#include "ds_interfaces/srv/change_control_state.hpp"
#include "ds_interfaces/srv/request_edit_connection.hpp"
#include "ds_interfaces/srv/request_slave_list.hpp"

namespace ds_interfaces {
    // Primary template
    template <typename T> static rclcpp::QoS getQoS() {
        return rclcpp::QoS(rclcpp::KeepLast(10));
    }
    template <typename T> static std::string getTopicName() {
        throw std::runtime_error(
            "getTopicName not implemented for this type! (DS Interfaces only)");
    }

    template <> [[maybe_unused]] rclcpp::QoS getQoS<ds_interfaces::msg::Heartbeat>() {
        return rclcpp::QoS(rclcpp::KeepLast(1)).best_effort().durability_volatile();
    }
    template <> [[maybe_unused]] std::string getTopicName<ds_interfaces::msg::Heartbeat>() {
        return TOPIC_HEARTBEAT;
    }

    template <> [[maybe_unused]] rclcpp::QoS getQoS<ds_interfaces::msg::ChangeState>() {
        return rclcpp::QoS(rclcpp::KeepLast(10)).reliable().durability_volatile();
    }
    template <> [[maybe_unused]] std::string getTopicName<ds_interfaces::msg::ChangeState>() {
        return TOPIC_CHANGE_STATE;
    }

    template <> [[maybe_unused]] rclcpp::QoS getQoS<ds_interfaces::msg::MasterBroadcast>() {
        return rclcpp::QoS(rclcpp::KeepLast(10)).reliable().transient_local();
    }
    template <> [[maybe_unused]] std::string getTopicName<ds_interfaces::msg::MasterBroadcast>() {
        return TOPIC_MASTER_BROADCAST;
    }

    template <> [[maybe_unused]] rclcpp::QoS getQoS<ds_interfaces::msg::StringArray>() {
        return rclcpp::QoS(rclcpp::KeepLast(1)).best_effort().durability_volatile();
    }
    template <> [[maybe_unused]] std::string getTopicName<ds_interfaces::msg::StringArray>() {
        return TOPIC_SLAVES;
    }

    template <typename T>
    static rclcpp::Subscription<T>::SharedPtr
    newSubscription(rclcpp::Node* node, std::function<void(const typename T::SharedPtr)> callback) {
        if (node == nullptr) {
            throw std::runtime_error("Node pointer is null");
        }

        return node->create_subscription<T>(getTopicName<T>(), getQoS<T>(), callback);
    }
} // namespace ds_interfaces
