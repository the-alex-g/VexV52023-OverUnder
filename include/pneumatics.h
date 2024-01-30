#pragma once

#include "universals.h"


class PneumaticSystem {
private:
    pneumatics wingRight = pneumatics(Brain.ThreeWirePort.A);
    pneumatics wingLeft = pneumatics(Brain.ThreeWirePort.B);
public:
    bool wingsOpen = false;
    void setWingsOpen(bool value);
};

PneumaticSystem pneumaticSystem;


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