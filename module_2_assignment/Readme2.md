How i make the second nodes :
1. Start with making files task 2.cpp
2. Then imclude the libraries for the node such as geometry msgs , std msgs and rclcpp
3. make the class of DriveTurtle
4. create the publisher using parameters cmd_vel_topic with default value turtle1/cmd_vel topic and timer which is contain timer_callback methods for generate the logic
5. in timer_callback , i created the message variable that contains Twist() method to generate linear and angular velocity
6. Next, i define the logic for the robot move forward and backward using conditional sentence
7. it must publish the message in every timer range inside the timer_callback with steps in every 2 seconds
8. In line with the moving robot, it will inform the linear velocity on the linux terminal
7. Finally,make the ros2 int main() function to spin the node in order to run the nodes.

How i set up the ros2 package system:
1. create the folder of src and launch
2. create the files of nodes and launch
3. in launch files contains turlesim node , spawn each turtle using srv, and the drive node for each with coordinates
4. modify the CMakelist,txt using add_executable , ament_target_dependencies,install(TARGETS),install(DIRECTORY)
5. colcon build to compile all of the files in the packages (inside the assignment_ws folder)
6. ros2 launch module_2_assignment turtletest2.launch.py to launch all of the nodes (inside the assignment_ws/packages folder)