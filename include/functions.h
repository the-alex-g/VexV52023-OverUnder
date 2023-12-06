#pragma once

#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor leftDrive = motor(PORT11, ratio18_1, false);
motor rightDrive = motor(PORT12, ratio18_1, true);
motor intake = motor(PORT13, ratio18_1, false);
motor catapult = motor(PORT14, ratio18_1, true);
motor wings = motor(PORT15, ratio18_1, false);

const double minCatapultPercentVelocity = 50.0;
const double maxCatapultPercentVelocity = 100.0;
const double intakePercentVelocity = 100.0;
const double catapultPullbackCurrent = 35.0;

bool wingsExtended = true;


void runDriveMotors() {
    double forward = controller1.Axis3.position() / 2.0;
    double turn = controller1.Axis1.position() / 2.0;

    double leftVelocity = forward + turn;
    double rightVelocity = forward - turn;

    leftDrive.setVelocity(leftVelocity, percent);
    rightDrive.setVelocity(rightVelocity, percent);

    leftDrive.spin(fwd);
    rightDrive.spin(fwd);
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


void moveWings() {
    if (wingsExtended) {
        wings.spin(fwd);
    } else {
        wings.spin(reverse);
    }
    while (controller1.ButtonA.pressing()) {
        wait(20.0, msec);
    }
    wings.stop();
    wingsExtended = ! wingsExtended;
}