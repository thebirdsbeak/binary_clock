/* 
Binary Clock program based on the DS323 library

Beerware by Craig McIntyre (thebirdsbeak.com)

With grateful thanks to those responsible for the DS3231.h library.
*/

unsigned long previousMillis = 0;
const long interval = 50;

#include <Wire.h>
#include "DS3231.h"
RTClib RTC;
DS3231 Clock;

byte hr;
byte mn;

// byte set_hour = 05; // Uncomment to set time
// byte set_min = 34; // Uncomment to set time

const byte numMinPins = 6;
const byte numHrPins = 4;
byte minPins[] = {4, 5, 7, 8, 12, 13};
byte hrPins[] = {6, 9, 10, 11};

void setup() {

    Serial.begin(57600); // Uncomment for debugging
    Wire.begin();

  for (int thisPin = 0; thisPin < numMinPins; thisPin++) {
    pinMode(minPins[thisPin], OUTPUT);
  }

  for (int thisPin = 0; thisPin < numHrPins; thisPin++) {
    pinMode(hrPins[thisPin], OUTPUT);
  }

//    Clock.setClockMode(true);  // set to 12h time (not 24h)
//    Clock.setHour(set_hour); // Uncomment to set hour
//    Clock.setMinute(set_min); //Uncomment to set minute
  
}




void loop() {

    DateTime now = RTC.now();
    hr = now.hour(), DEC;
    mn = now.minute(), DEC;

    Serial.print(hr); // Uncomment for debugging
    Serial.print(":"); // Uncomment for debugging
    Serial.println(mn); // Uncomment for debugging

 
  for (byte i=0; i<numMinPins; i++) {
    byte state = bitRead(mn, i);
    digitalWrite(minPins[i], state);
  }

delay(1000);
  for (byte i=0; i<numHrPins; i++) {
        byte state = bitRead(hr, i);
        if (state == 1) {
  for (int fadeValue = 0 ; fadeValue <= 250; fadeValue += 5) {
    analogWrite(hrPins[i], fadeValue);
    delay(20);
  }
  }
  }

  for (byte i=0; i<numHrPins; i++) {
            byte state = bitRead(hr, i);
        if (state == 1) {
  for (int fadeValue = 250 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(hrPins[i], fadeValue);
    delay(20);
  }
  }
  }
}
