# math_tools
## 运行环境
<p align="center">
    <img width="100px" height="20px" src="https://img.shields.io/badge/Ubuntu-20.04-orange?logo=Ubuntu&Ubuntu-20.04"
        alt="ubuntu" />
    <img width="100px" height="20px" src="https://img.shields.io/badge/ROS-noetic-blue?logo=ROS&ROS=noetic" alt="ROS" />
</p>

a ros package for B-spline curve and dubins curve
# Quick Start

1. 创建ros工作空间
```shell
mkdir ros_ws/src
cd ros_ws/src
git clone https://github.com/hehehhh/dwa_tra-local-planner.git
cd ..
catkin_make
```
2.引入该头文件
```cpp
#include<math_tools/bspine.h>
#include<math_tools/dubins.h>
```
