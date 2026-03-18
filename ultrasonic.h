#ifndef ULTRASONIC_H
#define ULTRASONIC_H

struct UltrasonicData{
    double distance = 0;
    double detectionThreshold = 30.0; //cm
    bool obstacleDetected = false;
};

double calculateDistance(double microseconds);

void updateUltrasonic(UltrasonicData &ultrasonic, double microseconds);

#endif