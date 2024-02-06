#pragma once

#include "universals.h"


class Intake {
private:
    motor intakeMotor = motor(PORT18, ratio18_1, false);
    const double intakePercentVelocity = 100.0;
public:
    const controller::button intakeInButton = controller1.ButtonR1;
    const controller::button intakeOutButton = controller1.ButtonR2;

    Intake();
    void spinIntakeOut();
    void spinIntakeIn();
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


Intake intake;