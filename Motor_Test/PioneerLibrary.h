/*
 by Scott P. Arendt
 Code developed to control the motor control board of Mobile robots Inc - 
 Pioneer 3.  The Motor control board is a ActivMedia Robotics, ELC1587 REB H.
 This ustilizes the J28 connector, a 26 pin ribbon cable connector. The 
 following information was pulled from Appendix A, page 61 of the Pioneer 3 
 operation manual.

Pin - Signal - Description               Pin  - Signal - Description
1     LPWM    Left Motor PWM              2       LDIR    Left Motor Direction
3     RPWM    Right Motor PWM             4       RDIR    Right Motor Direction
5     MEN     Motor Enable                6       LEA     Left Encoder channel A
7     E-STOP  E-Stop detect Input         8       REA     Right Encoder channel A
9     RPWR    Aux1 Power enable           10      REB     Right Encoder Channel B
11    APWR    Aux2 Power enable           12      LEB     Left Encoder Channel B
13    CHRG    Charge port detect          14      IR6     IR input bit 6
15    IR7     IR input Bit 7              16      IR4     IR input bit 4
17    IR5     IR input bit 5              18      IR2     IR input bit 2
19    IR3     IR input bit 3              20      IR0     IR input bit 0
21    IR1     IR input bit 1              22      VBAT    Battery Voltage
23    GND     signal common               24      AN1     Analog input
25    GND     Signal Common               26      AN2     Analog input
 
 This example code is in the public domain.

*/


#ifndef PIONEERLIBRARY
#define PIONEERLIBRARY

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

// List of Arduino pins connected to the Pioneer motorcontroller's pins
#define MOTOR_ENABLE_PIN 8
#define RIGHT_MOTOR_PIN 9
#define LEFT_MOTOR_PIN 10
#define RIGHT_MOTOR_DIRECTION_PIN 11
#define LEFT_MOTOR_DIRECTION_PIN 12

// State machine, to record the current state of the system
enum MOVEMENT_STATE 
{
  STATIONARY, FORWARD, REVERSE, TURN_LEFT, TURN_RIGHT
};

class PioneerLibrary
{
  MOVEMENT_STATE movementState = STATIONARY;        //default value for State machine startup
  unsigned long previousTimeMillis = 0;             //We need to code this for the first pass case where previousTimeMillis is undefined?
  int leftMotorPowerLevel;
  int RightMotorPowerLevel;

  
  public:
    //Constructor
    PioneerLibrary();
   
    //Methods
    void update();
    void straight(int duration);

    private:
    
};

#endif

