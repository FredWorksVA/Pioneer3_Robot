/* Motor_Test

 by Scott P. Arendt
 Code developed to control the motor control board of Mobile robots Inc - 
 Pioneer 3.  

*/


#include "PioneerLibrary.h"
PioneerLibrary pioneerLibrary = PioneerLibrary();

volatile int count_1 = 0;           //Variable to keep track of encoder pulses on encoder 1
volatile int count_2 = 0;           //Variable to keep track of encoder pulses on encoder 2

void setup() 
{
 pinMode (2, INPUT);    //test code to read motor encoder 1 channel A
 pinMode (3, INPUT);    //test code to read motor encoder 2 channel A


 attachInterrupt(0, encoder_ISR_L, RISING);
 attachInterrupt(1, encoder_ISR_R, RISING);
 Serial.begin(9600);
}


void loop() 
{
//  delay(2000);

//  pioneerLibrary.straight(5000);            //Motors straight for 5 seconds
  pioneerLibrary.update();

  delay(1000);
    Serial.print("L: ");
    Serial.println(count_1);
    Serial.print("R: ");
    Serial.println(count_2);  
}

void encoder_ISR_L()
{
  count_1 += 1;
}


void encoder_ISR_R()
{
  count_2 += 1;
}




