#include <SoftwareSerial.h>

SoftwareSerial xbee(3, 4); // RX, TX
char temp;
void setup()
{
    Serial.begin(9600);

    Serial.println( "Arduino started receiving bytes via XBee" );

    // Set the data rate for the SoftwareSerial port.
    xbee.begin(9600);
}

void loop()  {
    if (xbee.available()) {
      temp= xbee.read();
      Serial.println(temp);
    }
}
