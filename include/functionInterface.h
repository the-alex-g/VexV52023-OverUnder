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


void toggleLeftWing() {
    pneumaticSystem.toggleWingOpen(left);
}


void toggleRightWing() {
    pneumaticSystem.toggleWingOpen(right);
}


void toggleBlockerExtended() {
    blocker.toggleExtended();
}