int redPin = 12;
int greenPin = 14;
int bluePin = 27;
int shortT = 300;
int longT = 750;
int brdRt = 115200;
String askUser = "How many times do you want your RGB LED to blink?";
int n;
int cycle;
bool done;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
  for (n = 1;n <= cycle;n++) {
    analogWrite(redPin, 255);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
    delay(shortT);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
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
  }
  done = true;
  while (done = true) {}
}