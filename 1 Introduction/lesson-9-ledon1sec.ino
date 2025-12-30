int ledPin = 12;
int coolOff = 1000;
String ledOn = "LED is ON";
String ledOff = "LED is OFF";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  Serial.println(ledOn);
  delay(coolOff);
  digitalWrite(ledPin, LOW);
  Serial.println(ledOff);
  delay(coolOff);
}
