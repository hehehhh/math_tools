#include <ros/ros.h>
#include <iostream>
#include <math_tools/bspine.h>

int main(int argc, char  *argv[])
{   
    setlocale(LC_ALL,"");
    setlocale(LC_CTYPE,"zh_CN.utf8");

    ros::init(argc,argv,"math_test");
    ros::NodeHandle nh;

    tybspline bspine;
    // bspine.init();
    return 0;
}