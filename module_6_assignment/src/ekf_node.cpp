#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "visualization_msgs/msg/marker.hpp"
#include <Eigen/Dense>
//#include <random>
#include "ekf_lib.hpp"
#include <rclcpp/logger.hpp>
#include <rclcpp/logging.hpp>
#include <rclcpp/subscription.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <visualization_msgs/msg/marker_array.hpp>

typedef Eigen::Matrix<double, 2, 1> Vector2d;
typedef Eigen::Matrix<double, 4, 1> Vector4d;
typedef Eigen::Matrix<double, 4, 4> Matrix4d;
typedef Eigen::Matrix<double, 4, 5> Matrix45d;
typedef Eigen::Matrix<double, 5, 1> Vector5d;
typedef Eigen::Matrix<double, 5, 5> Matrix5d;
typedef Eigen::Matrix<double, 2, 5> Matrix25d;

using namespace std::chrono_literals;

class Tb3SensorFusion : public rclcpp::Node
{
public:
  Tb3SensorFusion() : Node("tb3_sensor_fusion")
  {
    setMatrices();

    _imu_subscriber = this->create_subscription<sensor_msgs::msg::Imu>(
      "/imu", 10, std::bind(&Tb3SensorFusion::imuCallback, this, std::placeholders::_1));
    
    _cmd_subscriber = this->create_subscription<geometry_msgs::msg::Twist>(
      "/cmd_vel", 10, std::bind(&Tb3SensorFusion::cmdCallback, this, std::placeholders::_1));

    _publisher = this->create_publisher<visualization_msgs::msg::Marker>("visualization_marker", 10);

    _timer = this->create_wall_timer(
      100ms, std::bind(&Tb3SensorFusion::timerCallback, this));
  }

private:
  void imuCallback(const sensor_msgs::msg::Imu::SharedPtr msg) {
        imu_msg = msg;
    }

  void cmdCallback(const geometry_msgs::msg::Twist::SharedPtr cmd){

    controller_x = cmd->linear.x;
    controller_y = cmd->linear.y;


  }

  void timerCallback(){

    double dt = 0.1;

    kf.prediction(controller_x,controller_y,dt);
    double filtered_x = kf.getStateX();
    double filtered_y = kf.getStateY();

    visualization_msgs::msg::Marker marker;
    marker.header.frame_id = "odom";
    marker.header.stamp = this->get_clock()->now();
    marker.ns = "tb3odom";
    marker.id = 0.0;
    marker.type = visualization_msgs::msg::Marker::SPHERE;
    marker.action = visualization_msgs::msg::Marker::ADD;
    marker.pose.position.x = filtered_x;
    marker.pose.position.y = filtered_y;
    marker.pose.position.z = 0.0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker.scale.x = 0.1;
    marker.scale.y = 0.1;
    marker.scale.z = 0.1;
    marker.color.r = 0.0;
    marker.color.g = 1.0;
    marker.color.b = 0.0;
    marker.color.a = 1.0;


    _publisher->publish(marker);
    
  }


  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr _odom_subscriber;
  rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr _cmd_subscriber;
  rclcpp::Publisher<visualization_msgs::msg::Marker>::SharedPtr _publisher;
  rclcpp::TimerBase::SharedPtr _timer;
  KalmanFilter kf;
  double controller_x;
  double controller_y;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<Tb3SensorFusion>());
  rclcpp::shutdown();
  return 0;
}
