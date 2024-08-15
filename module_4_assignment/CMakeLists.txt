cmake_minimum_required(VERSION 3.8)
project(module_4_assignment)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(task_1 src/task1.cpp)
ament_target_dependencies(task_1 rclcpp sensor_msgs geometry_msgs cv_bridge)
target_link_libraries(task_1 ${OpenCV_LIBS})

add_executable(task_3 src/task3.cpp)
ament_target_dependencies(task_3 rclcpp sensor_msgs)

add_executable(task_4 src/task4.cpp)
ament_target_dependencies(task_4 rclcpp sensor_msgs geometry_msgs)


install(TARGETS
 task_1
 task_3
 task_4
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  world
  DESTINATION share/${PROJECT_NAME})


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
