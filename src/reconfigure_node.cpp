#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <rqt_reconfigure_tutorial/SampleConfig.h>
#include <iostream>

namespace rqt_reconfigure_tutorial {
    class DynamicReconfigureTemlate {
        private:
            ros::NodeHandle nh_;
            ros::NodeHandle pnh_;
            dynamic_reconfigure::Server<rqt_reconfigure_tutorial::SampleConfig>* server_;
            dynamic_reconfigure::Server<rqt_reconfigure_tutorial::SampleConfig>::CallbackType f_;
            void callback(rqt_reconfigure_tutorial::SampleConfig& config, uint32_t level);

        public:
            DynamicReconfigureTemlate( );
    };
}

void rqt_reconfigure_tutorial::DynamicReconfigureTemlate::callback(rqt_reconfigure_tutorial::SampleConfig& config, uint32_t level){
    std::cout << "==========================" << std::endl;
    ROS_INFO("intParam Request: %d", config.int_param);
    ROS_INFO("doubleParam Request: %f", config.double_param);
    ROS_INFO("stringParam Request: %s", config.str_param.c_str());
    ROS_INFO("boolParam Request: %s",config.bool_param ? "True" : "False");
    ROS_INFO("Reconfigure Request: %d",config.size);
    std::cout << "--------------------------\n[Group]" << std::endl;
    ROS_INFO("intParam Request: %d", config.group_int_param);
    ROS_INFO("doubleParam Request: %f", config.group_double_param);
    ROS_INFO("stringParam Request: %s", config.group_str_param.c_str());
    ROS_INFO("boolParam Request: %s",config.group_bool_param ? "True" : "False");
    std::cout << "--------------------------\n[Sub Group]" << std::endl;
    ROS_INFO("intParam Request: %d", config.sub_group_int_param);
    ROS_INFO("doubleParam Request: %f", config.sub_group_double_param);
    ROS_INFO("stringParam Request: %s", config.sub_group_str_param.c_str());
    ROS_INFO("boolParam Request: %s",config.sub_group_bool_param ? "True" : "False");
    std::cout << "--------------------------\n[Sub Sub Group]" << std::endl;
    ROS_INFO("intParam Request: %d", config.sub_sub_group_int_param);
    ROS_INFO("doubleParam Request: %f", config.sub_sub_group_double_param);
    ROS_INFO("stringParam Request: %s", config.sub_sub_group_str_param.c_str());
    ROS_INFO("boolParam Request: %s",config.sub_sub_group_bool_param ? "True" : "False");
    std::cout << "==========================" << std::endl;
}

rqt_reconfigure_tutorial::DynamicReconfigureTemlate::DynamicReconfigureTemlate( ) : nh_(), pnh_("~") {
    server_ = new dynamic_reconfigure::Server<rqt_reconfigure_tutorial::SampleConfig>(pnh_);            // このとき初期値がrosparamで変更される
    f_ = boost::bind(&rqt_reconfigure_tutorial::DynamicReconfigureTemlate::callback, this, _1, _2);     // dynamic_reconfigureのコールバック関数を指定
    server_->setCallback(f_);
}

int main(int argc, char *argv[])  {
    ros::init(argc, argv, "reconfigure");
    rqt_reconfigure_tutorial::DynamicReconfigureTemlate reconfigure;
    ros::spin();
    return 0;
}