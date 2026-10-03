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
#include <webots/PositionSensor.hpp>
#include <iostream>

const int TIME_STEP {64}; // control step 
const double MAX_SPEED {6.28};
const double WHEEL_RADIUS {0.02}; // 20mm
const double AXLE_LENGTH {0.052};

int main(int argc, char **argv) {
  // create object on the stack

  webots::Robot robot {}; // uses namespace webots, define object robot of class Robot

  // get motor devices using Motor function in Robot.hpp file 
  webots::Motor* leftMotor {robot.getMotor("left wheel motor")};
  webots::Motor* rightMotor {robot.getMotor("right wheel motor")};
  // rightMotor is a pointer to Motor class, initialised to the specified left or right wheel motor

  //tracks the rotation each motor has performed
  webots::PositionSensor* leftEncoder {robot.getPositionSensor("left wheel sensor")};
  webots::PositionSensor* rightEncoder {robot.getPositionSensor("right wheel sensor")};

  // first we have to enable before we can use device
  leftEncoder->enable(TIME_STEP);
  rightEncoder->enable(TIME_STEP);
  
  leftMotor->setPosition(INFINITY); // switch motor to velocity control
  rightMotor->setPosition(INFINITY); 
  
  leftMotor->setVelocity(0.1 * MAX_SPEED);
  rightMotor->setVelocity(-0.1 * MAX_SPEED); 
  // opposite directions, rotate in place

  // synchronises w physical simulation
  // updates the sensor within the while loop (constantly updates during simulation)
  while (robot.step(TIME_STEP) != -1) { // allows controller to synchronise w simulation CONSTANTLY, get result of simulation each time
  // if not for step function, the controller will initialise & not communicate btwn controller and physical simulation
    double leftPosition {leftEncoder->getValue()};
    double rightPosition {rightEncoder ->getValue()};
    std::cout << leftPosition << ' ' << rightPosition << ' ';
    std::cout << (rightPosition + leftPosition) * WHEEL_RADIUS / 2 << ' '; // linear motion
    std::cout << (rightPosition - leftPosition) * WHEEL_RADIUS / AXLE_LENGTH << std::endl; // angle
    
  }
  

  return 0;
}


