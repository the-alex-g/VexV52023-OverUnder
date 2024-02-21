#include "universals.h"
#include "functionInterface.h"
#include "autonomous.h"
#include "autonPicker.h"
#include "controllerBindings.h"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton() {
  return;
}


/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous() {
  runAuton(autonToRun);  
};

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol() {
  while (true) {
    
    runDriveMotors();
    intakeInButton.pressed(spinIntakeIn);
    intakeOutButton.pressed(spinIntakeOut);
    spinCatapultButton.pressed(fireCatapult);
    toggleWingsButton.pressed(toggleWingState);
    toggleLeftWingButton.pressed(toggleLeftWing);
    toggleRightWingButton.pressed(toggleRightWing);
    extendButton.pressed(toggleBlockerExtended);

    wait(20, msec);
  }
}


int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pickAuton();

  while (true) {
    wait(20.0, msec);
  }
}
