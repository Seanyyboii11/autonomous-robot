#ifndef ODOMETRY_H
#define ODOMETRY_H

struct robotData;

void updateOdometry(robotData &robot);

double calculateDistanceTraveled(int encoderTicks);

double calculateHeading(double leftTraveled, double rightTraveled);

#endif