int chatInt;
float chatFloat;
String myName;
int br = 9600;
int waitT = 5000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
}

void clearSerial() {
  while (Serial.available()) {
    Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What is your age?");
  while (Serial.available() == 0) {

  }
  chatInt = Serial.parseInt();
  clearSerial();
  Serial.print("Your age is ");
  Serial.println(chatInt);

  Serial.println("What is your float number?");
  while (Serial.available() == 0) {

  }
  chatFloat = Serial.parseFloat();
  clearSerial();
  Serial.print("Your float is ");
  Serial.println(chatFloat);

  Serial.println("What is your name? ");
  while (Serial.available() == 0) {

  }
  myName = Serial.readStringUntil('\n');
  Serial.print("Your name is ");
  Serial.println(myName);
  Serial.print("Welcome, ");
  Serial.print(myName);
  Serial.println(" to ESP32!");

  delay(waitT);
}