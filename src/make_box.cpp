#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/TeleportAbsolute.h>
#include <turtlesim/SetPen.h>
#include <iostream>
#include <cmath>
#include <time.h>


  float offset = 5.5f;
  int width = 0;

  struct teleport_options{
    float box_size;
    turtlesim::TeleportAbsolute srv;
    ros::ServiceClient teleport_client;
  };

void select_color(int color, turtlesim::SetPen& pen_srv){
 switch (color)
 {
 case 1:
  pen_srv.request.r = 255;
  pen_srv.request.g = 0;
  pen_srv.request.b = 0;
   break;
  
 case 2:
  pen_srv.request.r = 0;
  pen_srv.request.g = 0;
  pen_srv.request.b = 255;
   break;
 case 3:
  pen_srv.request.r = 0;
  pen_srv.request.g = 255;
  pen_srv.request.b = 0;
   break;

 default:
   break;
 }
}
void start_pos(teleport_options c, int figure){
    int figure_number;
    if (figure == 1)
    {
      c.srv.request.x = offset-c.box_size/2;
      c.srv.request.y = offset-c.box_size/2;
      c.teleport_client.call(c.srv);
    };
    if (figure == 2)
    {
      c.srv.request.x = offset;
      c.srv.request.y = offset-c.box_size/2;
      c.teleport_client.call(c.srv);
    };
    if (figure == 3)
    {
      float r = c.box_size/2;
      c.srv.request.x = offset + r/2;
      c.srv.request.y = offset + (sqrt(3)/2)*r;
      c.teleport_client.call(c.srv);
    };
}

void square(teleport_options c){
  c.srv.request.x = offset-c.box_size/2;
  c.srv.request.y = offset+c.box_size/2;
  c.teleport_client.call(c.srv);

  c.srv.request.x = offset+c.box_size/2;
  c.srv.request.y = offset+c.box_size/2;
  c.teleport_client.call(c.srv);

  c.srv.request.x = offset+c.box_size/2;
  c.srv.request.y = offset-c.box_size/2;
  c.teleport_client.call(c.srv);

  c.srv.request.x = offset-c.box_size/2;
  c.srv.request.y = offset-c.box_size/2;
  c.teleport_client.call(c.srv);
}

void triangle(teleport_options c){
      c.srv.request.x = offset+c.box_size/2;
      c.srv.request.y = offset+c.box_size/2;
      c.teleport_client.call(c.srv);

      c.srv.request.x = offset-c.box_size/2;
      c.srv.request.y = offset+c.box_size/2;
      c.teleport_client.call(c.srv);

  c.srv.request.x = offset;
      c.srv.request.y = offset-c.box_size/2;
      c.teleport_client.call(c.srv);

}

void hexagon(teleport_options c){

      float r = c.box_size/2;
      c.srv.request.x = offset - r/2;
      c.srv.request.y = offset + (sqrt(3)/2)*r;
      c.teleport_client.call(c.srv);

      c.srv.request.x = offset - c.box_size/2;
      c.srv.request.y = offset;
      c.teleport_client.call(c.srv);

      c.srv.request.x = offset - r/2;
      c.srv.request.y = offset - (sqrt(3)/2)*r;
      c.teleport_client.call(c.srv);

      c.srv.request.x = offset + r/2;
      c.srv.request.y = offset - (sqrt(3)/2)*r;
      c.teleport_client.call(c.srv);

      c.srv.request.x = offset + c.box_size/2;
      c.srv.request.y = offset;
      c.teleport_client.call(c.srv);

      c.srv.request.x = offset + r/2;
      c.srv.request.y = offset + (sqrt(3)/2)*r;
      c.teleport_client.call(c.srv);

}

bool outside_range(int value, int max_range, int offset){
  if(value > max_range - 1 + offset){
    return true;
  } else if(value < offset){
    return true;
  } else{
    return false;
  }
  

}


int main(int argc, char *argv[]) {
  ros::init(argc, argv, "move_turtlesim");
    float box_size = ros::param::param("~box_size", 9.0);
    int shape;
    int color;
    std::cout << "Define witdh: ";

 

  
  std::cin >> width;

  while (outside_range(color,3,1))
  {

    std::cout << "Select color" << std::endl;
    std::cout << "1 - red" << std::endl;
    std::cout << "2 - blue" << std::endl;
    std::cout << "3 - green" << std::endl;
    std::cout << "Enter number: ";
    std::cin >> color;
  }


  while (outside_range(shape,3,1))
  {

    std::cout << "Select shape" << std::endl;
    std::cout << "1 - square" << std::endl;
    std::cout << "2 - triangle" << std::endl;
    std::cout << "3 - hexagon" << std::endl;
    std::cout << "Enter number: ";
    std::cin >> shape;
  }

  std::cout << shape << std::endl;

  ros::NodeHandle nh;

  ros::service::waitForService("/turtle1/teleport_absolute", -1);

  ros::ServiceClient teleport_client = nh.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
  ros::ServiceClient pen_client = nh.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");




  turtlesim::SetPen pen_srv;
  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  turtlesim::TeleportAbsolute srv;

  teleport_options options;
  options.box_size = box_size;
  options.teleport_client = teleport_client;
  options.srv = srv;

  start_pos(options, shape);



  pen_srv.request.off = false;
  pen_srv.request.width = width;
  select_color(color, pen_srv);
  pen_client.call(pen_srv);

switch (shape)
{
case 1:
  square(options);
  break;
case 2:
  triangle(options);
  break;
case 3:
  hexagon(options);
  break;
}

  pen_srv.request.off = true;
  pen_client.call(pen_srv);

  srv.request.x = 5.5;
  srv.request.y = 5.5;
  teleport_client.call(srv);

  pen_srv.request.off = false;
  pen_srv.request.width = 4;
  pen_srv.request.r = 255;
  pen_srv.request.g = 0;
  pen_srv.request.b = 255;
  pen_client.call(pen_srv);

  return 0;
}