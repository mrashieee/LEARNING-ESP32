#include <Arduino.h>

// never changing constant value
const int butPin = 4;
const int ledPin = 2;

// volatile will only change the value if hardware changes it
// and prevents compiler optimization issues
volatile bool toggleState = false;


//  function for checking if the switch worked then this function will work
void checkSwitch() {
  if (digitalRead(butPin) == LOW) {
    toggleState = !toggleState;
    digitalWrite(ledPin, toggleState);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(butPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  // interrupt attached and using butPin as digital pin interrupt, 
  // Check switch to use that fuction when used, 
  // FALLING is to use interrupt when the button falls from HIGH to LOW
  attachInterrupt(digitalPinToInterrupt(butPin),checkSwitch,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10000); // dummy delay
}
