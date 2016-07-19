#include <iostream>
#include <string>
#include <sstream>
#include <ros/ros.h>
#include "std_msgs/Int32.h"

using namespace std;

int main(int argc, char** argv){
	// ROS INITIALIZATION: announce node to ROS
	ros::init(argc, argv, "compassInput");
	ros::start();
	ros::NodeHandle n;
	ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("data", 1000);
	ros::Rate loop_rate(10);
	std_msgs::Int32 num;
	int angle = 0;
	while(ros::ok())
	{
		ROS_INFO_STREAM("Please enter an angle to test the compass:");
		cin >> angle;
		angle = -angle;
		num.data = angle;
		chatter_pub.publish(num);
		cout << "You entered: " << -num.data << endl;
	}
	ros::spin();
	ros::shutdown();
	return 0;
}
