#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "tf2/LinearMath/Matrix3x3.h"
#include "tf2/LinearMath/Quaternion.h"

using namespace std::chrono_literals;

enum class RobotState {
  ON
};

class GoalPlanner : public rclcpp::Node
{
public:
  GoalPlanner()
  : Node("goal_planner"),
    prev_ED(0.0), controller(0.0), integral(0.0)
  {
    this->declare_parameter<double>("goal_x", 0.0);
    this->declare_parameter<double>("goal_y", 0.0);
    
    this->declare_parameter<double>("Kp_dist", 2);
    this->declare_parameter<double>("Ki_dist", 0.0);
    this->declare_parameter<double>("Kd_dist", 0.0);
    
    this->declare_parameter<double>("Kp_angle", 0.5);
    this->set_parameter(rclcpp::Parameter("use_sim_time", true));

    _subscriber = this->create_subscription<nav_msgs::msg::Odometry>(
      "/odom", 10, std::bind(&GoalPlanner::odomCallback, this, std::placeholders::_1));
      
    _publisher = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
  }

private:
  void odomCallback(const nav_msgs::msg::Odometry::SharedPtr odom)
  {
    robotInit(odom);
    robotController();
    robotAction();
  }

  void robotInit(const nav_msgs::msg::Odometry::SharedPtr odom){
    _x = odom->pose.pose.position.x;
    _y = odom->pose.pose.position.y;

    int energy = robotEnergy();
    energy = std::max(0, energy);
    RCLCPP_INFO(this->get_logger(), "Battery = '%d' ", energy);

    theta = getYaw(odom->pose.pose.orientation);
    //RCLCPP_INFO(this->get_logger(), "Pose x: '%f' Pose y: '%f'", _x, _y);

    goal_x = get_parameter("goal_x").as_double();
    goal_y = get_parameter("goal_y").as_double();

    if (!initialized) {
      last_time = this->now();
      initialized = true;
    }
  }

  void robotController(){
    double Kp_dist = get_parameter("Kp_dist").as_double();
    double Ki_dist = get_parameter("Ki_dist").as_double();
    double Kd_dist = get_parameter("Kd_dist").as_double();
    double Kp_angle = get_parameter("Kp_angle").as_double();

    auto current_time = this->now();

    double ED = sqrt(pow((goal_x - _x), 2) + pow((goal_y - _y), 2));
    double A = atan2(goal_y - _y, goal_x - _x);
    A = atan2(sin(A), cos(A));
    double EA = A - theta;
    //RCLCPP_INFO(this->get_logger(), "ED: '%f' , EA: '%f' ", ED, EA);
            
    ED = std::max(0.0, std::min(ED, 0.5));
    EA = std::max(-1.0, std::min(EA, 1.0));
        
    double dt = (current_time - last_time).seconds();
    integral += ED * dt;
    double Derivative = (ED - prev_ED) / dt;

    //controller = Kp_dist * ED + Ki_dist * integral + Kd_dist * Derivative;
    controller = Kp_dist * ED + Ki_dist * integral;
    error_a = Kp_angle * EA;

    prev_ED = ED;
    last_time = current_time;
  }

  void robotAction(){
    geometry_msgs::msg::Twist cmd;

    // if (std::abs(controller) > _threshold_d || std::abs(error_a) > _threshold_a) {
    if (std::abs(controller) > _threshold_d){
      cmd.linear.x = controller;
      cmd.angular.z = error_a;
      RCLCPP_INFO(this->get_logger(), "velocities '%f' ", cmd.linear.x);
    } else {
      cmd.linear.x = 0.0;
      cmd.angular.z = 0.0;
      RCLCPP_INFO(this->get_logger(), "Reached goal");
    }

    _publisher->publish(cmd);
  }

  double getYaw(const geometry_msgs::msg::Quaternion &quat){
    tf2::Quaternion q(quat.x, quat.y, quat.z, quat.w);
    tf2::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);
    return yaw;
  }

  int robotEnergy(){
    switch (_state)
    {
      case RobotState::ON:
        return _energy -= 1;
    } 
    return _energy;
  }

  rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr _subscriber;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _publisher;
  RobotState _state;
  rclcpp::Time last_time;
  double _x, _y;
  double goal_x, goal_y, theta;
  double prev_ED, controller, error_a, integral;
  double _threshold_d = 0.1;
  double _threshold_a = 0.01;
  int _energy = 10000;
  bool initialized = false;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<GoalPlanner>());
  rclcpp::shutdown();
  return 0;
}
