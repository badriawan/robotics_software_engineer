# Assignments for Module #7 : Mapping 


### Assignment - Task 1: Create a 2D LIDAR-Based Map
<p align="center">
<img src = "doc/maze_map.png?raw=true" center=true width="55%"/>
</p> -->

### Assignment - Task 2: Understanding Inputs and Outputs for 2D and 3D Mapping 
<p align="center">
<img src = "doc/rtabmap.gif?raw=true" center=true width="55%"/>
</p> -->



<summary> <b>Brief Review<b></summary>

- The first assignment is to create a custom maze world in Gazebo and a map using slam_toolbox algorithms.

- The second assignment is understand the inputs and outputs for 2D and 3D Mapping

- The third assignment is explain the mapping algorithm.

<summary> <b>Assignments and Solutions<b></summary>


# **Assignment 1: Create a 2D LIDAR-Based Map**

This documentation outlines the steps to complete Assignment 1, which involves creating a 2D LIDAR-based map using a custom world maze in Gazebo and visualizing the map using the SLAM Toolbox in Rviz.

---

## **Tasks**
1. **Create a custom world maze in Gazebo**  
2. **Use the SLAM Toolbox to build and visualize the map in Rviz**

---

## **Solutions**

### **1. Creating the Custom World Maze**
#### Steps to Make the World:
1. **Launch Gazebo**  
   Open Gazebo to design the maze environment.
   
2. **Design the Maze**  
   - Create a custom maze using walls and obstacles.  
   - Save your maze by exporting it as a `.world` file.  

---

### **2. Building the Map**
#### Prerequisites:
- Install the required ROS 2 packages, including `slam_toolbox` and dependencies.
  
#### Steps to Build the Map:
1. **Set Up Your ROS 2 Workspace**  
   - Create directories for your workspace:  
     ```bash
     mkdir -p ~/ros2_ws/src/world
     mkdir -p ~/ros2_ws/src/map
     mkdir -p ~/ros2_ws/src/launch
     ```
   
2. **Modify the CMakeLists.txt and Package.xml**  
   - Update `CMakeLists.txt` to include the custom directories:
     ```cmake
     install(DIRECTORY world DESTINATION share/${PROJECT_NAME})
     install(DIRECTORY map DESTINATION share/${PROJECT_NAME})
     install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
     ```
   - Ensure dependencies like `slam_toolbox` are listed in `package.xml`.

3. **Create the Launch File**  
   - Write a launch file to integrate:
     - **TurtleBot3 in Gazebo** with the custom world file.  
     - **Rviz2** for visualization.  
   - Example:  
     ```python
     from launch import LaunchDescription
     from launch_ros.actions import Node

     def generate_launch_description():
         return LaunchDescription([
             Node(
                 package='gazebo_ros',
                 executable='spawn_entity.py',
                 arguments=['-entity', 'turtlebot3', '-file', 'path/to/your.world']
             ),
             Node(
                 package='rviz2',
                 executable='rviz2',
                 arguments=['-d', 'path/to/rviz/config.rviz']
             )
         ])
     ```

4. **Launch SLAM Toolbox**  
   - Use the **`online_async`** mode:
     ```bash
     ros2 launch slam_toolbox online_async.launch.py
     ```

5. **Control the Robot**  
   - Run the `teleop_twist_keyboard` node to move the robot:  
     ```bash
     ros2 run teleop_twist_keyboard teleop_twist_keyboard
     ```

6. **Configure Rviz2**  
   - Open Rviz2:  
     ```bash
     rviz2
     ```
   - Set the fixed frame to `map`.  
   - Add the `/map` topic to visualize the generated map.

7. **Generate and Save the Map**  
   - Move the robot around the maze to map the environment.  
   - Save the map using the `map_saver` node:  
     ```bash
     ros2 run nav2_map_server map_saver_cli -f ~/ros2_ws/src/map/my_map
     ```

---

### **3. Loading the Map**
#### Steps to Load the Map:
1. **Create a Launch File**  
   - Include:
     - `map_server` lifecycle node.  
     - `rviz2` configuration.  
   - Example:  
     ```python
     from launch import LaunchDescription
     from launch_ros.actions import Node

     def generate_launch_description():
         return LaunchDescription([
             Node(
                 package='nav2_map_server',
                 executable='map_server',
                 parameters=[{'yaml_filename': 'path/to/saved_map.yaml'}],
                 arguments=['--ros-args', '--params-file', 'path/to/params.yaml']
             ),
             Node(
                 package='rviz2',
                 executable='rviz2'
             )
         ])
     ```

2. **Set the Map Lifecycle**  
   - Activate the `map_server` lifecycle node:  
     ```bash
     ros2 lifecycle set /map_server configure
     ros2 lifecycle set /map_server activate
     ```

---

## **Conclusion**
By following these steps, you can successfully create a custom world maze, build a map using SLAM Toolbox, visualize it in Rviz, and load the saved map for reuse in ROS 2 projects. This pipeline ensures effective utilization of the 2D LIDAR-based mapping workflow.


# **Assignment 2: Understanding Inputs and Outputs for 2D and 3D Mapping**

This document provides a detailed explanation of inputs and outputs in the mapping process for both 2D and 3D systems, explores their workflows, and compares the two mapping techniques.

---

## **1. Role of Inputs and Outputs in the Mapping Process**

### **2D Mapping with SLAM Toolbox**
#### Inputs:
- **LIDAR Data (`/scan`)**:  
  - Laser scan data containing distance measurements from the robot to nearby obstacles.  
- **Odometry (`/odom`)**:  
  - Provides the robot's estimated position and velocity over time.  
- **Transforms (`/tf`)**:  
  - Defines spatial relationships between frames such as `base_link`, `odom`, and `map`.

#### Outputs:
- **Map (`/map`)**:  
  - A 2D grid-based occupancy map of the environment. Cells represent free space, obstacles, or unknown areas.  
- **Transforms (`map->odom`)**:  
  - Links the global map frame to the robot’s position for localization and navigation.  

---

### **3D Mapping with RTAB-Map**
#### Inputs:
- **RGB-D Camera Data (`/camera/depth` and `/camera/rgb`)**:  
  - Depth images provide distance measurements, while RGB images add color and texture information.  
- **IMU Data (`/imu`)**:  
  - Assists with motion estimation by capturing orientation, acceleration, and angular velocity.  
- **Odometry (`/odom`)**:  
  - Tracks the robot's movement for pose estimation.  
- **Transforms (`/tf`)**:  
  - Establishes the relationships between sensor frames and the robot's base frame.

#### Outputs:
- **3D Map (`/mapData`)**:  
  - A point cloud or voxel-based map that represents the environment in three dimensions.  
- **Graph Optimizations (`/graph`)**:  
  - Contains the optimized poses of the robot for trajectory visualization.  

---

## **2. Input Processing and Output Generation**

### **2D Mapping (SLAM Toolbox Workflow)**
1. **Input Processing**:  
   - Laser scan data is processed to detect obstacles and boundaries.  
   - Odometry data is fused to estimate the robot’s movement.  
   - Transform frames link the robot’s current position to the global map frame.

2. **Map Generation**:  
   - The algorithm creates a 2D occupancy grid where cells are marked as occupied, free, or unknown based on sensor readings.  
   - SLAM techniques (e.g., scan matching, pose graph optimization) are used to correct localization and minimize drift.

---

### **3D Mapping (RTAB-Map Workflow)**
1. **Input Processing**:  
   - Depth images are converted into 3D point clouds.  
   - IMU and odometry data assist in pose estimation and loop closure detection.  
   - RGB data overlays textures on the 3D map for enhanced detail.

2. **Map Generation**:  
   - The algorithm fuses depth and pose data to build a 3D point cloud map or a voxel grid map.  
   - Graph-based SLAM techniques optimize the trajectory by identifying loop closures and correcting localization errors.  

---

## **3. Comparison: 2D vs 3D Mapping**

| **Aspect**         | **2D Mapping (SLAM Toolbox)**          | **3D Mapping (RTAB-Map)**                 |
|---------------------|----------------------------------------|-------------------------------------------|
| **Complexity**      | Lower complexity; uses simpler algorithms and less computational power. | Higher complexity; requires more data processing and computational resources. |
| **Accuracy**        | Suitable for environments with flat terrains; limited vertical detail. | High accuracy with detailed representations, including vertical structures. |
| **Environment Suitability** | Best for indoor and flat spaces like offices, warehouses.         | Ideal for complex environments, including multi-level or outdoor areas.       |
| **Hardware**        | LIDAR sensor and odometry are sufficient.                          | Requires RGB-D cameras, IMU, and odometry.                                  |
| **Applications**    | Robot navigation in structured areas.                             | Robotics in outdoor, dynamic, or uneven terrains.                           |

---

## **Conclusion**
Understanding the roles of inputs and outputs in mapping processes is crucial for selecting the right tools and methods for specific environments. While 2D mapping is effective for simpler, flat terrains, 3D mapping provides a richer and more detailed representation of complex environments.


### **Brief Explanation of GMapping in ROS**

GMapping is a widely used SLAM (Simultaneous Localization and Mapping) algorithm for robots equipped with laser scanners. It enables a robot to map an unknown environment while simultaneously localizing itself within that map.

---

#### **Key Components of GMapping**

1. **Particle Filters (Monte Carlo Localization):**
   - GMapping uses a particle filter to estimate the robot's pose (position and orientation).
   - Each particle represents a potential pose.
   - **Steps:**
     - **Prediction:** The robot's motion model updates particles based on odometry.
     - **Correction:** Laser scan data adjusts particle weights based on how well each particle aligns with the environment.
     - **Resampling:** Particles with higher weights are kept, while others are replaced to converge on the most likely pose.

2. **Map Updating:**
   - The map is represented as an occupancy grid, where:
     - **Cells:** Marked as free, occupied, or unknown.
   - Laser scan data is used to:
     - Mark obstacles where laser beams hit.
     - Expand free space where no obstacles are detected.
   - Continuous updates refine the map as the robot moves.

3. **Handling Sensor Noise:**
   - GMapping addresses noise through probabilistic models:
     - **Laser Sensor Noise:** Accounts for errors in range measurements by incorporating a likelihood model in scan matching.
     - **Odometry Noise:** Models uncertainties in motion estimation (slippage, drift) using the motion model in particle filters.
   - Noise smoothing occurs through:
     - **Scan Matching:** Aligns incoming laser scans with the existing map.
     - **Particle Resampling:** Eliminates improbable pose estimates caused by noisy data.

4. **Loop Closure:**
   - Detects when the robot revisits a known location.
   - Adjusts the map to correct cumulative errors from odometry or sensor drift.

---

#### **Advantages**
- Robust in dynamic and static environments.
- Handles non-linearities and uncertainties effectively.

Here is a comparison table including **RTAB-Map**, **SLAM Toolbox**, and **Gmapping**:

| **Aspect**              | **RTAB-Map**                       | **SLAM Toolbox**                     | **Gmapping**                         |
|--------------------------|-------------------------------------|---------------------------------------|---------------------------------------|
| **Platform Focus**       | ROS1 & ROS2                        | ROS1 & ROS2                          | ROS1 (requires adaptation for ROS2)  |
| **Mapping Dimension**    | 2D & 3D                            | 2D                                   | 2D                                   |
| **Sensor Support**       | RGB-D Camera, LiDAR, IMU, Stereo   | LiDAR, Laser Scan, Odometry          | Laser Scan, Odometry                 |
| **Loop Closure**         | Very Good (visual-based)           | Good                                 | Limited                              |
| **Computational Demand** | High                               | Moderate                             | Low                                  |
| **Environment**          | Complex indoor & outdoor           | Large-scale indoor environments      | Small to medium-scale environments   |
| **Ease of Use**          | Complex                            | Moderate                             | Easy                                 |
| **Offline Mapping**      | Supported                          | Supported                            | Not supported                        |
| **Real-Time Performance**| Good (requires strong hardware)    | Good                                 | Basic                                |

---

### **When to Use Each Framework?**
- **Use RTAB-Map if:**
  - You need both 2D and 3D mapping capabilities.
  - Visual SLAM is required with RGB-D or stereo cameras.
  - The environment is complex, and high-accuracy mapping is critical.
  - You have powerful hardware capable of handling the computational load.

- **Use SLAM Toolbox if:**
  - You are using ROS2 and need a robust 2D mapping solution.
  - Persistent mapping, loop closure, or multi-session mapping is required.
  - The environment is large-scale but doesn’t require 3D mapping.

- **Use Gmapping if:**
  - You are working on a ROS1-based system with basic mapping needs.
  - The robot has limited computational resources.
  - You need a lightweight and easy-to-setup solution for small to medium-scale environments.




<details open>
<summary> <b>Issues<b></summary>

- Nothing
</details>



<details open>
<summary> <b>Future Work<b></summary>

- Integrate this project with autonomous navigation performance.
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