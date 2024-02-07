#pragma once

#include <cmath>
#include "universals.h"


double sign(double value) {
    return std::abs(value) / value;
}


class DriveTrain {
private:
    motor leftForwardDrive = motor(PORT11, ratio18_1, false);
    motor leftRearDrive = motor(PORT12, ratio18_1, false);
    motor rightForwardDrive = motor(PORT19, ratio18_1, true);
    motor rightRearDrive = motor(PORT20, ratio18_1, true); 

    const controller::axis forwardAxis = controller1.Axis3;
    const controller::axis turnAxis = controller1.Axis1;

    const double inchesPerRevolution = 11.5;
    const double degreesPerRevolution = 95.0;

    void zeroMotors();
    void setMotorVelocity(double velocity);
    void setLeftMotorVelocity(double velocity);
    void setRightMotorVelocity(double velocity);
    void spinMotorsToPosition(double position, rotationUnits rotationType);
    void spinLeftToPosition(double position, rotationUnits rotationType);
    void spinRightToPosition(double position, rotationUnits rotationType);
public:
    double getForwardAxisPosition();
    double getTurnAxisPosition();

    void spinLeft(double velocity, directionType direction);
    void spinRight(double velocity, directionType direction);
    bool isStationary();
    void drive();

    void driveForward(double distance);
    void turn(double degrees, turnType direction);
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


bool DriveTrain::isStationary() {
    return ! (
        rightForwardDrive.isSpinning() ||
        leftForwardDrive.isSpinning() ||
        rightRearDrive.isSpinning() ||
        leftRearDrive.isSpinning()
    );
}


void DriveTrain::drive() {
    double forward = getForwardAxisPosition();
    double turn = getTurnAxisPosition();

    double leftVelocity = forward + turn;
    double rightVelocity = forward - turn;

    spinLeft(leftVelocity);
    spinRight(rightVelocity);
}


void DriveTrain::zeroMotors() {
    rightForwardDrive.setPosition(0.0, rev);
    leftForwardDrive.setPosition(0.0, rev);
    rightRearDrive.setPosition(0.0, rev);
    leftRearDrive.setPosition(0.0, rev);
}


void DriveTrain::setMotorVelocity(double velocity) {
    setLeftMotorVelocity(velocity);
    setRightMotorVelocity(velocity);
}


void DriveTrain::setLeftMotorVelocity(double velocity) {
    leftForwardDrive.setVelocity(velocity, percent);
    leftRearDrive.setVelocity(velocity, percent);
}


void DriveTrain::setRightMotorVelocity(double velocity) {
    rightForwardDrive.setVelocity(velocity, percent);
    rightRearDrive.setVelocity(velocity, percent);
}


void DriveTrain::spinLeftToPosition(double position, rotationUnits rotationType) {
    leftForwardDrive.spinToPosition(position, rotationType, false);
    leftRearDrive.spinToPosition(position, rotationType, false);
}


void DriveTrain::spinRightToPosition(double position, rotationUnits rotationType) {
    rightForwardDrive.spinToPosition(position, rotationType, false);
    rightRearDrive.spinToPosition(position, rotationType, false);
}


void DriveTrain::spinMotorsToPosition(double position, rotationUnits rotationType) {
    spinLeftToPosition(position, rotationType);
    spinRightToPosition(position, rotationType);
}


void DriveTrain::driveForward(double inches) {
    zeroMotors();

    double revolutions = inches / inchesPerRevolution;
    setMotorVelocity(75.0 * sign(revolutions));

    spinMotorsToPosition(revolutions, rev);
}


void DriveTrain::turn(double degrees, turnType direction) {
    zeroMotors();

    double revolutions = 1.0 /*degrees / degreesPerRevolution*/;
    double revSign = sign(revolutions);

    if (direction == left) {
        setLeftMotorVelocity(-75.0 * revSign);
        setRightMotorVelocity(75.0 * revSign);
        spinLeftToPosition(-revolutions, rev);
        spinRightToPosition(revolutions, rev);
    } else {
        setLeftMotorVelocity(75.0 * revSign);
        setRightMotorVelocity(-75.0 * revSign);
        spinLeftToPosition(revolutions, rev);
        spinRightToPosition(-revolutions, rev);
    }
}


DriveTrain driveTrain;