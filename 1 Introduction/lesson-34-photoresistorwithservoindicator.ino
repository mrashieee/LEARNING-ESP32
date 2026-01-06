#include <ESP32Servo.h>
int ServoPin = 32;
int photoPin = 34;
int br = 115200;
int dt = 500;
int servoAngle;
int readPin;
Servo dnCheck;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(photoPin, INPUT);
  dnCheck.attach(ServoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  readPin = analogRead(photoPin);
  Serial.println(readPin);
  servoAngle = ((readPin - 32) * 180 + 4031 / 2) / 4031;
  dnCheck.write(servoAngle);
  delay(dt);
}
