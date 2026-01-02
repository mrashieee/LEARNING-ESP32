int brdNum = 9600;
int red = 12;
int yellow = 14;
int green = 27;
String myPrompt = "What is your color: ";
String myColor;

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
  if (myColor == "red") {
    Serial.println("red led ON");
    digitalWrite(red, HIGH);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
  else if (myColor == "green") {
    Serial.println("green led ON");
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
  }
  else if (myColor == "yellow") {
    Serial.println("yellow led ON");
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
  }
  else {
    Serial.println("led not available");
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
  }
}
