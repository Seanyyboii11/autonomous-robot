#include "odometry.h"
#include "robot.h"
#include <iostream>

const double wheelDiameter_CM = 10; // will change
const double wheelCircumference_CM = 3.14159 * wheelDiameter_CM;
const int ticksPerRotation = 20; // will change

void updateOdometry(robotData &robot){

    double leftDistance = calculateDistanceTraveled(robot.leftMotor.encoderTicks);
    double rightDistance = calculateDistanceTraveled(robot.rightMotor.encoderTicks);

    robot.totalDistanceTraveled = (leftDistance + rightDistance) / 2.0;
    robot.heading = calculateHeading(leftDistance, rightDistance);
}

double calculateDistanceTraveled(int encoderTicks){

    return (encoderTicks * wheelCircumference_CM) / ticksPerRotation;
}

double calculateHeading(double leftTraveled, double rightTraveled){
    return leftTraveled - rightTraveled; // will be degree facing. will have to figure out formula
}