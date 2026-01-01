int potPin = 12;
int potVal;
int bcmd = 9600;
int waitTime = 300;
int ledPin = 33;
float volts;
float ledVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(bcmd);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  volts = potVal*3.3/4095;
  ledVal = pow(2, potVal/511.875)-1;  // power
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print(" Voltage: ");
  Serial.print(volts);
  Serial.print(" Led Input: ");
  Serial.println(ledVal);
  analogWrite(ledPin, ledVal);
  delay(waitTime);
}
