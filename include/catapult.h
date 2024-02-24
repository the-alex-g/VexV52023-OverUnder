#pragma once

#include "universals.h"


class Catapult {
private:
    const double minCatapultPercentVelocity = 50.0;
    const double maxCatapultPercentVelocity = 100.0;
    motor catapultMotor = motor(PORT12, ratio18_1, true);
public:
    Catapult();
    void spinCatapult();
    void spinCatapultFor(double time);
};


Catapult::Catapult() {
    catapultMotor.setBrake(hold);
    catapultMotor.setVelocity(maxCatapultPercentVelocity, percent);
}


void Catapult::spinCatapult() {
    catapultMotor.spin(fwd);
    while (spinCatapultButton.pressing()) {
        wait(20.0, msec);
    }
    catapultMotor.stop();
}


void Catapult::spinCatapultFor(double time) {
    catapultMotor.spin(fwd);
    while (time > 0.0) {
        wait(0.05, sec);
        time -= 0.05;
    }
    catapultMotor.stop();
}


Catapult catapult;