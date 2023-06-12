#include "ros/ros.h"
#include "sensor_msgs/BatteryState.h"

class BatteryStatePublisher
{
public:
  BatteryStatePublisher()
  {
    // Create publisher
    publisher_battery_state_ = nh_.advertise<sensor_msgs::BatteryState>("/battery_status", 10);

    // Time interval in seconds
    double timer_period = 5.0;
    timer_ = nh_.createTimer(ros::Duration(timer_period), &BatteryStatePublisher::getBatteryState, this);

    // Initialize battery level
    battery_voltage_ = 9.0;            // Initialize the battery voltage level
    percent_charge_level_ = 1.0;       // Initialize the percentage charge level
    decrement_factor_ = 0.99;          // Used to reduce battery level each cycle
  }

private:
  void getBatteryState(const ros::TimerEvent& event)
  {
    sensor_msgs::BatteryState msg;  // Create a message of this type
    msg.voltage = battery_voltage_;
    msg.percentage = percent_charge_level_;
    publisher_battery_state_.publish(msg);  // Publish BatteryState message

    // Decrement the battery state
    battery_voltage_ *= decrement_factor_;
    percent_charge_level_ *= decrement_factor_;
  }

  ros::NodeHandle nh_;
  ros::Publisher publisher_battery_state_;
  ros::Timer timer_;
  double battery_voltage_;
  double percent_charge_level_;
  double decrement_factor_;
};

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "battery_state_pub");

  BatteryStatePublisher battery_state_pub;

  ros::spin();

  return 0;
}
