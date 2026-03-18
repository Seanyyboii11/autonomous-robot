#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <fstream>

struct robotData;

void initTelemetry(std::ofstream &logFile);

void writeTelemetry(std::ofstream &logFile, const robotData &robot);

#endif