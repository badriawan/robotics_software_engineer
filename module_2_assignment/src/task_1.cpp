#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

class DriveTurtle : public rclcpp::Node
{
  public:
    DriveTurtle()
    : Node("drive_turtle"), count_(0)
    {
    //   this->declare_parameter<std::string>("cmd_vel_topic","/turtle1/cmd_vel");
    //   std::string cmd_vel_topic = this->get_parameter("cmd_vel_topic").as_string();

      publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
      timer_ = this->create_wall_timer(
      2000ms, std::bind(&DriveTurtle::timer_callback, this));
    }

  private:
    void timer_callback()
    {
    auto message = geometry_msgs::msg::Twist();
    //   if (forward_){
    //     message.linear.x = 0.5;
    //   }
    //   else{
    //     message.linear.x = -0.5;
    //   }

    //   forward_ = !forward_;
    //   message.angular.z = 0.5;
      message.linear.x = 0.5;
      float r = 2; //radius
      message.angular.z = message.linear.x/r;
      RCLCPP_INFO(this->get_logger(), "Radius: '%lf'", r);
      RCLCPP_INFO(this->get_logger(), "Speed: '%f'", message.linear.x);

      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    size_t count_;
    // bool forward_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<DriveTurtle>());
  rclcpp::shutdown();
  return 0;
}