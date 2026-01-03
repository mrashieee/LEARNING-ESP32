int redPin = 12;
int greenPin = 14;
int bluePin = 27;
int brdRate = 115200;
String questionColor = "Which color do you want?";
String invalidColor = "Please enter a valid colour in the system!";
String ledInd = "Led Color is ";
String userColor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(brdRate);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void clearSerial() {
  while (Serial.available()) {
    Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(questionColor);
  while (Serial.available() == 0) {

  }
  userColor = Serial.readStringUntil('\n');
  clearSerial();
  userColor.toLowerCase();
  if (userColor == "red") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
  else if (userColor == "green") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  else if (userColor == "blue") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else if (userColor == "orange") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 15);
    analogWrite(bluePin, 0);
  }
  else if (userColor == "cyan") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  else if (userColor == "magenta") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
  }
  else if (userColor == "yellow") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
  }
  else if (userColor == "white") {
    Serial.print(ledInd);
    userColor.toUpperCase();
    Serial.println(userColor);
    analogWrite(redPin, 255);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 255);
  }
  else {
    Serial.println(invalidColor);
  }
}