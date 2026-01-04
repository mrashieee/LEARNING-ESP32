#include <ESP32Servo.h>
int servoPin = 16;
int servoAngle = 0;
int dT = 100;
int i;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i=0;i<=180;i=i+1) {
    myServo.write(i);
    delay(dT);
  }
  for (i=180;i>=0;i=i-1) {
    myServo.write(i);
    delay(dT);
  }
}
