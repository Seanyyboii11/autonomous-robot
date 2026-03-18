#include "ultrasonic.h"
#include <iostream>

double calculateDistance(double microseconds){
    return 0.0343 * microseconds;
}

void updateUltrasonic(UltrasonicData &ultrasonic, double microseconds){
    ultrasonic.distance = calculateDistance(microseconds);
    ultrasonic.obstacleDetected = ultrasonic.distance < ultrasonic.detectionThreshold;

}