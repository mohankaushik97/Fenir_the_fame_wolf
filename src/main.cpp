#include <Arduino.h>
#include <Servo.h>


#define eye1In A0
#define eye2In A1
#define earIn A2
#define jawIn A3



Servo earOut,eye1Out,eye2Out,jawOut;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int earVal, eye1Val, eye2Val, jawVal; 

int earPositionX = 0;
int eyePositionX = 0;
int eyePositionY = 0;
int jawPosition = 0;


void setup() {
  Serial.begin(9600);

  pinMode(earIn,INPUT);
  pinMode(eye1In,INPUT);
  pinMode(eye2In,INPUT);
  pinMode(jawIn,INPUT);
  
 
  eye1Out.attach(3);
  eye2Out.attach(5);
  earOut.attach(6);// attaches the servo on pin 9 to the servo object
  jawOut.attach(9);  
}


void loop() {
  earVal = analogRead(earIn);            // reads the value of the potentiometer (value between 0 and 1023)
  eye1Val = analogRead(eye1In);
  eye2Val = analogRead(eye2In);
  jawVal = analogRead(jawIn);  
  
  earVal = map(earVal, 430, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  eye1Val = map(eye1Val, 0, 1023, 0, 180);
  eye2Val = map(eye2Val, 0, 1023, 0, 180);
  jawVal = map(jawVal,0,1023,0,180);
  // Serial.print("Eye 1: "); Serial.println(eye1Val);
  // Serial.print("Eye 2: "); Serial.println(eye2Val);
  // Serial.print("Eye 1: "); Serial.println(eye1Val);
  
  earOut.write(earVal);
  eye1Out.write(eye1Val);                  // sets the servo position according to the scaled value
  eye2Out.write(eye2Val);
  jawOut.write(jawVal);
  delay(15);                           // waits for the servo to get there
}

