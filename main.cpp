#include "robot.h"
#include <iostream>

int main(){
    robotData robot;
    std::ofstream logFile("robot-telemetry-data.csv");

    initTelemetry(logFile);

    for(int i = 0; i < 100; i++){
        writeTelemetry(logFile, robot);
        printRobotInfo(robot);


    robot.direction = DriveDirection::FORWARD;
    robot.state = updateState(robot);
    printRobotInfo(robot);

    robot.ultrasonic.obstacleDetected = true;
    updateUltrasonic(robot.ultrasonic, 100);
    handleObstacle(robot);
    printRobotInfo(robot);

    robot.leftMotor.overHeating = true;
    robot.state = updateState(robot);
    printRobotInfo(robot);
    

    }


    return 0;
}