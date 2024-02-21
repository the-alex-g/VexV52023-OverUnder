#pragma once

#include "universals.h"
#include "controllerBindings.h"


class Intake {
private:
    motor intakeMotor = motor(PORT14, ratio18_1, false);
    const double intakePercentVelocity = 100.0;
public:
    Intake();
    void spinIntakeOut();
    void spinIntakeIn();
    void spinIntakeInFor(double seconds);
    void spinIntakeOutFor(double seconds);
};


Intake::Intake() {
  intakeMotor.setBrake(hold);
  intakeMotor.setVelocity(intakePercentVelocity, percent);
}


void Intake::spinIntakeIn() {
    intakeMotor.spin(fwd);
    while (intakeInButton.pressing()) {
        wait(20.0, msec);
    }
    intakeMotor.stop();
}


void Intake::spinIntakeOut() {
    intakeMotor.spin(reverse);
    while (intakeOutButton.pressing()) {
        wait(20.0, msec);
    }
    intakeMotor.stop();
}

void Intake::spinIntakeInFor(double seconds) {
    intakeMotor.spin(fwd);
    double timeElapsed = 0.0;
    while (timeElapsed < seconds) {
        wait(50, msec);
        timeElapsed += 0.05;
    }
    intakeMotor.stop();
}


void Intake::spinIntakeOutFor(double seconds) {
    intakeMotor.spin(reverse);
    double timeElapsed = 0.0;
    while (timeElapsed < seconds) {
        wait(50, msec);
        timeElapsed += 0.05;
    }
    intakeMotor.stop();
}


Intake intake;