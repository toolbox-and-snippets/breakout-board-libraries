#include <DistanceGP2Y0A21YK.h>
#include <SoftwareSerial.h>

SoftwareSerial xbee(7, 6); // RX, TX
DistanceGP2Y0A21YK Dist;
DistanceGP2Y0A21YK Dist2;

int distance;
int distance2;

void setup()
{
  Serial.begin(9600);
  Dist.begin(A0);
  Dist2.begin(A1);
  xbee.begin( 9600 );
}

void loop()
{
  distance = Dist.getDistanceCentimeter();
  distance2 = Dist2.getDistanceCentimeter();
  
  Serial.println("\nDistance in centimers from 1: ");
  Serial.print(distance);  
  Serial.println("\nDistance in centimers from 2: ");
  Serial.print(distance2);  
  
  /*Begin sending to xbee*/
  
  xbee.println("\nDistance in centimers from 1: ");
  xbee.print(distance);  
  xbee.println("\nDistance in centimers from 2: ");
  xbee.print(distance2);   
  
  /*End sending to xbee*/
   
  delay(500); //make it readable
}
