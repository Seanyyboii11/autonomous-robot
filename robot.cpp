#include "robot.h"
#include <iostream>


RobotState updateState(robotData &robot){
if(robot.leftMotor.overHeating || robot.rightMotor.overHeating){
    return RobotState::MOTOR_OVERHEAT;
}
if(robot.remoteSwitch){
    return RobotState::REMOTE_CONTROL;
}
if(robot.ultrasonic.obstacleDetected){
    return RobotState::OBSTACLE_DETECTED;
}
else{
    return RobotState::AUTONOMOUS;
}

}

void printRobotInfo(const robotData &robot){

    std::cout << "State: " << stateToString(robot.state) << "\n";
    std::cout << "Direction: " << directionToString(robot.direction) << "\n";
    std::cout << "Distance: " << robot.totalDistanceTraveled << "\n";
    std::cout << "Heading: " << robot.heading << "\n";
    std::cout << "Left Motor Temp: " << robot.leftMotor.temperature << "\n";
    std::cout << "Right Motor Temp: " << robot.rightMotor.temperature << "\n";
    std::cout << "Obstacle: " << robot.ultrasonic.distance << "cm\n";
    std::cout << "Avoidance Maneuvers: " << robot.avoidanceManeuvers << "\n";
}


std::string stateToString(RobotState state){
    switch(state){
        case RobotState::STARTUP: return "STARTUP";
        case RobotState::AUTONOMOUS: return "AUTONOMOUS";
        case RobotState::OBSTACLE_DETECTED: return "OBSTACLE DETECTED";
        case RobotState::AVOIDING: return "AVOIDING";
        case RobotState::REMOTE_CONTROL: return "REMOTE_CONTROL";
        case RobotState::MOTOR_OVERHEAT: return "MOTOR_OVERHEAT";
        case RobotState::SHUTDOWN: return "SHUTDOWN";
        default: return "UNKNOWN";
    }
}


std::string directionToString(DriveDirection direction){
    switch(direction){
        case DriveDirection::FORWARD: return "FORWARD";
        case DriveDirection::BACKWARD: return "BACKWARD";
        case DriveDirection::LEFT: return "LEFT";
        case DriveDirection::RIGHT: return "RIGHT";
        case DriveDirection::STOP: return "STOP";
        default: return "UNKNOWN";
    }
}

