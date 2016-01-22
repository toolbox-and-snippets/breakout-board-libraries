
#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial xbee(2, 3); // RX, TX
char c = 'A';
int  pingPong = 1;
int sensorAddress = 0x91 >> 1;  // From datasheet sensor address is 0x91
                                // shift the address 1 bit right, the Wire library only needs the 7
                                // most significant bits for the address
byte msb;
byte lsb;
int temperature;


void setup()  {
   Serial.begin(9600);
   Wire.begin();
   Serial.println( "Arduino started sending bytes via XBee" );

   // set the data rate for the SoftwareSerial port
   xbee.begin( 9600 );
}

void loop()  {
  
  
  Wire.requestFrom(sensorAddress,2); 
  if (2 <= Wire.available())  // if two bytes were received 
  {
    msb = Wire.read();  // receive high byte (full degrees)
    lsb = Wire.read();  // receive low byte (fraction degrees) 
    temperature = ((msb) << 4);  // MSB
    temperature |= (lsb >> 4);   // LSB
    Serial.print("Temperature: ");
    xbee.print( temperature*0.0625 );
    xbee.print( '\t');
    Serial.println(temperature*0.0625);
  }
  delay(500);  // wait for half a s
  
  
  
  
  // send character via XBee to other XBee connected to Mac
  // via USB cable
  
 
  //--- display the character just sent on console ---
  Serial.println( c );
 
  //--- get the next letter in the alphabet, and reset to ---
  //--- 'A' once we have reached 'Z'.
  c = c + 1;
  if ( c>'Z' )
       c = 'A';
 
  //--- switch LED on Arduino board every character sent---
  if ( pingPong == 0 )
      digitalWrite(13, LOW);
  else
    digitalWrite(13, HIGH);
  pingPong = 1 - pingPong;
  delay( 1000 );
}
