#pragma once

#include "universals.h"


class PneumaticSystem {
private:
    pneumatics wings = pneumatics(Brain.ThreeWirePort.A);
public:
    bool wingsOpen = false;
    void setWingsOpen(bool value);
};

PneumaticSystem pneumaticSystem;


void PneumaticSystem::setWingsOpen(bool value) {
    if (value) {
        wings.open();
    } else {
        wings.close();
    }
    wingsOpen = value;
}