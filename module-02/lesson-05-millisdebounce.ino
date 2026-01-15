#include <Arduino.h>

int butPin = 12;

byte lastButtonState;

unsigned long lastTimeButtonStateChanged = millis();
unsigned long debounceDuration = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(butPin, INPUT);
  lastButtonState = digitalRead(butPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - lastTimeButtonStateChanged >= debounceDuration) {
    byte buttonState = digitalRead(butPin);
    if (buttonState != lastButtonState) {
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if (buttonState == LOW) {
        Serial.println("Button has been released");
      }
    }
  }
}
