/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 4, 5      
// Controller1          controller                    
// Motor8               motor         8               
// Motor9               motor         9               
// Inertial10           inertial      10              
// DigitalOutA          digital_out   A               
// Distance15           distance      15              
// MotorGroup18         motor_group   18, 19          
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

void autonomous(void) {

Drivetrain.setDriveVelocity(100,pct);
Drivetrain.driveFor(forward,100,inches);



Drivetrain.turnFor(left,90,degrees);



Motor9.spinFor(100,degrees);
DigitalOutA.set(true);



Drivetrain.drive(forward);
wait(1,sec);
Drivetrain.stop();





}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) { while (1) {


if(Controller1.ButtonR1.pressing()){
Motor9.spin(forward,12,volt);
}else if(Controller1.ButtonR2.pressing()){
Motor8.spin(reverse,12,volt);
}else(Motor9.stop(hold));

if(Controller1.ButtonL1.pressing()){
Motor8.spin(forward,12,volt);
}else if(Controller1.ButtonL2.pressing()){
Motor8.spin(reverse,12,volt);
}else(Motor8.stop(hold));




if(Controller1.ButtonDown.pressing()){
DigitalOutA.set(true);
}
if(Controller1.ButtonUp.pressing()){
DigitalOutA.set(false);
}






if(Controller1.ButtonUp.pressing()){
DigitalOutA.set(false);
}
else(DigitalOutA.set(true));






wait(20, msec);}}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
