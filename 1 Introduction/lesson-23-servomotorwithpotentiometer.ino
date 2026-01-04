#include <ESP32Servo.h>
int servoPin = 16;
int potPin = 15;
int servoAngle = 0;
int br = 115200;
int dt = 50;
float userAngle;
float potInput;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  myServo.attach(servoPin);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potInput = analogRead(potPin);
  userAngle = potInput*180.0/4095;
  myServo.write(userAngle);
  delay(dt);
}
