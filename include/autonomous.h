#pragma once

#include "universals.h"
#include "drivetrain.h"
#include "pneumatics.h"
#include "catapult.h"
#include "intake.h"


void basicAuton(turnType turnDirection) {
  driveTrain.driveForward(48.0);

  wait(2.0, sec);
  
  driveTrain.turn(90.0, turnDirection);

  wait(1.0, sec);

  pneumaticSystem.setWingsOpen(true);
  driveTrain.driveForward(10.0);
  intake.spinIntakeOutFor(2.0);

  driveTrain.driveBackward(12.0);
  intake.spinIntakeOutFor(2.0);

  while(true) {
    wait(10.0, sec);
  }
}


void runAuton1() {
    basicAuton(right);
}


void runAuton2() {
    basicAuton(left);
}

void runAuton3() {
    catapult.spinCatapultFor(60.0);
}

void runAuton4() {
}


void runAuton(int auton) {
  pneumaticSystem.setWingsOpen(false);
  switch (auton) {
    case 0:
      runAuton1();
    case 1:
      runAuton2();
    case 2:
      runAuton3();
    case 3:
      runAuton4();
  }
}