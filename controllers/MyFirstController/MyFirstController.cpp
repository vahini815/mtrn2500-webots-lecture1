// File:          MyFirstController.cpp
// Date:
// Description:
// Author:
// Modifications:

// You may need to add webots include files such as
// <webots/DistanceSensor.hpp>, <webots/Motor.hpp>, etc.
// and/or to add some other includes

// provided header files when install webots on computer, see webots souorce files
#include <webots/Robot.hpp> 
#include <webots/Motor.hpp> 

const int TIME_STEP {64};
const double MAX_SPEED {6.28};

int main(int argc, char **argv) {
  // create object on the stack

  webots::Robot robot {}; // uses namespace webots, define object robot of class Robot

  // get motor devices using Motor function in Robot.hpp file 
  webots::Motor* leftMotor {robot.getMotor("left wheel motor")};
  webots::Motor* rightMotor {robot.getMotor("right wheel motor")};
  // rightMotor is a pointer to Motor class, initialised to the specified left or right wheel motor

  // set target position of motor 
  // leftMotor points to Motor class, so look in Motor.hpp
  // leftMotor->setPosition(10.0); // absolute position, set target travel distance in radians
  // rightMotor->setPosition(10.0); // use -> to access members of Motor class through the pointer rightMotor
  
  leftMotor->setPosition(INFINITY); // switch motor to velocity control
  rightMotor->setPosition(INFINITY); 
  
  leftMotor->setVelocity(0.1 * MAX_SPEED); // switch motor to velocity control
  rightMotor->setVelocity(-0.1 * MAX_SPEED); 
  // opposite directions, rotate in place


  while (robot.step(TIME_STEP) != -1); 
  // controller synchronises w physical simulation

  return 0;
}


