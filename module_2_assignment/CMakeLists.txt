cmake_minimum_required(VERSION 3.5)
project(module_2_assignment)

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

add_executable(task_1 src/task_1.cpp)
ament_target_dependencies(task_1 rclcpp std_msgs geometry_msgs)

add_executable(task_2 src/task_2.cpp)
ament_target_dependencies(task_2 rclcpp std_msgs geometry_msgs)


install(TARGETS
  task_1
  task_2
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME})

ament_package()