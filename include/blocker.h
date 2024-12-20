#pragma once

#include "universals.h"


class Blocker {
private:
    motor leftMotor = motor(PORT16, ratio18_1, true);
    motor rightMotor = motor(PORT15, ratio18_1, false);

    const double fullExtensionRevolutions = 1.3;
    const double fullRetractionRevolutions = 0.0;
public:
    bool isExtended = false;

    Blocker();
    void setExtended(bool value);
    void toggleExtended();
};


Blocker::Blocker() {
    leftMotor.setPosition(0.0, rev);
    rightMotor.setPosition(0.0, rev);
    leftMotor.setVelocity(100.0, percent);
    rightMotor.setVelocity(100.0, percent);
}


void Blocker::setExtended(bool value) {
    isExtended = value;
    double target = fullRetractionRevolutions;
    if (NOT isExtended) {
        target = fullExtensionRevolutions;
    }
    leftMotor.spinToPosition(target, rev, false);
    rightMotor.spinToPosition(target, rev, false);
}


void Blocker::toggleExtended() {
    if (NOT leftMotor.isSpinning()) {
        setExtended(NOT isExtended);
    }
}


Blocker blocker;