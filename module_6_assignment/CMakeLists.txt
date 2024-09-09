cmake_minimum_required(VERSION 3.5)
project(module_6_assignment)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
find_package(visualization_msgs REQUIRED)
find_package(Eigen3 REQUIRED)



# find_package(PCL REQUIRED)
# find_package(pcl_conversions REQUIRED)
# include_directories(${PCL_INCLUDE_DIRS})
# link_directories(${PCL_LIBRARY_DIRS})
# add_definitions(${PCL_DEFINITIONS})



add_library(ekf_lib src/ekf_lib.cpp)
target_include_directories(ekf_lib PRIVATE ${EIGEN3_INCLUDE_DIR} include)
target_link_libraries(ekf_lib Eigen3::Eigen)

add_executable(ekf_node src/ekf_node.cpp)
target_include_directories(ekf_node PRIVATE include)
target_link_libraries(ekf_node ekf_lib)
ament_target_dependencies(ekf_node rclcpp sensor_msgs visualization_msgs)


install(TARGETS
 ekf_node
  DESTINATION lib/${PROJECT_NAME})
  
install(DIRECTORY
  launch
  config
  DESTINATION share/${PROJECT_NAME})

ament_package()