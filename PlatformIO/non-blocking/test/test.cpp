#include <Adafruit_NeoPixel.h>

int ledPin = 38;

Adafruit_NeoPixel led(1,ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(115200);
    delay(100);
    Serial.println("Neo Demo");

    led.begin();
    led.setBrightness(50);
    led.clear();
    led.show();

}

void loop() {
    led.setPixelColor(0, led.Color(255,0,0));
    led.show();
}