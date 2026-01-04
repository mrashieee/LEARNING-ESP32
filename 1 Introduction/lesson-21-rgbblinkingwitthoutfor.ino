int redPin = 12;
int greenPin = 14;
int bluePin = 27;
int shortT = 300;
int longT = 750;
int bdRt = 115200;
String askUser = "How many times do you want your RGB LED to blink?";
int cycle;
int n;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(bdRt);
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
  Serial.println(askUser);
  while (Serial.available() == 0) {

  }
  cycle = Serial.parseInt();
  clearSerial();
  Serial.print("Blinking LED ");
  Serial.print(cycle);
  Serial.println(" times.");
  n = 1;
  while (n <= cycle) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(shortT);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(shortT);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    analogWrite(bluePin, 0);
    delay(shortT);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(shortT);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 255);
    delay(shortT);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(longT);
    n = n + 1;
  }
}