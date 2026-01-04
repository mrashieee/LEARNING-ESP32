int redLed = 16;
int butPin = 2;
int butVal;
int br = 115200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(butPin, INPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  if (butVal == 0) {
    digitalWrite(redLed, HIGH);
  }
  else {
    digitalWrite(redLed, LOW);
  }
}
