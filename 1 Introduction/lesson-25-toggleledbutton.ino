int redLed = 16;
int butPin = 2;
int br = 115200;
int ledState = 0;
int delayT = 50;
int butVal;
int butOldVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(butPin, INPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  if (butOldVal == 0  &&  butVal == 1) {
    if (ledState == 0) {
      digitalWrite(redLed, HIGH);
    }
    if (ledState == 1) {
      digitalWrite(redLed,LOW);
    }
    ledState = !ledState;
  }
  butOldVal = butVal;
  delay(delayT);
}
