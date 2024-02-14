#pragma once

#include "universals.h"
#include "drivetrain.h"
#include "pneumatics.h"
#include "intake.h"


void runAutonR1(){
    intake.spinIntakeInFor(1.0);
    driveTrain.driveForward(48.0);

    waitUntil(driveTrain.isStationary());
    
    pneumaticSystem.setWingsOpen(true);
    
    wait(10, msec);
    
    driveTrain.turn(90.0, left);

    wait(750, msec);

    intake.spinIntakeOutFor(1.0);
    driveTrain.driveForward(12.0);
}


void runAutonR2() {
    intake.spinIntakeInFor(1.0);
    driveTrain.driveForward(48.0);
    
    waitUntil(driveTrain.isStationary());
    
    driveTrain.turn(90.0, left);
    
    wait(750, msec);
    
    driveTrain.driveForward(9.0);
    intake.spinIntakeOutFor(3.5);
}


void runAutonB1(){
    driveTrain.driveForward(1.0);
}


void runAutonB2(){
    driveTrain.driveForward(1.0);
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