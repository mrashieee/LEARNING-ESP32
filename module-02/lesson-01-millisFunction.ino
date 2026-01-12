#include <Arduino.h>

// put function declarations here:
unsigned long hardwareClock;  // unsigned long has the digits from 0 - 4,294,967,295
int br = 115200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  hardwareClock = millis();  // millis() counts time in milliseconds since startup unsigned long allows correct handling of the overflow
  Serial.println(hardwareClock);
}