int brdNum = 9600;
String myPrompt = "What is your color: ";
String myColor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(brdNum);
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
  if (myColor == "red") {
    Serial.println("RED ALERT!!!");
  }
  if (myColor != "red") {
    Serial.print("Your color is: ");
    Serial.println(myColor);
  }
}
