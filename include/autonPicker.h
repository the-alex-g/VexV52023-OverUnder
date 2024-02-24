#pragma once

#include "universals.h"
#include <string>


int autonToRun = 0;

class Button {
  private:
    int x, y, width, height;
  public:
    std::string text;
    color buttonColor;
    bool selected = false;
    
    Button(int x, int y, int width, int height, std::string text, color buttonColor)
    : x(x), y(y), width(width), height(height), text(text), buttonColor(buttonColor){}

    void render();

    bool isClicked();
};


void Button::render() {
    color currentColor = buttonColor;
    if (selected) {
        currentColor = green;
    }
    Brain.Screen.drawRectangle(x, y, width, height, currentColor);
    Brain.Screen.printAt(x + 35, y + 35, false, text.c_str());
}


bool Button::isClicked() {
    return 
    Brain.Screen.pressing() &&
    Brain.Screen.xPosition() >= x && Brain.Screen.xPosition() <= x + height &&
    Brain.Screen.yPosition() >= y && Brain.Screen.yPosition() <= y + height;
}


Button autonButtons[] = {
  Button(270, 170, 200, 60, "Turn Right", red),
  Button(15, 170, 200, 60, "Turn Left", red),
  Button(15, 15, 200, 60, "Skills", blue),
  Button(270, 15, 200, 60, "No Auton", blue)
};


void selectButton(int index) {
    for (int i = 0; i < 4; i++) {
        if (i == index) {
            autonButtons[i].selected = true;
        } else {
            autonButtons[i].selected = false;
        }
    }
}


void pickAuton() {
    while (true) {
        Brain.Screen.clearScreen(white);

        if (Competition.isEnabled()) {
            for (int i = 0; i < 4; i++) {
                autonButtons[i].render();
                if (autonButtons[i].isClicked()) {
                    selectButton(i);
                    autonToRun = i;
                }
            }
        }

        Brain.Screen.render();
        wait(20.0, msec);
    }
}