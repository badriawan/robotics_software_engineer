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