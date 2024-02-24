#pragma once

#include "universals.h"


class PneumaticSystem {
private:
    pneumatics wingRight = pneumatics(Brain.ThreeWirePort.A);
    pneumatics wingLeft = pneumatics(Brain.ThreeWirePort.B);
    bool leftWingOpen = false;
    bool rightWingOpen = false;
public:
    void setWingOpen(bool value, turnType side);
    void toggleWingOpen(turnType side);
    void setWingsOpen(bool value);
    void toggleWingsOpen();
};


void PneumaticSystem::setWingOpen(bool value, turnType side) {
    if (side == right) {
        if (value) {
          wingRight.close(); 
        } else {
            wingRight.open();
        }
        rightWingOpen = value;
    } else if (side == left) {
        if (value) {
            wingLeft.close();
        } else {
            wingLeft.open();
        }
        leftWingOpen = value;
    }
}


void PneumaticSystem::toggleWingOpen(turnType side) {
    if (side == right) {
        setWingOpen(NOT rightWingOpen, right);
    } else if (side == left) {
        setWingOpen(NOT leftWingOpen, left);
    }
}


void PneumaticSystem::setWingsOpen(bool value) {
    setWingOpen(value, left);
    setWingOpen(value, right);
}


void PneumaticSystem::toggleWingsOpen() {
    setWingsOpen(NOT (leftWingOpen && rightWingOpen));
}


PneumaticSystem pneumaticSystem;