#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/TeleportRelative.h"
#include "turtlesim/SetPen.h"
#include <turtlesim/Pose.h>
#include <cmath>
/*
bool wall = false;

void wallHit(const turtlesim::Pose::ConstPtr& message){
    std::cout << message->x << "fdsf" << std::endl;
    if (message->x <= 0.0 || message->x >= 11.0 || message->y <= 0.0 || message->y >= 11.0){
        wall = true;
    } else {
        wall = false;
    }
}
*/


int main(int argc, char *argv[]) {
  ros::init(argc, argv, "lecture5");

  ros::NodeHandle nh;
  ros::Publisher cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
 /*   ros::Subscriber pose_subscriber = nh.subscribe("/turtle1/pose", 100, &wallHit);*/

  geometry_msgs::Twist msg;
int size = 10 ;
 int movement[size];
 int movement_execution[size];

  int shape;
  int numberOfMoves;
  float time = 0.5;
  int i = 0;
  char command_contine;

char c; 


/*
         std::cout << "Enter the number of times the turtle should move forward" << std::endl;
     
        std::cin >> numberOfMoves;
*/


for(int i = 0; i < size; i++){
    std::cout << "command " << std::endl;
    std::cin >> movement[i];
    std::cout << "number of movements " << std::endl;
    std::cin >> movement_execution[i];

    std::cout << "Do you want to enter another command y/n?";
    std::cin >> command_contine;
    if (command_contine != 'y'){
        break;
    }
}

  while(ros::ok() && movement[i] != 0)
  {

    ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportRelative>("/turtle1/teleport_relative");
    ros::Duration(0.5).sleep();
    turtlesim::TeleportRelative srv;



    if (movement[i] == 1){
        for (int j = movement_execution[i]; j > 0; j--){
                srv.request.linear = 1.0;
                client.call(srv);
                ros::Duration(time).sleep();
        }}
    else if (movement[i] == -1)
    {
         for (int j = movement_execution[i]; j > 0; j--){
      srv.request.linear = -1.0;
                client.call(srv);
                ros::Duration(time).sleep();}
    }
    else if (movement[i] == 2)
    {
         for (int j = movement_execution[i]; j > 0; j--){
        srv.request.angular = M_PI/18;
                client.call(srv);
                ros::Duration(time).sleep();}
    }
    else if (movement[i] == -2)
    {
        for (int j = movement_execution[i]; j > 0; j--){
      srv.request.angular = -M_PI/18;
                client.call(srv);
                ros::Duration(time).sleep();}
    }
    
    
    /*
     ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
     ros::Duration(0.5).sleep();
     turtlesim::TeleportAbsolute srv;
     */

    i++;


     ros::ServiceClient pen_client = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
     turtlesim::SetPen pen_srv;
/*
     std::cout << "SELECT FIGURE" << std::endl;
     std::cout << "1. Square" << std::endl;
     std::cout << "2. Star " << std::endl;
     std::cout << "3. Circle " << std::endl;
     
     std::cin >> shape;
*/ 

/* TELEPORT ABSOLUTE
     if (shape == 1){
    pen_srv.request.off = true;
    pen_client.call(pen_srv);
      srv.request.x = 1.0;
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

      srv.request.x = 1.0;
      srv.request.y =10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 10.0;
      srv.request.y = 10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 10.0;
      srv.request.y =1.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 1.0;
      srv.request.y =1.0;
      client.call(srv);
      ros::Duration(time).sleep();

     }
     else if (shape == 2){
     pen_srv.request.off = true;
     pen_client.call(pen_srv);
      srv.request.x = 2.0;
      srv.request.y = 3.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

      srv.request.x = 9.0;
      srv.request.y = 3.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 5.5;
      srv.request.y = 10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 2.0;
      srv.request.y = 3.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = true;
     pen_client.call(pen_srv);

      srv.request.x = 5.5;
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

srv.request.x = 9.0;
      srv.request.y = 8.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 2.0;
      srv.request.y = 8.0;
      client.call(srv);
      ros::Duration(time).sleep();


       srv.request.x = 5.5;
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

     }
     else if (shape == 3){

     }
     */
    
/* TELEPORT ABSOLUTE
     if (shape == 1){
    pen_srv.request.off = true;
    pen_client.call(pen_srv);
      srv.request.x = 1.0;
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

      srv.request.x = 1.0;
      srv.request.y =10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 10.0;
      srv.request.y = 10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 10.0;
      srv.request.y =1.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 1.0;
      srv.request.y =1.0;
      client.call(srv);
      ros::Duration(time).sleep();

     }
     else if (shape == 2){
     pen_srv.request.off = true;
     pen_client.call(pen_srv);
      srv.request.x = 2.0;
      srv.request.y = 3.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

      srv.request.x = 9.0;
      srv.request.y = 3.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 5.5;
      srv.request.y = 10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 2.0;
      srv.request.y = 3.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = true;
     pen_client.call(pen_srv);

      srv.request.x = 5.5;
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

srv.request.x = 9.0;
      srv.request.y = 8.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 2.0;
      srv.request.y = 8.0;
      client.call(srv);
      ros::Duration(time).sleep();


       srv.request.x = 5.5;
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

     }
     else if (shape == 3){

     }*/
/*
     if (shape == 1){

    pen_srv.request.off = true;
    pen_client.call(pen_srv);
      srv.request.linear 
      srv.request.y = 1.0;
      client.call(srv);
      ros::Duration(time).sleep();

    pen_srv.request.off = false;
    pen_client.call(pen_srv);

      srv.request.x = 1.0;
      srv.request.y =10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 10.0;
      srv.request.y = 10.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 10.0;
      srv.request.y =1.0;
      client.call(srv);
      ros::Duration(time).sleep();


      srv.request.x = 1.0;
      srv.request.y =1.0;
      client.call(srv);
      ros::Duration(time).sleep();

     }
     else if (shape == 2){

     }
     else if (shape == 3){

     }




*/
/*
    srv.request.linear = 1.0;
    client.call(srv);
    ros::Duration(0.5).sleep();
    i++;
    */

  /*  ros::spinOnce(); */



//Different ways of moving the turtlesim: i. Teleport Absolute, ii. Teleport Relative, iii. continously 

/*
  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");

  ros::Duration(0.5).sleep();

  turtlesim::TeleportAbsolute srv;
  srv.request.x = 1.0;
  srv.request.y = 10.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 10.0;
  srv.request.y = 10.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 10.0;
  srv.request.y = 5.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 1.0;
  srv.request.y = 5.0;
  client.call(srv);
  ros::Duration(0.5).sleep();

  srv.request.x = 1.0;
  srv.request.y = 10.0;
  client.call(srv);
*/

/*
  ros::ServiceClient client = nh.serviceClient<turtlesim::TeleportRelative>("/turtle1/teleport_relative");

  ros::Duration(0.5).sleep();

  turtlesim::TeleportRelative srv;
  srv.request.linear= 1.0;
  srv.request.angular = 0.0;
  client.call(srv);
  ros::Duration(0.5).sleep();
*/
/*
    msg.linear.x = 1.0;
    msg.angular.z = 0.0;
    cmd_vel_pub.publish(msg);
    ros::Duration(0.2).sleep();
    */

  }

  return 0;
}