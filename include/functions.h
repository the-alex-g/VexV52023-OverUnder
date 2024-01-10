#pragma once

#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor intake = motor(PORT19, ratio18_1, false);
motor catapult = motor(PORT14, ratio18_1, true);
motor leftWing = motor(PORT15, ratio18_1, false);
motor rightWing = motor(PORT16, ratio18_1, true);

const double minCatapultPercentVelocity = 50.0;
const double maxCatapultPercentVelocity = 100.0;
const double intakePercentVelocity = 100.0;
double catapultPullbackCurrent = 44.0;

bool wingsExtended = true;

class DriveTrain {
private:
    motor leftForwardDrive = motor(PORT17, ratio18_1, false);
    motor leftRearDrive = motor(PORT11, ratio18_1, false);
    motor rightForwardDrive = motor(PORT18, ratio18_1, true);
    motor rightRearDrive = motor(PORT12, ratio18_1, true); 
public:
    void spinLeft(double velocity, directionType direction);
    void spinRight(double velocity, directionType direction);
};


DriveTrain driveTrain;


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


void runDriveMotors() {
    double forward = controller1.Axis3.position() / 2.0;
    double turn = controller1.Axis1.position() / 2.0;

    double leftVelocity = forward + turn;
    double rightVelocity = forward - turn;

    driveTrain.spinLeft(leftVelocity);
    driveTrain.spinRight(rightVelocity);
}


void spinIntakeIn() {
    intake.spin(fwd);
    while (controller1.ButtonR1.pressing()) {
        wait(20.0, msec);
    }
    intake.stop();
}


void spinIntakeOut() {
    intake.spin(reverse);
    while (controller1.ButtonR2.pressing()) {
        wait(20.0, msec);
    }
    intake.stop();
}


void fireCatapult() {
    catapult.spin(fwd);
    catapult.setVelocity(maxCatapultPercentVelocity, percent);
    while (controller1.ButtonY.pressing()) {
        wait(20.0, msec);
    }
    catapult.stop();
}


double lerp(double from, double to, double weight) {
    return from + (to - from) * weight;
}


void primeCatapult() {
    catapult.spin(fwd);
    while (catapult.current(percent) < catapultPullbackCurrent) {
        wait(20.0, msec);
        catapult.setVelocity(lerp(maxCatapultPercentVelocity, minCatapultPercentVelocity, catapult.current(percent) / catapultPullbackCurrent), percent);
    }
    catapult.stop();
}


void spinWings(directionType direction) {
    leftWing.spin(direction);
    rightWing.spin(direction);
}


void stopWings() {
    leftWing.stop();
    rightWing.stop();
}


void moveWings() {
    if (wingsExtended) {
        spinWings(reverse);
    } else {
        spinWings(fwd);
    }
    while (controller1.ButtonA.pressing()) {
        Brain.Screen.clearScreen();
        Brain.Screen.print(leftWing.current());
        wait(20.0, msec);
    }
    stopWings();
    wingsExtended = ! wingsExtended;
}