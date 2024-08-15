cmake_minimum_required(VERSION 3.5)
project(module_5_assignment)

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





# add_executable(talker src/publisher.cpp)
# ament_target_dependencies(talker rclcpp std_msgs)

# add_executable(listener src/subscriber.cpp)
# ament_target_dependencies(listener rclcpp std_msgs)

# add_executable(drive_turtle src/drive_turtle.cpp)
# ament_target_dependencies(drive_turtle rclcpp std_msgs geometry_msgs)


add_executable(task_1 src/task1.cpp)
ament_target_dependencies(task_1 rclcpp std_msgs geometry_msgs nav_msgs tf2_ros cv_bridge)
target_link_libraries(task_1 ${OpenCV_LIBS})

add_executable(task_2 src/task2.cpp)
ament_target_dependencies(task_2 rclcpp std_msgs geometry_msgs nav_msgs tf2_ros)
target_link_libraries(task_2 ${OpenCV_LIBS})


install(TARGETS
  task_1
  task_2
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  urdf
  DESTINATION share/${PROJECT_NAME})

ament_package()
