#pragma once

#include "universals.h"


class DriveTrain {
private:
    motor leftForwardDrive = motor(PORT11, ratio18_1, false);
    motor leftRearDrive = motor(PORT12, ratio18_1, false);
    motor rightForwardDrive = motor(PORT19, ratio18_1, true);
    motor rightRearDrive = motor(PORT20, ratio18_1, true); 

    const controller::axis forwardAxis = controller1.Axis3;
    const controller::axis turnAxis = controller1.Axis1;
public:
    double getForwardAxisPosition();
    double getTurnAxisPosition();

    void spinLeft(double velocity, directionType direction);
    void spinRight(double velocity, directionType direction);
    void drive();
};


double DriveTrain::getForwardAxisPosition() {
    return forwardAxis.position() / 2.0;
}


double DriveTrain::getTurnAxisPosition() {
    return turnAxis.position() / 2.0;
}


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


void DriveTrain::drive() {
    double forward = getForwardAxisPosition();
    double turn = getTurnAxisPosition();

    double leftVelocity = forward + turn;
    double rightVelocity = forward - turn;

    driveTrain.spinLeft(leftVelocity);
    driveTrain.spinRight(rightVelocity);
}


DriveTrain driveTrain;