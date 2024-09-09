# Assignments for Module #2 : ROS2 2D Turlesim Simulation
- Create all files in *module_2_assignment* package


### Assignment 2 - Task 1: Custom Nodes and Launch Files
<p align="center">
<img src = "doc/turtle1.gif?raw=true" center=true width="55%"/>
</p> -->

### Assignment 2 - Task 2: Exploring Turtlesim Services and Parameters
<p align="center">
<img src = "doc/turtle2.gif?raw=true" center=true width="55%"/>
</p> -->

<details open>
<summary> <b>Brief Review<b></summary>

- First part of the assignment is creating nodes and launch files for turtlesim to move.

- The second assignment just create launch files for multi-robot application.



<summary> <b>Assignments and Solutions<b></summary>

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

- **Problem**:
In this case, the turtle robot must move in circular motion using ROS2 publisher implementation. The main problem is how to move a robot effectively using velocicities to produce circular motion with radius input.

- **Solutions**:
By breakdown this spesific problem using analysis thinking and proper mindset. There are four steps which i must completed first when i want to solve this problem.





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

- **Solutions**:
- How i make the second nodes :
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
    colcon build --packages-select module_2_assignment
    source install/setup.bash
```

- Run the demos for Assignment 2, Part 1, 2,3,4
```sh
    ros2 launch module_2_assignment turtletest1.launch.py
    ros2 launch module_2_assignment turtletest2.launch.py

   
 
```

</details>


<details open>
<summary> <b>Issues<b></summary>

- 1. There is no issues at all.
</details>

<details open>
<summary> <b>Future Work<b></summary>
- Create a multi-differential drive robot manuever.
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