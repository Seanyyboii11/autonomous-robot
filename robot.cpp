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

void setMotorSpeed(motorData &motor, int pwmSpeed){
    if(pwmSpeed < 0) pwmSpeed = 0;

    if(pwmSpeed > 255) pwmSpeed = 255;
    
    motor.pwmSpeed = pwmSpeed;
}

void drive(robotData &robot, DriveDirection direction, int speed){
    robot.direction = direction; // no need for drivedirection::direction since it already is. 
    setMotorSpeed(robot.leftMotor, speed);
    setMotorSpeed(robot.rightMotor, speed);
}

void stopRobot(robotData &robot){
    setMotorSpeed(robot.leftMotor, 0);
    setMotorSpeed(robot.rightMotor, 0);
    robot.direction = DriveDirection::STOP;

}

void handleObstacle(robotData &robot){
    if(robot.ultrasonic.obstacleDetected){
        stopRobot(robot);
        robot.state = RobotState::AVOIDING;
        
        drive(robot, DriveDirection::LEFT, 150);
        robot.avoidanceManeuvers++;

        robot.ultrasonic.obstacleDetected = false;
        robot.state = RobotState::AUTONOMOUS;


    }

}
