#include "telemetry.h"
#include "robot.h"
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>
#include <iostream>


void initTelemetry(std::ofstream &logFile){
    logFile << "Timestamp,State,Direction,Left Ticks,Right Ticks,Distance Traveled,Heading,Left PWM, Right PWM,PID Error, PID Correction, Obstacle Distance, Avoidance Count" << '\n';
}

void writeTelemetry(std::ofstream &logFile, const robotData &robot){
    std::time_t timeStamp = std::time(nullptr);
    logFile << std::fixed << std::setprecision(2);


    logFile << timeStamp << ","
    << stateToString(robot.state) << ","
    << directionToString(robot.direction) << ","
    << robot.leftMotor.encoderTicks << ","
    << robot.rightMotor.encoderTicks << ","
    << robot.totalDistanceTraveled << ","
    << robot.heading << ","
    << robot.leftMotor.currentSpeed << ","
    << robot.rightMotor.currentSpeed << ","
    << robot.pidError << ","
    << robot.pidCorrection << ","
    << robot.ultrasonic.distance << ","
    << robot.avoidanceManeuvers << "\n";
}


void printRobotInfo(const robotData &robot){

    std::cout << "State: " << stateToString(robot.state) << "\n";
    std::cout << "Direction: " << directionToString(robot.direction) << "\n";
    std::cout << "Distance: " << robot.totalDistanceTraveled << "\n";
    std::cout << "Heading: " << robot.heading << "\n";
    std::cout << "Left Motor PWM: " << robot.leftMotor.pwmSpeed << "\n";
    std::cout << "Right Motor PWM: " << robot.rightMotor.pwmSpeed << "\n";
    std::cout << "PID Error: " << robot.pidError << "\n";
    std::cout << "Obstacle Distanece: " << robot.ultrasonic.distance << "cm\n";
    std::cout << "Avoidance Maneuvers: " << robot.avoidanceManeuvers << "\n";
}