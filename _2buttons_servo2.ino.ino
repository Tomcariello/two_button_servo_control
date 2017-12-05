/* 2 Button Servo Control
 * ----------------------
 *
 * Rotate a 180 degree Servo motor connected to digital pin 10 counterclockwise 
 * when pressing  a pushbutton attached to pin 4 and clockwise when pressing a 
 * pushbutton connected to pin 2.  
 * 
 * In my setup, this requires 4 AA batteries to power the Servo & USB connection 
 * to power the Arduino Uno board.
 */

#include <Servo.h>
Servo servoMain; // Define our Servo

// set input pins for  pushbuttons
int inPinCounter = 4;        
int inPinClockwise = 3;

//Set vars to 0
int ValinPinCounter = 0;
int ValinPinClockwise = 0;

void setup() {
  Serial.begin(9600);

  // declare pushbuttons as inputs
  pinMode(inPinCounter, INPUT_PULLUP);       
  pinMode(inPinClockwise, INPUT_PULLUP);
  
  // attach servo on digital pin 10
  servoMain.attach(10);                   

  // Return Servo to center position on initial load
  servoMain.write(90);                   
}

void loop(){
  ValinPinCounter = digitalRead(inPinCounter);
  ValinPinClockwise = digitalRead(inPinClockwise);
  
  if (ValinPinClockwise == LOW) {
   //Rotate Clockwise
   servoMain.write(0);               // Turn Servo to 0 degrees
   delay(1000);
   servoMain.write(90);              // Return Servo to 90 degrees
   //delay(1000);
  
 } else if (ValinPinCounter == LOW) {
   //Rotate Counter-Clockwise
   servoMain.write(180);             // Turn Servo to 180 degrees
   delay(1000);
   servoMain.write(90);               // Return Servo to 0
   delay(1000);
    
  } else {
   delay(1000);          // Wait 1 second   
  }
}
