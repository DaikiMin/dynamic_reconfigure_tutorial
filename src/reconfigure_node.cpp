#include <ros/ros.h>
#include <dynamic_reconfigure/server.h>
#include <rqt_reconfigure_tutorial/sampleConfig.h>
#include <iostream>

namespace rqt_reconfigure_tutorial {
    class DynamicReconfigureTemlate {
        private:
            ros::NodeHandle nh_;
            ros::NodeHandle pnh_;
            dynamic_reconfigure::Server<rqt_reconfigure_tutorial::sampleConfig>* server_;
            dynamic_reconfigure::Server<rqt_reconfigure_tutorial::sampleConfig>::CallbackType f_;
            void callback(rqt_reconfigure_tutorial::sampleConfig& config, uint32_t level);

        public:
            DynamicReconfigureTemlate( );
    };
}

void rqt_reconfigure_tutorial::DynamicReconfigureTemlate::callback(rqt_reconfigure_tutorial::sampleConfig& config, uint32_t level){
    std::cout << "==========================" << std::endl;
    ROS_INFO("intParam Request: %d", config.int_param);
    ROS_INFO("doubleParam Request: %f", config.double_param);
    ROS_INFO("stringParam Request: %s", config.str_param.c_str());
    ROS_INFO("boolParam Request: %s",config.bool_param ? "True" : "False");
    ROS_INFO("Reconfigure Request: %d",config.size);
    std::cout << "==========================" << std::endl;
}

rqt_reconfigure_tutorial::DynamicReconfigureTemlate::DynamicReconfigureTemlate( ) : nh_(), pnh_("~") {
    server_ = new dynamic_reconfigure::Server<rqt_reconfigure_tutorial::sampleConfig>(pnh_);            // このとき初期値がrosparamで変更される
    f_ = boost::bind(&rqt_reconfigure_tutorial::DynamicReconfigureTemlate::callback, this, _1, _2);     // dynamic_reconfigureのコールバック関数を指定
    server_->setCallback(f_);
}

int main(int argc, char *argv[])  {
    ros::init(argc, argv, "reconfigure");
    rqt_reconfigure_tutorial::DynamicReconfigureTemlate reconfigure;
    ros::spin();
    return 0;
}