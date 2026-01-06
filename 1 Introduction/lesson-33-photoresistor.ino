int photoPin = 34;
int dPhotoPin = 0;
int br = 115200;
int dt = 500;
int readPin;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(photoPin, INPUT);
  pinMode(dPhotoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readPin = analogRead(photoPin);
  Serial.println(readPin);
  readPin = digitalRead(dPhotoPin);
  Serial.println(readPin);
  delay(dt);
}
