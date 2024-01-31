#pragma once

#include "universals.h"


class Catapult {
private:
    const double minCatapultPercentVelocity = 50.0;
    const double maxCatapultPercentVelocity = 100.0;
    motor catapultMotor = motor(PORT17, ratio18_1, true);
public:
    const controller::button spinCatapultButton = controller1.ButtonY;
    Catapult();
    void spinCatapult();
};


Catapult::Catapult() {
    catapultMotor.setBrake(hold);
}


void Catapult::spinCatapult() {
    catapultMotor.spin(fwd);
    catapultMotor.setVelocity(maxCatapultPercentVelocity, percent);
    while (spinCatapultButton.pressing()) {
        wait(20.0, msec);
    }
    catapultMotor.stop();
}


Catapult catapult;