int ledPin = 12;
int brightness = 0;
int fadeTime = 100;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  brightness = 1;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 2;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 4;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 8;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 16;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 32;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 64;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 128;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 255;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 128;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 64;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 32;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 16;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 8;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 4;
  analogWrite(ledPin, brightness);
  delay(fadeTime);

  brightness = 2;
  analogWrite(ledPin, brightness);
  delay(fadeTime);
}
