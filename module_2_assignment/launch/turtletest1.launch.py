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
    Drive_turtle1=Node(
    package = 'module_2_assignment',
    executable = 'task_1',
    name = 'task_1',
    # namespace= 'drive_turtle1'
    )



    return LaunchDescription([
    Turtlesim,
    Drive_turtle1,

 ])