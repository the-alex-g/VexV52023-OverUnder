#pragma once

#include "universals.h"


class DriveTrain {
private:
    motor leftForwardDrive = motor(PORT11, ratio18_1, false);
    motor leftRearDrive = motor(PORT12, ratio18_1, false);
    motor rightForwardDrive = motor(PORT19, ratio18_1, true);
    motor rightRearDrive = motor(PORT20, ratio18_1, true); 
public:
    void spinLeft(double velocity, directionType direction);
    void spinRight(double velocity, directionType direction);
};


void DriveTrain::spinLeft(double velocity, directionType direction = fwd) {
    leftForwardDrive.setVelocity(velocity, percent);
    leftRearDrive.setVelocity(velocity, percent);
    leftForwardDrive.spin(direction);
    leftRearDrive.spin(direction);
}


void DriveTrain::spinRight(double velocity, directionType direction = fwd) {
    rightForwardDrive.setVelocity(velocity, percent);
    rightRearDrive.setVelocity(velocity, percent);
    rightForwardDrive.spin(direction);
    rightRearDrive.spin(direction);
}


DriveTrain driveTrain;