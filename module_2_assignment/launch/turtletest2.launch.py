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

    spawn_turtle2 = ExecuteProcess(
        cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 5.0, y: 5.0, theta: 1.57, name: 'turtle2'}\""],
        name = 'spawn_turtle2',
        shell = True
    )
    
    spawn_turtle3 = ExecuteProcess(
        cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 6.0, y: 6.0, theta: 1.57, name: 'turtle3'}\""],
        name = 'spawn_turtle3',
        shell = True
    )

    spawn_turtle4 = ExecuteProcess(
        cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 8.0, y: 8.0, theta: 1.57, name: 'turtle4'}\""],
        name = 'spawn_turtle4',
        shell = True
    )

    spawn_turtle5 = ExecuteProcess(
        cmd=['ros2', 'service', 'call', '/spawn', 'turtlesim/srv/Spawn', "\"{x: 2.0, y: 2.0, theta: 1.57, name: 'turtle5'}\""],
        name = 'spawn_turtle5',
        shell = True
    )
    task_21=Node(
    package = 'module_2_assignment',
    executable = 'task_2',
    name = 'task_2 1',
    # namespace= 'task_21'
    )
   
    
    task_22=Node(
    package = 'module_2_assignment',
    executable = 'task_2',
    name = 'task_2 2',
    #namespace= 'task_22'
    parameters= [

        {'cmd_vel_topic':'/turtle2/cmd_vel'}

    ]
    )

    task_23=Node(
    package = 'module_2_assignment',
    executable = 'task_2',
    name = 'task_2 3',
    #namespace= 'task_22'
    parameters= [

        {'cmd_vel_topic':'/turtle3/cmd_vel'}

    ]
    )


    return LaunchDescription([
    Turtlesim,
    task_21,
    task_22,
    task_23,
    spawn_turtle2,
    spawn_turtle3,
    spawn_turtle4,
    spawn_turtle5, 

 ])