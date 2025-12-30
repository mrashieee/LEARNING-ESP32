int ledPin = 12;
int brightness = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  analogWrite(ledPin, brightness);
}
