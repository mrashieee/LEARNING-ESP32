#include <Arduino.h>

const unsigned long eventInterval = 5000;
unsigned long previousTime = 0;
int br = 115200;

void setup() {
  Serial.begin(br);
}

void loop() {
  // Updates millis to current time
  unsigned long currentTime = millis();

  if ( currentTime - previousTime >= eventInterval ) {
    Serial.println("its been 5 seconds");

    previousTime = currentTime;  // when 1000ms or more it changes previous time to current to make it back to giving 1000
  }
}
