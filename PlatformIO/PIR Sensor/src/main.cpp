#include <Arduino.h>

// Pin connected to the PIR motion sensor output
const int pirPin = 2;

// Variable to store the current motion state (HIGH or LOW)
int motion = 0;

// Variable to store the previous motion state
// Initialized to HIGH so the system doesn’t falsely trigger on startup
int lastMotion = 1;

void setup() {
  // Start serial communication so we can print messages to the Serial Monitor
  Serial.begin(115200);

  // Set the PIR sensor pin as an input
  pinMode(pirPin, INPUT);
}

void loop() {
  // Read the current state of the PIR sensor
  // HIGH means motion detected, LOW means no motion
  motion = digitalRead(pirPin);

  // Check for a LOW → HIGH transition
  // This means motion has just started
  if (lastMotion == LOW && motion == HIGH) {
    Serial.println("Motion Detected!!!");
  }

  // Check for a HIGH → LOW transition
  // This means motion has stopped and the area is clear
  if (lastMotion == HIGH && motion == LOW) {
    Serial.println("Area clear.");
  }

  // Store the current motion state as the previous state
  // This allows us to detect changes on the next loop iteration
  lastMotion = motion;
}