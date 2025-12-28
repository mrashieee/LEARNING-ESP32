
#define LED 12  // 12 is the pin the + of LED connected( - is on GRD(Ground))

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED,LOW);
  delay(300);     // How long the LED will be ON
  digitalWrite(LED,HIGH);
  delay(300);    //  How long the LED will be OFF
}
