#include <Arduino.h>

// put function declarations here:
int hardwareClock; // Using int works only temporarily and will fail after ~24.8 days
int br = 115200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  hardwareClock = millis(); // storing in int will cause overflow and cause negative values
  Serial.println(hardwareClock);
}