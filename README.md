# TurtleBot3 Battery State Publisher
This ROS package provides a battery state publisher node for TurtleBot3. The purpose of this project is to simulate a battery and publish its state (voltage and percentage charge level) at a regular interval on the topic **/battery_status** in the ROS ecosystem.

## Description
The TurtleBot3 Battery State Publisher is a ROS node that periodically publishes battery state information, including voltage and percentage charge level. The node initializes the battery state with default values and starts publishing the state at a predefined time interval.

## Features
-Simulates a battery state by publishing voltage and percentage charge level
-Allows customization of time interval, initial battery values, and decrement factor
-Publishes battery state information on the topic **/battery_status**

## Dependencies
This package depends on the following ROS packages:
- roscpp
- sensor_msgs

## Usage
Follow these steps to use the TurtleBot3 battery state publisher:
To launch the TurtleBot3 software using the appropriate launch file for TurtleBot3 burger model. 
For example:

```bash
roslaunch turtlebot3_bringup turtlebot3_robot.launch
```
Run the battery state publisher node:
```bash
rosrun turtlebot3_battery battery_state_publisher
```
Verify the battery state publication by echoing the /battery_status topic:
```bash
rostopic echo /battery_status
```

The battery state publisher node will continuously publish the battery voltage and percentage charge level at a regular interval.
