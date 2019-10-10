#include <ros/ros.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <geometry_msgs/Twist.h>
#include <iostream>
    
    float offset = 5.5f;

struct teleport_options{
    float box_size;
    turtlesim::TeleportAbsolute srv;
    ros::ServiceClient teleport_client;
  };


void square(teleport_options c){
 c.srv.request.x = 11;
  c.srv.request.y = 11;
  c.teleport_client.call(c.srv);
  }

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "communication");
    float box_size = ros::param::param("~box_size", 9.0);
    ros::NodeHandle ny;

    ros::service::waitForService("/turtle1/teleport_absolute", -1);

    ros::ServiceClient teleport_client = ny.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute"); 
    ros::ServiceClient pen_client = ny.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
    turtlesim::SetPen pen_srv;
    pen_srv.request.off = true;
    pen_client.call(pen_srv);

    turtlesim::TeleportAbsolute srv;

    teleport_options options;
    options.box_size = box_size;
    options.teleport_client = teleport_client;
    options.srv = srv;


    square(options); 

    return 0;
}