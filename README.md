# Autonomous Robot

An autonomous mobile robot built on an STM32 Nucleo development board using C++ and FreeRTOS. This project focuses on learning embedded software development through direct interaction with ARM Cortex-M hardware rather than relying on high-level Arduino libraries.

## Overview

The robot navigates its environment using onboard sensors while coordinating movement through a hierarchical state machine. The project is being migrated from an Arduino-based implementation to an STM32 platform to gain experience with lower-level embedded development, real-time operating systems, and modular firmware design.

## Features

- Autonomous navigation
- Obstacle detection and avoidance
- Hierarchical state machine
- FreeRTOS task scheduling
- Ultrasonic sensor integration
- IMU integration
- Modular C++ firmware architecture

## Hardware

- STM32 Nucleo Development Board
- Ultrasonic Distance Sensor
- IMU
- DC Motors
- Motor Driver
- Chassis
- Battery Pack

## Software

- C++
- STM32
- FreeRTOS
- STM32CubeIDE (or whatever IDE you're using)

## Project Structure

```
src/
    main.cpp
    navigation/
    sensors/
    motors/
    state_machine/
    telemetry/

include/
```

## Current Progress

- Arduino implementation complete
- STM32 migration in progress
- FreeRTOS integration in progress
- State machine implemented
- Sensor integration ongoing

## Future Improvements

- Improve navigation algorithms
- Sensor fusion
- Better path planning
- Wireless telemetry
- PCB for custom electronics

## What I Learned

This project has provided experience with:

- Embedded C++
- ARM Cortex-M development
- FreeRTOS
- Task scheduling
- State machine design
- Sensor integration
- Firmware organization
- Hardware debugging
