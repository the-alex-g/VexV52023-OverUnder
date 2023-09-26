#pragma once

#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor leftDrive = motor(PORT1, ratio18_1, true);
motor rightDrive = motor(PORT2, ratio18_1, true);


void runDriveMotors() {
    double forward = controller1.Axis3.position() / 2.0;
    double turn = controller1.Axis1.position() / 2.0;

    double leftVelocity = forward - turn;
    double rightVelocity = forward + turn;

    leftDrive.setVelocity(leftVelocity, percent);
    rightDrive.setVelocity(rightVelocity, percent);

    leftDrive.spin(fwd);
    rightDrive.spin(reverse);
}