#include <memory>
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <algorithm>

using std::placeholders::_1;


class ImuSens : public rclcpp::Node {
public:
  ImuSens() : Node("imu_sensor") {
    _publisher = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    _subscription = this->create_subscription<sensor_msgs::msg::Imu>(
      "/imu", 10, std::bind(&ImuSens::imuCallback, this, _1));
  }

private:
  void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
    imuSens(msg);
    robotAction();
  }

  void imuSens(const sensor_msgs::msg::Imu::SharedPtr msg) {
    

    msg->header.stamp = this->get_clock()->now();
    msg->header.frame_id =  "imu";

    _angular_vel = msg->angular_velocity.z;
    _linear_acc = msg->linear_acceleration.x;

    RCLCPP_INFO(this->get_logger(), " angular_vel = '%f' and acceleration = '%f' ", _angular_vel, _linear_acc);

  }

 
    
  void robotAction(){


    geometry_msgs::msg::Twist cmd;
    cmd.linear.x = 0.5;
    cmd.angular.z = 0.2;
    

    _publisher->publish(cmd);




  }
    

  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr _subscription;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _publisher;
  double _angular_vel;
  double _linear_acc;

};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ImuSens>());
  rclcpp::shutdown();
  return 0;
}
