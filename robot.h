#ifndef ROBOT_H
#define ROBOT_H

#include <fstream>
#include "ultrasonic.h"
#include "odometry.h"
#include "telemetry.h"

enum class RobotState {
    STARTUP,
    AUTONOMOUS,
    OBSTACLE_DETECTED,
    AVOIDING,
    REMOTE_CONTROL,
    MOTOR_OVERHEAT,
    SHUTDOWN
};

enum class DriveDirection{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    STOP
};

struct motorData{
    double temperature = 0;
    double maxTemp = 0;
    bool overHeating = false;

    int encoderTicks = 0;
    int totalRotations = 0;
    double distanceTraveled = 0;
    double currentSpeed = 0;
    int pwmSpeed = 0;
};

struct robotData{
    RobotState state = RobotState::STARTUP;
    DriveDirection direction = DriveDirection::STOP;

    motorData leftMotor;
    motorData rightMotor;

    UltrasonicData ultrasonic;

    bool remoteSwitch = false;
    double totalDistanceTraveled = 0;
    int avoidanceManeuvers = 0;
    double heading = 0; //direction facing in degrees
};

RobotState updateState(robotData &robot);

void printRobotInfo(const robotData &robot);

double calculateDistance(int ticks, double wheelDiameter, int ticksPerRotation);

double calculateHeading(const robotData &robot);

std::string stateToString(RobotState state);

std::string directionToString(DriveDirection direction);

void setMotorSpeed(motorData &motor, int pwmSpeed);

void drive(robotData &robot, DriveDirection direction, int speed);

void stopRobot(robotData &robot);

void handleObstacle(robotData &robot);  

#endif