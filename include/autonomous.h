#pragma once

#include "universals.h"
#include "drivetrain.h"
#include "pneumatics.h"
#include "intake.h"


void runAuton() {
    intake.spinIntakeInFor(1.0);
    driveTrain.driveForward(48.0);
    waitUntil(driveTrain.isStationary());
    driveTrain.turn(90.0, left);
    waitUntil(driveTrain.isStationary());
    intake.spinIntakeOutFor(1.0);
    driveTrain.driveForward(10.0);
}