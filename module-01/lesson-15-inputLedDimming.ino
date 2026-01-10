int boardSerial = 9600;
int ledPin = 12;
String prompt = "How much brightness you want(0-100%)?";
String equalTo = " = ";
char perc = '%';
int brightness;
int input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(boardSerial);
  pinMode(ledPin, OUTPUT);
}

void clearSerial() {
  while (Serial.available()) {
    Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(prompt);
  while (Serial.available() == 0) {}
  input = Serial.parseInt();
  // brightness = pow(2,(8.0/100)*input)-1;          // Way-1 can't be done with 100 cause light doesn't light up until input is 16
  // brightness = constrain(brightness,1,255);      // Constrain will make any input be inside 1-255
  brightness = input*255/100;                      //  Way-2  works the best
  clearSerial();
  Serial.print(input);
  Serial.print(perc);
  Serial.print(equalTo);
  Serial.println(brightness);
  analogWrite(ledPin, brightness);
}
