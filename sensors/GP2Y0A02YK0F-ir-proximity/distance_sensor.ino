#include <Servo.h>
#define LEFTSERVOPIN  10

#define RIGHTSERVOPIN  9
int LeftMotorForward = 10; // Pin 10 has Left Motor connected on Arduino boards.
int LeftMotorReverse = 12; // Pin 9 has Left Motor connected on Arduino boards.

int RightMotorForward = 9; // Pin 12 has Right Motor connected on Arduino boards.
int RightMotorReverse = 13; // Pin 13 has Right Motor connected on Arduino boards.
int i;
int val;
int redpin=0;

Servo leftServo; 

Servo rightServo; 
 

void setup()
{
  serbSetup();     
  pinMode(LeftMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorForward, OUTPUT);  // initialize the  pin as an output.
  pinMode(LeftMotorReverse, OUTPUT);  // initialize the  pin as an output.
  pinMode(RightMotorReverse, OUTPUT);  // initialize the  pin as an output.
//   leftServo.attach(10);
//   leftServo.write(0);
  pinMode(redpin,OUTPUT);
  
    Serial.begin(9600);
}
void serbSetup(){

  setSpeed(100);

  pinMode(LEFTSERVOPIN, OUTPUT);     //sets the left servo signal pin to output

  pinMode(RIGHTSERVOPIN, OUTPUT);    //sets the right servo signal pin to output

  leftServo.attach(LEFTSERVOPIN);    //attaches left servo

  rightServo.attach(RIGHTSERVOPIN);  //attaches right servo

 

}
// The following Loop is to make the Robot go staright
void loop()

{
      // wait for  10 seconds
   
   
   
   i=analogRead(redpin);
    val=(6762/(i-9))-4;
    
    Serial.println(val);
    delay (100);
//    if(val>100)
//    {
      // Turn Servo Left to 45 degrees
    leftServo.write(90 + 10);

 rightServo.write(90 - 10);
   //delay(10);               // wait for  10 seconds
 //leftServo.write(90);
    //}
  
}
 
