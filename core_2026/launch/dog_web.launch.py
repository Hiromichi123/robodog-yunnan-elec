"""网页驱动模式起 dog_node：等 /dog/mission 上的任务，按 JSON 一步步执行。

    ros2 launch core_2026 dog_web.launch.py

**为什么 dog_node 不在 slam_only.launch.py 里**：那套是"链路"（雷达/SLAM/桥/网页入口），
而起 dog_node 会让狗在预检通过后站起来 —— 这必须是**一次明确的手动动作**，不能跟着链路
一起被拉起来。这个 launch 就是那个手动动作，只是把参数固定成网页模式。

两个参数的含义（**别随手改**）：
  wait_for_mission:=true        起来后不跑固定流程，等网页下发任务；预检（自检/起立）
                                变成任务里的步骤，操作员在网页上看得见、可编排。
  confirm_transitions:=false    关掉**终端**回车闸门 —— 不是拆掉闸门，是**换成网页闸门**：
                                任务 JSON 的 confirm 字段（默认 "each"）会让狗在每个危险
                                步骤前停下，等网页点「继续/放弃」。不关的话，launch 拉起时
                                stdin 不是终端，wait_for_enter 会按安全策略直接中止。

想回到"固定流程 + 终端回车确认"，直接 ros2 run（不带这些参数）即可，行为一字未变：
    ~/rosrun.sh 'ros2 run core_2026 dog_node --ros-args -p forward_duration_s:=0.0'

⚠️ 这里用 `arguments=[...]` 传 `-p`，**不要改成 `parameters=[{...}]`**：
launch_ros 的 `parameters=` 会生成一份**按节点名索引**的参数文件（这里是 `dog_node`），
而实际声明这些参数的是同进程里的 `robot_dog_hal_node` / `dog_mission_node` —— 名字对不上，
参数会**静默不生效**（最危险的是 confirm_transitions 没传进去，闸门还开着）。
命令行 `-p` 是本板验证过的路子（手动 `ros2 run ... -p forward_duration_s:=0.0` 一直这么用）。
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    dog_node = Node(
        package='core_2026',
        executable='dog_node',
        name='dog_node',
        output='screen',
        emulate_tty=True,
        arguments=[
            '--ros-args',
            # 网页驱动：起来后等 /dog/mission，不跑固定流程
            '-p', 'wait_for_mission:=true',
            # 终端闸门关掉（换成网页闸门，理由见文件头）
            '-p', 'confirm_transitions:=false',
        ],
    )

    return LaunchDescription([dog_node])
