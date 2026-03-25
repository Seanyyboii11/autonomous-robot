#include "pid.h"

const double Kp = 1.0; // how hard to react to current error
const double Ki = 0.01; // how hard to react to the accumulated error
const double Kd = 0.1; // how hard to brake the correction

void updatePID(robotData &robot){

    double P = 0;
    double I = 0;
    double D = 0; 

    robot.pidError = robot.leftMotor.encoderTicks - robot.rightMotor.encoderTicks;

    if(robot.pidError == 0){ 
        robot.lastError = 0;
    return;
    }
    robot.sumError += robot.pidError;

    P = Kp * robot.pidError;
    I = Ki * robot.sumError;
    D = Kd * (robot.pidError - robot.lastError);

    robot.pidCorrection = P + I + D;


    // if error > 0: left - more ticks
    // if error < 0: right - more ticks
        setMotorSpeed(robot.leftMotor, (int)(robot.leftMotor.currentSpeed - robot.pidCorrection/2));
        setMotorSpeed(robot.rightMotor, (int)(robot.rightMotor.currentSpeed + robot.pidCorrection/2));

        
    robot.lastError = robot.pidError;
}