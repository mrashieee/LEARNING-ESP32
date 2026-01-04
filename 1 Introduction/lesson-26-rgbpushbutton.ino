int redLed = 27;
int greenLed = 26;
int blueLed = 25;
int rButPin = 2;
int gButPin = 0;
int bButPin = 4;
int rLedState = 1;
int gLedState = 1;
int bLedState = 1;
int br = 115200;
int delayT = 50;
int rButVal;
int gButVal;
int bButVal;
int rOldVal;
int gOldVal;
int bOldVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(rButPin, INPUT);
  pinMode(gButPin, INPUT);
  pinMode(bButPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  rButVal = digitalRead(rButPin);
  gButVal = digitalRead(gButPin);
  bButVal = digitalRead(bButPin);
  if (rOldVal == 0  &&  rButVal == 1) {
    if (rLedState == 0) {
      digitalWrite(redLed, HIGH);
    }
    if (rLedState == 1) {
      digitalWrite(redLed,LOW);
    }
    rLedState = !rLedState;
  }
  if (gOldVal == 0  &&  gButVal == 1) {
    if (gLedState == 0) {
      digitalWrite(greenLed, HIGH);
    }
    if (gLedState == 1) {
      digitalWrite(greenLed,LOW);
    }
    gLedState = !gLedState;
  }
  gOldVal = gButVal;
  if (bOldVal == 0  &&  bButVal == 1) {
    if (bLedState == 0) {
      digitalWrite(blueLed, HIGH);
    }
    if (bLedState == 1) {
      digitalWrite(blueLed,LOW);
    }
    bLedState = !bLedState;
  }
  rOldVal = rButVal;
  gOldVal = gButVal;
  bOldVal = bButVal;
  delay(delayT);
}
