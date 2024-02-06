#pragma once

#include "universals.h"


class Blocker {
private:
    motor leftMotor = motor(PORT1, ratio18_1, true);
    motor rightMotor = motor(PORT16, ratio18_1, false);

    const double fullExtensionRotation = 1.65;
    const double fullRetractionRotation = 0.0;
public:
    controller::button extendButton = controller1.ButtonB;
    bool isExtended = false;

    Blocker();
    void setExtended(bool value);
    void toggleExtended();
};


Blocker::Blocker() {
    leftMotor.setPosition(0.0, rev);
    rightMotor.setPosition(0.0, rev);
}


void Blocker::setExtended(bool value) {
    isExtended = value;
    double target = fullRetractionRotation;
    if (! isExtended) {
        target = fullExtensionRotation;
    }
    leftMotor.spinToPosition(target, rev, false);
    rightMotor.spinToPosition(target, rev, false);
}


void Blocker::toggleExtended() {
    if (! leftMotor.isSpinning()) {
        setExtended(! isExtended);
    }
}


Blocker blocker;