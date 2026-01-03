int redPin = 12;
int greenPin = 14;
int bluePin = 27;
int shortT = 300;
int longT = 750;
bool stop = false;
int n;

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!stop) {
    for (n = 0;n < 25;n++) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      delay(shortT);
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(bluePin, LOW);
      delay(shortT);
      digitalWrite(bluePin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      delay(longT);
    }
    digitalWrite(bluePin, LOW);
  }
  stop = true;
}