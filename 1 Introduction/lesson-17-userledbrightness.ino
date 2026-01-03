int brdNum = 9600;
int red = 12;
int yellow = 14;
int green = 27;
String myPrompt = "What color you want? ";
String myQuest = "What brightness for the led?(0-100) ";
String myColor;
int myBright;
int brightOFF = 0;
int brightness;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(brdNum);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void clearSerial() {
  while (Serial.available()) {
    Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(myPrompt);
  while (Serial.available() == 0) {

  }
  myColor = Serial.readStringUntil('\n');
  myColor.toLowerCase();
  clearSerial();

  Serial.println(myQuest);
  while (Serial.available() == 0) {

  }
  myBright = Serial.parseInt();
  clearSerial();
  brightness = myBright*255/100;
  if (myColor == "red") {
    Serial.println("red led ON");
    analogWrite(red, brightness);
    analogWrite(yellow, brightOFF);
    analogWrite(green, brightOFF);
  }
  else if (myColor == "green") {
    Serial.println("green led ON");
    analogWrite(green, brightness);
    analogWrite(red, brightOFF);
    analogWrite(yellow, brightOFF);
  }
  else if (myColor == "yellow") {
    Serial.println("yellow led ON");
    analogWrite(yellow, brightness);
    analogWrite(red, brightOFF);
    analogWrite(green, brightOFF);
  }
  else {
    Serial.println("led not available");
    analogWrite(red, brightOFF);
    analogWrite(yellow, brightOFF);
    analogWrite(green, brightOFF);
  }
}
