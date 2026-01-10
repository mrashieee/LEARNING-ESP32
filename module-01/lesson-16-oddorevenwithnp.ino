int brdNum = 9600;
String myPrompt = "What is your number: ";
int myNum;
int rem;

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
  rem = myNum % 2;
  if (myNum > 0 && rem == 0) {
    Serial.println("You have a Positive Even Number!");
  }
  if (myNum < 0 && rem == 0) {
    Serial.println("You have a Negative Even Number!");
  }
  if (myNum > 0 && rem != 0) {
    Serial.println("You have a Positive Odd Number!");
  }
  if (myNum < 0 && rem != 0) {
    Serial.println("You have a Negative Odd Number!");
  }
  if (myNum == 0) {
    Serial.println("You have a Zero number!");
  }
}
