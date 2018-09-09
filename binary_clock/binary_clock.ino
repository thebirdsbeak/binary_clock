
const byte numMinPins = 6;
const byte numHrPins = 4;
byte minPins[] = {4, 5, 6, 7, 8, 9};
byte hrPins[] = {10, 11, 12, 13};
void setup() {

  for (int thisPin = 0; thisPin < numMinPins; thisPin++) {
    pinMode(minPins[thisPin], OUTPUT);
  }

  for (int thisPin = 0; thisPin < numHrPins; thisPin++) {
    pinMode(hrPins[thisPin], OUTPUT);
  }

  
}

void loop() {

  

  
  byte num = 12;
  for (byte i=0; i<numPins; i++) {
    byte state = bitRead(num, i);
    digitalWrite(pins[i], state);
  }
}

