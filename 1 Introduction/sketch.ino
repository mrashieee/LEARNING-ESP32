
#define LED 12  // 12 is the pin the + of LED connected( - is on GRD(Ground))

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);  // pinMode takes (pin number, mode) to use the esp32 pin
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite used for OUTPUT mode devices 
  // LOW = 0V
  // HIGH = 3.3V
  digitalWrite(LED,LOW);
  delay(300);     // How long the LED will be ON
  digitalWrite(LED,HIGH);
  delay(300);    //  How long the LED will be OFF
}
