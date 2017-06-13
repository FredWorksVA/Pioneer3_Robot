#include "PioneerLibrary.h"

PioneerLibrary::PioneerLibrary() 
{
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);                                 // MOTOR ENABLE - HIGH = OFF, LOW = ON
  
  pinMode(RIGHT_MOTOR_PIN, OUTPUT);                                 //RIGHT motor PWM
  pinMode(LEFT_MOTOR_PIN, OUTPUT);                                // LEFT Motor PWM
  
  pinMode(RIGHT_MOTOR_DIRECTION_PIN, OUTPUT);                                //RIGHT motor direction
  pinMode(LEFT_MOTOR_DIRECTION_PIN, OUTPUT);                                // LEFT Motor direction
  
  pinMode(13, OUTPUT);                                //Debug LED on arduino board

  unsigned long currentMillis = millis();             //set up time variable
}

void PioneerLibrary::update() 
{
  unsigned long currentTimeMillis = millis(); 
  unsigned long deltaTimeMillis = currentTimeMillis - previousTimeMillis;     
  previousTimeMillis = currentTimeMillis;                 
  if (movementState == FORWARD)
  {
    
  }
  else if (movementState == REVERSE)
  {
    
  }
  else if (movementState == TURN_LEFT)
  {
    
  }
  else if (movementState == TURN_RIGHT)
  {
    
  }
  else if (movementState == STATIONARY)
  {
    
  }
}

//Function to drive the robot straight
void PioneerLibrary::straight(int duration)
{
  //  This method enables the motors, ramps up to full speed, runs for duration (minus ramp time of 500 x2) and then ramps 
  //  down the motors to zero, then disables them.

  duration -= 1000;                                 //Ramp time is approx = 500 miliseconds, x2 for both ramp up and ramp down
  if (duration < 0) duration = 0;                   //Set duration to zero if less than zero
   
  analogWrite(LEFT_MOTOR_PIN, 0);                               //Motor speed to zero to ensure smooth start
  analogWrite(RIGHT_MOTOR_PIN, 0);                                //Motor speed to zero to ensure smooth start
  digitalWrite(MOTOR_ENABLE_PIN, LOW);                             //Motor Enable, HIGH = OFF
  digitalWrite(RIGHT_MOTOR_DIRECTION_PIN, HIGH);                           //Left Motor Direction Forward
  digitalWrite(LEFT_MOTOR_DIRECTION_PIN, LOW);                            //Right Motor Direction Forward
  
  for (int pos = 0; pos <= 255; pos += 5)           // goes from 0 (zero power) to 255 (full power)
  {
    analogWrite(LEFT_MOTOR_PIN, pos);
    analogWrite(RIGHT_MOTOR_PIN, pos);
    delay(10);                                      // waits 15ms for the servo to reach the position
  }
  
  delay(duration);

  for (int pos = 255; pos >= 0; pos -= 5)           // goes from 255 (full power) to 0 (zero power)
  {
    analogWrite(LEFT_MOTOR_PIN, pos);
    analogWrite(RIGHT_MOTOR_PIN, pos);
    delay(10);                                     // waits 15ms for the servo to reach the position
  }

  digitalWrite(MOTOR_ENABLE_PIN, HIGH);                            //Motor Enable, HIGH = OFF
}

