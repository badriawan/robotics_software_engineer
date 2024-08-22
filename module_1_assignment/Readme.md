# Assignments for Module #1 : OOP for Robotics in C++
- Create all files in *module_2_assignment* package


### Assignment 1 - Task 1: Robot Class Implementations
### Assignment 1 - Task 2: Simulating Sensor Readings
### Assignment 1 - Task 3: Sensor Library Design
<p align="center">
<img src = "doc/task1.png?raw=true" center=true width="55%"/>
</p> -->

<details open>
<summary> <b>Brief Review<b></summary>

- The assignment is just creating c++ code for controlling and define the function of robot using OOP concepts.




<summary> <b>Assignments and Solutions<b></summary>

### Assignment 1: Introduction to OOP Concepts in C++ for Robotics
- **Objective**: This assignment aims to introduce basic Object-Oriented Programming (OOP) concepts using C++ within a robotics context. You will develop a series of C++ programs that simulate robotic behavior, utilize sensor data, and demonstrate fundamental OOP principles.
- **Tasks**:
    - Define a Robot class with the following attributes
    - Methods for moving the robot:
    - Instantiate a Robot object and simulate actions by invoking its methods.
    - Use namespaces to define different robots. Ensure that each action is outputted to the console to demonstrate the robot's behavior.

Task 2: Simulating Sensor Readings
    - Create a C++ program that represents a robot equipped with temperature and distance sensors.
    - Print these values to the console with appropriate descriptions.
Task 3: Sensor Library Design
    - Design a simple sensor library that includes classes for different types of sensors:
    TemperatureSensor: Class for handling temperature readings.
    DistanceSensor: Class for handling distance measurements.
Use these classes in a main program to simulate getting readings from sensors.
- **Learning Outcome**: 
    Apply C++ syntax to simulate basic robotics concepts.
    Grasp fundamental OOP principles and understand their application in robotics software development.



 
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
    colcon build --packages-select module_1_assignment
    source install/setup.bash
```

- Run the demos for Assignment 1, Part 1, 2,3,4
```sh
    1. define cpp files , create drectories build
    2. create excutable and target link libr file on cmakelist
    3. cmake ..
    4. make to compile
    5. on build directories, ./files to run
 
```

</details>


<details open>
<summary> <b>Issues<b></summary>

- 1. There is no issues at all.
</details>

<details open>
<summary> <b>Future Work<b></summary>
- Nothing.
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





