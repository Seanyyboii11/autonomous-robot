#include "telemetry.h"
#include "robot.h"
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>


void initTelemetry(std::ofstream &logFile){
    logFile << "Timestamp,State,Direction,Distance Traveled,Heading,Left Motor Speed,Right Motor Speed,Obstacle Distance,Avoidance Maneuver Count" << '\n';
}

void writeTelemetry(std::ofstream &logFile, const robotData &robot){
    std::time_t timeStamp = std::time(nullptr);
    logFile << std::fixed << std::setprecision(2);


    logFile << timeStamp << ","
    << stateToString(robot.state) << ","
    << directionToString(robot.direction) << ","
    << robot.totalDistanceTraveled << ","
    << robot.heading << ","
    << robot.leftMotor.currentSpeed << ","
    << robot.rightMotor.currentSpeed << ","
    << robot.ultrasonic.distance << ","
    << robot.avoidanceManeuvers << "\n";
}