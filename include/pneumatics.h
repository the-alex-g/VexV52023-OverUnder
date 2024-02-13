#pragma once

#include "universals.h"


class PneumaticSystem {
private:
    pneumatics wingRight = pneumatics(Brain.ThreeWirePort.A);
    pneumatics wingLeft = pneumatics(Brain.ThreeWirePort.B);
public:
    const controller::button toggleWingsButton = controller1.ButtonA;

    bool wingsOpen = false;
    void setWingsOpen(bool value);
    void toggleWingsOpen();
};


void PneumaticSystem::setWingsOpen(bool value) {
    if (value) {
        wingLeft.open();
        wingRight.open();
    } else {
        wingLeft.close();
        wingRight.close();
    }
    wingsOpen = value;
}


void PneumaticSystem::toggleWingsOpen() {
    setWingsOpen(NOT wingsOpen);
}

 
PneumaticSystem pneumaticSystem;