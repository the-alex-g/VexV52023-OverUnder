#pragma once

#include "universals.h"
#include "pneumatics.h"
#include "drivetrain.h"
#include "catapult.h"


motor intake = motor(PORT18, ratio18_1, false);

const double intakePercentVelocity = 100.0;


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
   catapult.spinCatapult();
}


// double lerp(double from, double to, double weight) {
//     return from + (to - from) * weight;
// }


// void primeCatapult() {
//     catapult.spin(fwd);
//     while (catapult.current(percent) < catapultPullbackCurrent) {
//         wait(20.0, msec);
//         catapult.setVelocity(lerp(maxCatapultPercentVelocity, minCatapultPercentVelocity, catapult.current(percent) / catapultPullbackCurrent), percent);
//     }
//     catapult.stop();
// }


void toggleWingState() {
    pneumaticSystem.setWingsOpen(! pneumaticSystem.wingsOpen);
}