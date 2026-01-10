int potPin = 4;
int ledPin = 5;
int br = 9600;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potVal;
  int brightVal;
  
  potVal = readPot(potPin);
  brightVal = findBright(potVal);
  setLed(ledPin,brightVal);
}

int readPot(int potPin) {
  int readVal;
  readVal = analogRead(potPin);
  return readVal;
}

int findBright(int pv) {
  int bv;
  bv=pow(2, pv/511.875)-1;
  return bv;
}

void setLed(int lp,int bv) {
  analogWrite(lp, bv);
}