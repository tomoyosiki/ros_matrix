#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv){
    ros::init(argc, argv, "timer");
    ros::NodeHandle n;

    ros::Publisher timer_pub = n.advertise<std_msgs::String>("timer", 1000);

    ros::Rate loop_rate(10);

    while(ros::ok()){
        std_msgs::String msg;

        std::stringstream ss;
        ss << "hello world ";
        msg.data = ss.str();

        timer_pub.publish(msg);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}