# Assignments for Module #4 : Robot Sensing
- Create all files in *module_4_assignment* package

### Assignment 1: Create proper Line Following Code Nodes

How i make the nodes :
1. Start with making files task 1.cpp
2. Then imclude the libraries for the node such as geometry msgs ,sensor msgs std msgs and rclcpp
3. make the class of LineFollowing
4. create the publisher using /cmd_vel topic and subscriber which is contain camera calback methods(topic /camera/image_raw) for generate the 4 logic methods inside.
5. in camera callback , transferData methods for convert the ros data into opencv data, edgeSegementation for processing segementation in opencv data , robotAction method for declare the logic linefollower , visualization for showing the segementation images.
6. Finally,make the ros2 int main() function to spin the node in order to run the nodes.



### Assignment 3: Wall Following Behaviour
- **Tasks**:
How i make the nodes :
1. Start with making files task 3.cpp
2. Then imclude the libraries for the node such as geometry msgs ,sensor msgs std msgs and rclcpp
3. make the class of LineFollowing
4. create the publisher using /cmd_vel topic and subscriber which is contain lidar calback methods(topic /scan) for generate the 3 logic methods inside.
5. in lidar callback , obstacleSens methods for grouping the ros lidar data into forward,right,and left, robotState for give the switch logic of the state , robotAction method for declare the action per logic.
6. Finally,make the ros2 int main() function to spin the node in order to run the nodes.

How i set up the ros2 package system:
1. create the folder of src and launch
2. create gazebo world square using editor and save the world file
3. create the files of nodes and launch (contains turlebot3 spawner,gazebo system,task3 nodes,maze world file) 
4. modify the CMakelist,txt using add_executable , ament_target_dependencies,install(TARGETS),install(DIRECTORY) = world,launch,urdf
5. colcon build to compile all of the files in the packages (inside the assignment_ws folder)
6. ros2 launch module_4_assignment test_3 to launch  the nodes (inside the assignment_ws folder)

### Assignment 4: Calculate Robot Speed
- **Tasks**:
Utilize Turltebo3 IMU sensor to calculate robot
    - Velocity
    - Acceleration

How i make the nodes :
1. Start with making files task 4.cpp
2. Then imclude the libraries for the node such as geometry msgs ,sensor msgs/msg/imu.hpp, std msgs and rclcpp
3. make the class of ImuSens
4. create the publisher using /cmd_vel topic and subscriber which is contain imu calback methods(topic /imu) for generate the 2 logic methods inside.
5. in imu callback , imuSens methods for get the ros imu data for angular velocities and linear acceleration, robotAction for give the command velocities .
6. Finally,make the ros2 int main() function to spin the node in order to run the nodes.

How i set up the ros2 package system:
1. create the folder of src and launch
3. create the files of nodes 
4. modify the CMakelist,txt using add_executable , ament_target_dependencies,install(TARGETS),install(DIRECTORY) = world,launch,urdf
5. colcon build to compile all of the files in the packages (inside the assignment_ws folder)
5. ros2 launch turtlebot3_gazebo empty_world.launch.py to launch  the gazebo nodes (inside the assignment_ws folder)
6. ros2 run module_4_assignment test_4 to launch  the nodes (inside the assignment_ws folder)


### Another Assignment: Fixing LF code


1. clone the robot_sensing_debug packages
2. modify the CMakelist.txt (path ,folder and name of file)
3. modify the launch files path and name
4. modify the line_following.world path then models ( dae,config,and sdf file path )

