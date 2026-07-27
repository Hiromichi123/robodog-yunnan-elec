#include <rclcpp/rclcpp.hpp>
#include "layer4_system/dog_system.hpp"

/**
 * @brief 机器狗控制节点入口
 */
int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    DogSystem system;
    system.run();
    rclcpp::shutdown();
    return 0;
}
