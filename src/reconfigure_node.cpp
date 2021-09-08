#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <rqt_reconfigure_tutorial/sampleConfig.h>
#include <iostream>

void callback(rqt_reconfigure_tutorial::sampleConfig& config, uint32_t level){
    std::cout << "==========================" << std::endl;
    ROS_INFO("intParam Request: %d", config.int_param);
    ROS_INFO("doubleParam Request: %f", config.double_param);
    ROS_INFO("stringParam Request: %s", config.str_param.c_str());
    ROS_INFO("boolParam Request: %s",config.bool_param ? "True" : "False");
    ROS_INFO("Reconfigure Request: %d",config.size);
    std::cout << "==========================" << std::endl;
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "reconfigure");
  dynamic_reconfigure::Server<rqt_reconfigure_tutorial::sampleConfig> server;
  dynamic_reconfigure::Server<rqt_reconfigure_tutorial::sampleConfig>::CallbackType f;
  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);
  ros::spin();
  return 0;
}