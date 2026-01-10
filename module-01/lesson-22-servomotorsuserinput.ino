#include <ESP32Servo.h>
int servoPin = 16;
int servoAngle = 0;
int br = 115200;
int dT = 100;
String prompt = "Which angle do you desire?";
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(prompt);
  while (Serial.available() == 0) {

  }
  servoAngle = Serial.parseInt();
  myServo.write(servoAngle);
  delay(dT);
}
