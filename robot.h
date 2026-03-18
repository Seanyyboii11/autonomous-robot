#ifndef ROBOT_H
#define ROBOT_H

#include <fstream>

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

struct UltrasonicData{
    double distance = 0;
    double detectionThreshold = 30.0; //cm
    bool obstacleDetected = false;
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
    double heading = 0; //
};

RobotState updateState(robotData &robot);

void printRobotInfo(const robotData &robot);

double calculateDistance(int ticks, double wheelDiameter, int ticksPerRotation);

double calculateHeading(const robotData &robot);

std::string stateToString(RobotState state);

std::string directionToString(DriveDirection direction);



#endif