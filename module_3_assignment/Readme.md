
# Assignments for Module #3 : URDF and Robot Creation in ROS 2
- Objective 
This assignment focuses on understanding and applying the concepts of URDF (Unified Robot Description Format) to create custom robots in ROS 2. I will design and build a robotic arm with multiple degrees of freedom (DOF), integrate it with a mobile platform, and create an Ackerman drive system.

- Learning Outcome

By completing this assignment, I success:
    1.Learn to create custom robots for simulations using URDF.
    2.Understand how to define and manipulate joints and transforms in URDF.
    3.Gain experience in building and simulating mobile manipulators and drive systems in ROS 2.


### Assignment 3 - Task 1: Create Custom Mobile Manipulator with Ackerman Kinematics
<p align="center">
<img src = "doc/mobile_manipulator.gif?raw=true" center=true width="55%"/>
</p> -->


<details open>
<summary> <b>Brief Review<b></summary>

- First part of the assignment is creating custom manipulator in urdf file that contains links and joints with various type.

- The second assignment just create launch files in Gazebo and Rviz visualization.


<!-- ### <b>Project Tree</b>
<p align="center">
<img src = "doc/tree.PNG?raw=true" center=true width="35%"/>
</p>

</details>

<details close> -->
<summary> <b>Assignments and Solutions<b></summary>



### Assignment 1: Create Custom Mobile Manipulator with Ackerman Kinematics
- **Tasks**:
    Integrate the robotic arm with a mobile robot platform:
        Place the robotic arm on top of a differential drive robot.
        Connect the arm using the base_link of the differential drive robot.
    Create an Ackerman Drive System:
        Design a car-like robot structure that represents the front axle rotations for turning, simulating an Ackerman steering mechanism.


- **Solutions**:

How i make the urdf  :
1. Start with making files manipulator.urdf
2. Then put all of the links and joints type with parent,child,position and axis rotation
3. Firstly, without any visual,inertia, and collision
4. Then launch the rviz.launch.py
5. Define detail information about the visual inertia, and collision
6. Then launch the rviz.launch.py
7. Merge the manipulator with diff robot using ackerman model in diff_4.urdf
8. Then launch the rviz.launch.py
9. Finally, launch the gazebo.launch.py


How i set up the ros2 package system:
1. create the folder of urdf and launch
2. create the files of urdf and launch
3. in launch rviz files contains urdf model with additional library to import the files ,robot_state_publisher node, and joint_state_publisher_gui node then rviz2 node
4. in launch gazebo files contains urdf model with additional library to import the files ,robot_state_publisher node, and joint_state_publisher_gui node then gazebo execute process and spawn_entity node
4. modify the CMakelist,txt using install(DIRECTORY) launch and urdf
5. colcon build to compile all of the files in the packages (inside the assignment_ws folder)
6. ros2 launch module_3_assignment rviz.launch.py or gazebo-launch.py to launch all of the nodes (inside the assignment_ws/packages folder)
7. Set up all of the configuration on rviz2


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
    colcon build --packages-select module_3_assignment
    source install/setup.bash
```

- Run the demos for Assignment 2, Part 1, 2,3,4
```sh
    ros2 launch module_3_assignment rviz.launch.py
   
 
```

</details>


<details open>
<summary> <b>Issues<b></summary>

- 1. There is no issues at all.
</details>

<details open>
<summary> <b>Future Work<b></summary>
- Implement the controller to move the robot behaviour.
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