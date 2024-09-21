# Assignments for Module #6 : Sensor Fusion 


### Assignment - Task 1: Sensor Fusion using EKF for GPS and IMU Data 
<p align="center">
<img src = "doc/navsat.gif?raw=true" center=true width="55%"/>
</p> -->



details open>
<summary> <b>Brief Review<b></summary>

- The first assignment is to utilize the Extended Kalman Filter for Turtlebot 3 robot by fuse the IMU sensor data and GPS data only.

- The second assignment just modify the value of Q and R covariance to analyze the behaviour of the mobile robot localization performance.


<summary> <b>Assignments and Solutions<b></summary>



### Assignment 1: EKF for Turtlebot 3 
- **Tasks**:
Make a sensor fusion from GPS and IMU data using EKF to perform robot localization and show the result of filtered data on rviz2.

- **Solutions**:
To use the GPS sensor data implementation , we have to apply navsat transform from robot localization packages to transfrom the latitude and longitude position data from GPS to euclidean value in x and y positions.

How i make the nodes :
1. Start with installing ROS 2 robot localization packages.
2. Established the directories of config
3. Create the YAML file and copy paste the dualEKF YAML configuration from the robot localization packages
4. Turn of the Odometry/wheel sensor data by change the input matriks value from true to false.
5. Generate the launch files that contains 3 robot_localization packages(EKF and Navsat) with YAML configuration files.
6. Launch all of the nodes with turtlebot3 gazebo and rviz2. Choose the topics Odom instead of base_link and Odometry/global topics to see the localization result.

### Assignment 2: Q and R Covariance
- **Tasks**:
Make some analysis based on impact of difference value of Q and R to robot's behaviour.

- **Solutions**:
1. Implementation of higher value of Q and higher value of R compared to the default value from the navsat packages.
2. Implementation of lower value of Q and lower value of R compared to the default value from the navsat packages.



<details open>
<summary> <b>Project Summary<b></summary>

In the Extended Kalman Filter (EKF), the matrices Q and R are fundamental in determining the filter's performance and accuracy. The matrix Q represents the process noise covariance, capturing the uncertainties and inaccuracies in the system's dynamic model. The matrix R denotes the measurement noise covariance, reflecting the uncertainties associated with the sensor measurements. 
(Anyway , we can tuning this on fusion.yaml file)

When the system model is not perfectly known or there are external disturbances affecting the system, these uncertainties are incorporated into the filter through the matrix Q. A larger Q implies that more uncertainty is assumed in the model predictions, causing the filter to rely more heavily on the incoming measurements during the update step.

On the other hand, the matrix R models the noise present in the sensor data. If the sensors are known to be noisy or less reliable, the values in R are increased to represent this higher uncertainty. A larger R leads the filter to place less trust in the measurements, making it depend more on the model predictions.

The relationship between Q and R directly influences how the EKF balances the prediction and correction phases:

- High Q, Low R: The filter assumes that the model is highly uncertain and that the measurements are reliable. As a result, it adjusts the state estimates rapidly in response to new measurements, which may introduce more noise into the estimates if the measurements are actually noisy.

- Low Q, High R: The filter considers the model to be accurate and the measurements to be noisy. It relies more on the model predictions, leading to smoother state estimates that may lag behind rapid changes in the actual state.

Proper tuning of Q and R is crucial for optimal filter performance. If Q and R are not set appropriately, the filter may either respond too slowly to changes (if it trusts the model too much) or become too reactive to measurement noise (if it trusts the measurements too much). The values of Q and R are often determined based on knowledge of the system dynamics and the characteristics of the sensors, sometimes requiring empirical adjustment to achieve the desired filtering performance.

By carefully adjusting Q and R, the EKF can be made to provide accurate and reliable state estimates, effectively balancing the uncertainties in the model and the measurements to reflect the true state of the system as closely as possible.
</details>



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
    colcon build --packages-select module_6_assignment
    source install/setup.bash
```

- Run the demos for Projects, Part 1, 2,3,4
```sh
    ros2 launch module_6_assignment fusion.launch.py
    ros2 launch turtlebot3_gazebo empty_world.launch.py
    rviz2
    ros2 run teleop_twist_keyboard teleop_twist_keyboard
 
```

</details>


<details open>
<summary> <b>Issues<b></summary>

- Nothing
</details>



<details open>
<summary> <b>Future Work<b></summary>

- 1. Implementation camera sensor data,LiDAR, or any relevant distance sensor and fusion this together with EKF.
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