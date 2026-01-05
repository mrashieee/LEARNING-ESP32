#include <DHT.h>
#define DHTPIN 16
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

int br = 115200;
int setupDelay = 1000;
int measDelay = 1000;

float tempC;
float tempF;
float hum;
float HIC;
float HIF;

String message;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  dht.begin();
  delay(setupDelay);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempC=dht.readTemperature(false);
  tempF=dht.readTemperature(true);
  hum=dht.readHumidity();
  if(isnan(tempC) || isnan(tempF) || isnan(hum)) {
    Serial.println("Failed to read data on DHT22");
    return;
  }
  HIC=dht.computeHeatIndex(tempC,hum,false);
  HIF=dht.computeHeatIndex(tempF,hum,true);
  message="Temperature is "+String(tempC)+"°C and "+String(tempF)+"°F \nHumidity is "+hum+" %\nHeatIndex is "+String(HIC)+"°C and "+String(HIF)+"°F ";
  Serial.println(message);
  // Serial.print("Temperature is ");
  // Serial.print(tempC);
  // Serial.print("°C and ");
  // Serial.print(tempF);
  // Serial.print("°F \nHumidity is ");
  // Serial.print(hum);
  // Serial.println(" %");
  // Serial.print("HeatIndex: ");
  // Serial.print(HIC);
  // Serial.print("°C and ");
  // Serial.print(HIF);
  // Serial.println("°F");
  delay(measDelay);
}
