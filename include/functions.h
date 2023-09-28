#pragma once

#include "vex.h"

using namespace vex;

brain Brain;

controller controller1 = controller(primary);

motor leftDrive = motor(PORT1, ratio18_1, true);
motor rightDrive = motor(PORT2, ratio18_1, true);
motor intakeArm = motor(PORT3, ratio18_1, true);
motor intake = motor(PORT4, ratio18_1, true);

bool armDown = false;


void runDriveMotors() {
    double forward = controller1.Axis3.position() / 2.0;
    double turn = controller1.Axis1.position() / 2.0;

    double leftVelocity = forward + turn;
    double rightVelocity = forward - turn;

    leftDrive.setVelocity(leftVelocity, percent);
    rightDrive.setVelocity(rightVelocity, percent);

    leftDrive.spin(reverse);
    rightDrive.spin(fwd);
}


void moveIntakeArm() {
    if (! intakeArm.isSpinning()) {
        if (armDown) {
            intakeArm.spinTo(0.0, degrees);
            armDown = false;
        } else {
            intakeArm.spinTo(1100, degrees);
            armDown = true;
        }
    }
}


void spinIntakeIn() {
  //  if (armDown) {
        intake.spin(reverse);
        while (controller1.ButtonR1.pressing()) {
            wait(20.0, msec);
        }
        intake.stop();
    //}
}


void spinIntakeOut() {
   // if (armDown) {
        intake.spin(fwd);
        while (controller1.ButtonR2.pressing()) {
            wait(20.0, msec);
        }
        intake.stop();
    //}
}