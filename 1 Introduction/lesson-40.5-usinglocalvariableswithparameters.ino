void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float length;
  float width;
  float area;
  float parameter;
  float diagonal;
  Serial.println("Input length of rectangle: ");
  while (Serial.available() == 0) {

  }
  length = Serial.parseFloat();
  clearSerial();
  Serial.println("Input width of rectangle: ");
  while(Serial.available() == 0) {

  }
  width = Serial.parseFloat();
  clearSerial();
  findArea(length,width,area);
  Serial.println("Your area of reactangle is: "+String(area));
  findParameter(length,width,parameter);
  Serial.println("Your parammeter of rectangle is: "+String(parameter));
  findDiagonal(length,width,diagonal);
  Serial.println("Your diagonal of rectangle is: "+String(diagonal));
  Serial.println();
}

void clearSerial() {
  while(Serial.available()) {
    Serial.read();
  }
}

void findArea(float l,float w,float &a) {
  a = l*w;
}

void findParameter(float l,float w,float &p) {
  p = 2*l + 2*w;
}

void findDiagonal(float l,float w,float &d) {
  d = sqrt(l*l+w*w);
}