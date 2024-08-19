# Assignments for Module #4 : Robot Sensing
- Create all files in *module_4_assignment* package


### Assignment 4 - Task 1: Create Proper Line Following Code Nodes
<p align="center">
<img src = "doc/LF.png?raw=true" center=true width="55%"/>
</p> -->

### Depth Sensor - Visualization
<p align="center">
<img src = "doc/Depth.png?raw=true" center=true width="55%"/>
</p> -->

### Assignment 4 - Task 2: Create a Software Structure for Maze Solving Robot
<p align="center">
<img src = "doc/task2.png?raw=true" center=true width="55%"/>
</p> -->

### Assignment 4 - Task 3: Wall Following Behaviour
<p align="center">
<img src = "doc/mazesquare.gif?raw=true" center=true width="55%"/>
</p>

### Assignment 4 - Task 4: Calculate Robot Speed
<p align="center">
<img src = "doc/IMU.gif?raw=true" center=true width="55%"/>
</p>




<details open>
<summary> <b>Brief Review<b></summary>

- First part of the assignment is creating Line Follower using camera sensor and make the nodes readable.

- The second assignment just create methods for battery energy health and PID controllers for linear motion.

- Next the third, create wall following robot with custom square world in gazebo system using lidar scan sensor.

- Last assignment is get the IMU sensor data for acceleration and velocities

<!-- ### <b>Project Tree</b>
<p align="center">
<img src = "doc/tree.PNG?raw=true" center=true width="35%"/>
</p>

</details>

<details close> -->
<summary> <b>Assignments and Solutions<b></summary>



### Assignment 1: Create proper Line Following Code Nodes
- **Tasks**:
Create a LineFollowing robot using readable simple code. 

- **Solutions**:
How i make the nodes :
1. Start with making files task 1.cpp
2. Then imclude the libraries for the node such as geometry msgs ,sensor msgs std msgs and rclcpp
3. make the class of LineFollowing
4. create the publisher using /cmd_vel topic and subscriber which is contain camera calback methods(topic /camera/image_raw) for generate the 4 logic methods inside.
5. in camera callback , transferData methods for convert the ros data into opencv data, edgeSegementation for processing segementation in opencv data , robotAction method for declare the logic linefollower , visualization for showing the segementation images.
6. Finally,make the ros2 int main() function to spin the node in order to run the nodes.




### Assignment 3: Wall Following Behaviour
- **Tasks**:
Create a mobile robot following wall behaviour in square arena.

- **Solutions**:
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

- **Solutions**:
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




### Assignment 5: Robot Sensing Debug: Fixing LF code

- **Solutions**:
    1.clone the robot_sensing_debug packages
    2.modify the CMakelist.txt (path ,folder and name of file)
    3.modify the launch files path and name
    4.modify the line_following.world path then models ( dae,config,and sdf file path )






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
    colcon build --packages-select module_4_assignment
    source install/setup.bash
```

- Run the demos for Assignment 2, Part 1, 2,3,4
```sh
    ros2 launch module_4_assignment task_1
    ros2 launch module_4_assignment task_3
    ros2 launch module_4_assignment task_4

   
 
```

</details>


<details open>
<summary> <b>Issues<b></summary>

- 1. There is no issues at all.
</details>

<details open>
<summary> <b>Future Work<b></summary>
- Implement all of the sensor data in the mobile robot to move the robot eficiently.
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