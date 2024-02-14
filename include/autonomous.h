#pragma once

#include "universals.h"
#include "drivetrain.h"
#include "pneumatics.h"
#include "intake.h"


void basicAuton(turnType turnDirection) {
  intake.spinIntakeInFor(1.0);
    driveTrain.driveForward(48.0);

    waitUntil(driveTrain.isStationary());
    
    driveTrain.turn(90.0, turnDirection);

    wait(750, msec);

    driveTrain.driveForward(9.0);
    intake.spinIntakeOutFor(3.0);
}


// Red side right
void runAutonR1(){
    basicAuton(right);
}


// Blue side left
void runAutonR2() {
    basicAuton(left);
}

// Red side left
void runAutonB1(){
    basicAuton(left);
}

// Blue side right
void runAutonB2(){
    basicAuton(right);
}


void runAuton(int auton) {
    switch (auton) {
      case 0:
        runAutonR1();
      case 1:
        runAutonR2();
      case 2:
        runAutonB1();
      case 3:
        runAutonB2();
    }
}