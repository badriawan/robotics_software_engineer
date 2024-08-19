# Assignments for Module #5 : Control Systems 

### Assignment 3 - Task 2: PID controller with battery health
-PID -Task2
<p align="center">
<img src = "doc/PIDcontrol.png?raw=true" center=true width="55%"/>
</p> -->

### Assignment 3 - Task 3b: Build a Mobile Robot with Ackerman Steering Drive
<p align="center">
<img src = "doc/manipulator.mp4?raw=true" center=true width="55%"/>
</p>

<!-- ### Assignment 3 - Task 1: Create a Custom Transform Tree
<p align="center">
<img src = "doc/task1_robotic_arm.gif?raw=true" center=true width="55%"/>
</p>
<!-- 
### Assignment 3 - Task 2: Add Joints and Visual Elements
<p align="center">
<img src = "doc/task2_robotic_arm.gif?raw=true" center=true width="55%"/>
</p>

### Assignment 3 - Task 3a: Build a Mobile Manipulator
<p align="center">
<img src = "doc/task3a_mobile_arm.gif?raw=true" center=true width="55%"/>
</p> -->




<details open>
<summary> <b>Brief Review<b></summary>

- First part of the assignment is creating PI controllers for controlling the linefollower mobile robot smoothly.

- The second assignment just create methods for battery energy health and PID controllers for linear motion.

- Next the third, create position controller for ros2_control in custom manipulator robot.

- Last assignment is implementation of LQR robots using different penalties value in Q and R matriks

### <b>Project Tree</b>
<p align="center">
<img src = "doc/tree.PNG?raw=true" center=true width="35%"/>
</p>

</details>

<details close>
<summary> <b>Assignments and Solutions<b></summary>



### Assignment 1: Line Following With PI controller
- **Tasks**:
Improve Camera based Line following from previous module.From previous module improve Line following using camera by introducing PI controller

- **Solutions**:
How i make the nodes :
1. Start with making files task 1.cpp
2. Then imclude the libraries for the node such as geometry msgs ,sensor msgs std msgs and rclcpp
3. make the class of LineFollowing
4. create the publisher using /cmd_vel topic and subscriber which is contain camera calback methods(topic /camera/image_raw) for generate the 4 logic methods inside.
5. in camera callback , transferData methods for convert the ros data into opencv data, edgeSegementation for processing segementation in opencv data , robotAction method for declare the logic linefollower , visualization for showing the segementation images.
6. Define dt using differences of time for each timestep
7. Declare the Kp and Ki parameters on the constructor and put the Kp and Ki variables to the controller variables and define the logical movement of the robot using controller.
8. Finally,make the ros2 int main() function to spin the node in order to run the nodes.

### Assignment 2: Energy-Efficient Go to Goal Node
- **Tasks**:
Write a ROS2 node that plans the TurtleBot3's path to a given goal while minimizing energy consumption based on time.
The path planning algorithm should consider both the distance to the goal and the robot's energy expenditure
    - Through Speed , acceleration, and distance traveled.

- **Solutions**:
How i make the nodes :
1. Start with making files task 2.cpp
2. Then imclude the libraries for the node such as geometry msgs ,nav msgs tf2 msgs and rclcpp
3. make the class of goal planner
4. create the publisher using /cmd_vel topic and subscriber which is contain odom calback methods(topic /odom) for generate the 3 logic methods inside.
5. in odom callback , robotInit methods for declare the parameters (of goal, PID , convert the odom data into position and yaw) , robotController for create controller using PID , robotAction method for declare the logic goal planner and execute the action.
6. Define dt using differences of time for each timestep
7. Declare the Kp and Ki parameters on the constructor and put the Kp and Ki variables to the controller variables and define the logical movement of the robot using controller.
8. Finally,make the ros2 int main() function to spin the node in order to run the nodes.

### Assignment 3: Position Controller for Manipulator using ros2_control
- **Solutions**:

How i make the controller :
1. Start with making files manipulator.urdf
2. Then include the DIRECTORY launch and urdf on CMAKELIST.txt 
3. Make the launch folder and urdf folder contains the manipulator file with ros2_control gazebo system and system plugin with controller YAML file.
4. Use the position for state interface and command interface on URDF and YAML file. Dont forget to input jointstate_trajectory contollers to 
5. Create the launch files to launch the gazebo system node, spawner node, state_publisher node, and 2 controlers manager node for 2 controllers.
6. launch the files and publish the message to move the position of the manipulator's links.


### Assignment 4: LQR Control Analysis 
- **Tasks**:
Modify the Q and R matrix pnalties value and analyze the robot's behaviour.

- **Solutions**:
How i make the nodes system :
1. Start with making files task 4.cpp
2. Then imclude the libraries for the node such as geometry msgs ,nav msgs tf2 msgs and rclcpp, EIGEN then also create the custom libraries.
3. The hpp files lqr_lib.hpp and lqr_node.hpp are the header files which are lqr_lib contains header for defining methods for matrix Q, matrix R,and K  , lqr_node contains header for defining the state, input and class variables.
4. The cpp files which are lqr_lib.cpp compute the LQR controller and lqr_node.cpp for the ros2 node that produce the processing sensor input data to action velocities using LQR controllers.
5. Modify the CMAKELIST.txt using proper name of libraries and executable files and dependencies.
6. Finally, compile and run the nodes.

<p align="center"> </p>
</details>

<details open>
<summary> <b>Using The Package <b></summary>

- Follow the next steps to replicate the outcome...

- Create the workspace
```sh
    cd ~
    mkdir -p assignments_ws/src
    cd assignments_ws/src
```
- Fork (or clone) this repo in the `~/assignments_ws/src` folder by typing:
```sh 
    git clone https://github.com/Robotisim/robotics_software_engineer.git
```
- Next compile and source the repository
```sh
    cd ~/assignments_ws
    colcon build --packages-select module_5_assignment
    source install/setup.bash
```

- Run the demos for Assignment 2, Part 1, 2,3,4
```sh
    ros2 launch module_5_assignment task:=task1
    ros2 launch module_5_assignment task:=task2
    open task3.txt
    open task4.txt
 
```

</details>


<details open>
<summary> <b>Issues<b></summary>

- 1. The only issues on task 1 which illustrates black box images without any of object and colours .The solution : kindly check the robot's camera size and tuned all of the paramters
</details>

<details open>
<summary> <b>Future Work<b></summary>

- 1. For task 1, Experiment to improve the performance by increasing over the linear speed and tuning the PID controllers.
- 2. For task 2, Experiment in reorganized PID controllers for smoother path and robot's stability as well.
- 3. For task 3, Implementation of velocity and position controllers inside the URDF.
- 4. For task 4, Re-code the LQR in my own version.
</details>

<details open>
<summary> <b>Contributing<b></summary>

Your contributions are always welcome! Please feel free to fork and modify the content but remember to finally do a pull request.

</details>

<details open>
<summary> :iphone: <b>Having Problems?<b></summary>

<p align = "center">

[<img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white" />](https://www.linkedin.com/in/yusufbadriawan)
[<img src="https://img.shields.io/badge/telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/>](https://t.me/yusufbadriawan)
[<img src="https://img.shields.io/badge/linkedin-%230077B5.svg?&style=for-the-badge&logo=linkedin&logoColor=white" />](https://www.linkedin.com/in/yusufbadriawan)
[<img src="https://img.shields.io/badge/gmail-%23D14836.svg?&style=for-the-badge&logo=gmail&logoColor=white" />](mailto:yusufbadriawan@gmail.com)

</p

</details>

<details open>
<summary> <b>License<b></summary>
<!-- <p align = "center">
<img src= "https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/by-sa.svg" />
</p> -->
</details>