# Assignments for Module #2 : ROS2 2D Turlesim Simulation
- Create all files in *module_2_assignment* package

### Assignment 1: Custom Nodes and Launch Files
- **Objective**: Develop ability to write custom ROS2 nodes and use launch files for running multiple nodes.
- **Tasks**:
Create a custom ROS2 node that makes the
- Turtlesim follow a unique pattern
    - Move in user input radius of circle
    - Move the turtle in logrithmic spiral
Develop a launch file to run the Turtlesim simulation and the custom node simultaneously.
Document the node and launch file creation process, including code and execution results.
- **Learning Outcome**: Understand the development and execution of custom nodes and the utility of launch files in ROS2.

How i make the nodes :
1. Start with making files task 1.cpp
2. Then imclude the libraries for the node such as geometry msgs , std msgs and rclcpp
3. make the class of DriveTurtle
4. create the publisher using turtle1/cmd_vel topic and timer which is contain timer_callback methods for generate the logic
5. in timer_callback , i created the message variable that contains Twist() method to generate linear and angular velocity
6. Next, i define the logic for instance we put random value in radius r to make the robot move in circular
7. it must publish the message in every timer range inside the timer_callback
8. In line with the moving robot, it will inform the linear velocity on the linux terminal
7. Finally,make the ros2 int main() function to spin the node in order to run the nodes.

How i set up the ros2 package system:
1. create the folder of src and launch
2. create the files of nodes and launch
3. in launch files contains turlesim node and the drive node
4. modify the CMakelist,txt using add_executable , ament_target_dependencies,install(TARGETS),install(DIRECTORY)
5. colcon build to compile all of the files in the packages (inside the assignment_ws folder)
6. ros2 launch module_2_assignment turtletest1.launch.py to launch all of the nodes (inside the assignment_ws/packages folder)
 


### Assignment 2: Exploring Turtlesim Services and Parameters
- **Objective**: Concepts of services and parameters in ROS2 using the Turtlesim simulation.
- **Tasks**:
Use existing Turtlesim services (e.g., spawn, clear) to modify the simulation environment.
    - Spawn 5 Turtlebots with 1 single launch file in Diagonal from top to bottom.
    - Drive middle 3 turtles back and forth continuosly
Modify the behavior of the Turtlesims using ROS2 parameters
    - change the speed of the turtles
- **Learning Outcome**: Learn how to interact with ROS2 services and parameters to alter node behavior and simulation environments.

### Document :
- Create another readme file to guide on how to run your package