from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    
    Turtlesim = Node(
    package = 'turtlesim',
    executable = 'turtlesim_node',
    name = 'turtlesim1',
    # namespace= 'turtle1'
    )

    # spawn_turtle2 = ExecuteProcess(
    #     cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 5.0, y: 5.0, theta: 1.57, name: 'turtle2'}\""],
    #     name = 'spawn_turtle2',
    #     shell = True
    # )
    
    # spawn_turtle3 = ExecuteProcess(
    #     cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 6.0, y: 6.0, theta: 1.57, name: 'turtle3'}\""],
    #     name = 'spawn_turtle3',
    #     shell = True
    # )

    # spawn_turtle4 = ExecuteProcess(
    #     cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 8.0, y: 8.0, theta: 1.57, name: 'turtle4'}\""],
    #     name = 'spawn_turtle4',
    #     shell = True
    # )

    # spawn_turtle5 = ExecuteProcess(
    #     cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 2.0, y: 2.0, theta: 1.57, name: 'turtle5'}\""],
    #     name = 'spawn_turtle5',
    #     shell = True
    # )
    Drive_turtle1=Node(
    package = 'module_2_assignment',
    executable = 'task_1',
    name = 'task_1',
    # namespace= 'drive_turtle1'
    )
   
    
    # Drive_turtle2=Node(
    # package = 'ros_fundamental',
    # executable = 'drive_turtle',
    # name = 'drive_turtle2',
    # #namespace= 'drive_turtle2'
    # parameters= [

    #     {'cmd_vel_topic':'/turtle2/cmd_vel'}

    # ]
    # )

    # Drive_turtle3=Node(
    # package = 'ros_fundamental',
    # executable = 'drive_turtle',
    # name = 'drive_turtle3',
    # #namespace= 'drive_turtle2'
    # parameters= [

    #     {'cmd_vel_topic':'/turtle3/cmd_vel'}

    # ]
    #  )


    return LaunchDescription([
    Turtlesim,
    Drive_turtle1,
    # Drive_turtle2,
    # Drive_turtle3,
    # spawn_turtle2,
    # spawn_turtle3,
    # spawn_turtle4,
    # spawn_turtle5, 

 ])