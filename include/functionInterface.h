#pragma once

#include "universals.h"
#include "pneumatics.h"
#include "drivetrain.h"
#include "catapult.h"
#include "intake.h"
#include "blocker.h"


void runDriveMotors() {
    driveTrain.drive();
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


void toggleWingState() {
    pneumaticSystem.toggleWingsOpen();
}


void toggleBlockerExtended() {
    blocker.toggleExtended();
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