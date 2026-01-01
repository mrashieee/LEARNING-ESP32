int brdNum = 9600;
String myPrompt = "What is your number: ";
int myNum;

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
  myNum = Serial.parseInt();
  clearSerial();
  if (myNum > 0) {
    Serial.println("Positive");
  }
  else if (myNum < 0) {
    Serial.println("Negative");
  }
  else {
    Serial.println("Zero");
  }
}
