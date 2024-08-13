#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include <cmath>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"


//LF with PID

using namespace std::chrono_literals;

class LineFollowing : public rclcpp::Node
{
public:
  LineFollowing()
  : Node("line_follower")
  {
    this->declare_parameter<int>("lower_threshold",200);
    this->declare_parameter<int>("upper_threshold",250);
    this->declare_parameter<double>("Kp", 0.5);
    this->declare_parameter<double>("Ki", 0.5);
   

    _subscriber = this->create_subscription<sensor_msgs::msg::Image>(
      "/camera/image_raw", 10, std::bind(&LineFollowing::subCallback, this, std::placeholders::_1));

    _publisher = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    RCLCPP_INFO(this->get_logger(), "test");


    // _timer = this->create_wall_timer(
    //   100ms, std::bind(&LineFollowing::timerCallback, this));
    auto last_time = this->now();
  }

private:
  void subCallback(const sensor_msgs::msg::Image::SharedPtr camera_msg)
  {
    //get ros data
    
    //ros to opencv data
    transferData(camera_msg);
    //edge segmentation
    edgeSegmentation();
    //action robot
    robotAction();
    //visualization
    visualization();
 
  }



    void transferData(const sensor_msgs::msg::Image::SharedPtr camera_msg){

        cv_bridge::CvImagePtr cv_ptr;
        cv_ptr = cv_bridge::toCvCopy(camera_msg,"bgr8");

        cv::cvtColor(cv_ptr->image , gray_image,cv::COLOR_BGR2GRAY);
        lower_threshold = this->get_parameter("lower_threshold").as_int();
        upper_threshold = this->get_parameter("upper_threshold").as_int();


    }

    void edgeSegmentation(){

        cv::Canny(gray_image,cannyImage,lower_threshold,upper_threshold);

        int row = 150, column = 0;
        //boundaries dari pixel yang mau di proses
        roi = cannyImage(cv::Range(row, row + 240), cv::Range(column, column + 640));

        //piksel yang menunjukkan tepi/edge/objek disimpan dalam edge 
        for (int i = 0; i < 640; ++i) {
        if (roi.at<uchar>(160, i) == 255) {
            edge.push_back(i);
        }
        }

    }

    void robotAction(){
        
        
        double Kp = get_parameter("Kp").as_double();
        double Ki = get_parameter("Ki").as_double();

        auto current_time = this->now();
        double dt = (current_time-last_time).seconds();
        
        if (!edge.empty()) {
        int line = edge[1]-edge[0];
        int mid_line = edge[0] + line/2;
        int mid_robot = 640/2;


        //Calculate error and adjust robot's direction
        geometry_msgs::msg::Twist velocityMsg;
        double error = mid_robot - mid_line;
        integral += error * dt;

        double controller = Kp*error + Ki*integral;

        velocityMsg.linear.x = 0.1;


        if (error < 0.1) {
            velocityMsg.angular.z = -controller;
        } else {
            velocityMsg.angular.z = controller;
        }

        _publisher->publish(velocityMsg);
        last_time = current_time;
    }}

    void visualization(){
      
        cv::circle(roi,cv::Point(mid_line,160),2,cv::Scalar(255,255,255),-1);
        cv::circle(roi,cv::Point(mid_robot,160),5,cv::Scalar(255,255,255),-1);
        cv::imshow("Image", roi);
        cv::waitKey(1);
    }


  rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr _subscriber;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr _publisher;
  double _angularVel = 0.2;
  cv::Mat gray_image, cannyImage, roi;
  std::vector<int> edge;
  int lower_threshold, upper_threshold;
  int mid_line,mid_robot;
  rclcpp::Time last_time;
  double integral;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<LineFollowing>());
  rclcpp::shutdown();
  return 0;
}
