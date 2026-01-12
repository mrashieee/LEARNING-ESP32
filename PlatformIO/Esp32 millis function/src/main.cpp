#include <Arduino.h>

// put function declarations here:
unsigned long hardwareClock;
int br = 115200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  hardwareClock = millis();
  Serial.println(hardwareClock);
}