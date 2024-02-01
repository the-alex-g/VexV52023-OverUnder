#pragma once

#include "universals.h"
#include "pneumatics.h"
#include "drivetrain.h"
#include "catapult.h"
#include "intake.h"


void runDriveMotors() {
    double forward = controller1.Axis3.position() / 2.0;
    double turn = controller1.Axis1.position() / 2.0;

    double leftVelocity = forward + turn;
    double rightVelocity = forward - turn;

    driveTrain.spinLeft(leftVelocity);
    driveTrain.spinRight(rightVelocity);
}


void spinIntakeIn() {
    intake.spinIntakeIn();
}


void spinIntakeOut() {
    intake.spinIntakeOut();
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