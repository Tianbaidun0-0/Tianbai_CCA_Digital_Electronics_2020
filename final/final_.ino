

//add the servo libary
#include <Servo.h>

//define our servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
//define joystick pins (Analog)
int joyX = 2;
int joyY = 3;
int joyXX = 0;
int joyYY = 1;

//variable to read the values from the analog pins 
int joyVal;
void setup ()
{
  //attaches our servos on pins PWM 3-5
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(5);
  
}

void loop ()
{
  //read the value of joystick (betwen 0-1023)
  joyVal = analogRead(joyX);
  joyVal = map(joyVal, 0, 1023, 0, 180); //servo value betven 0-180
  servo1.write(joyVal); //set the servo position acording to the joystick value

  joyVal = analogRead(joyY);
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo2.write(joyVal);
  delay(15);
   //read the value of joystick (betwen 0-1023)
  joyVal = analogRead(joyXX);
  joyVal = map(joyVal, 0, 1023, 0, 180); //servo value betven 0-180
  servo4.write(joyVal); //set the servo position acording to the joystick value

  joyVal = analogRead(joyYY);
  joyVal = map (joyVal, 0, 1023, 0, 180);
  servo3.write(joyVal);
  delay(15);
  
}
