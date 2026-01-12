#include <DHT.h>          // Include library for DHT temperature/humidity sensor

int photoPin = 34;        // Analog pin connected to the LDR (photoresistor)
int DHTPin = 5;           // Digital pin connected to the DHT22 sensor
int br = 115200;          // Baud rate for serial communication

#define DHTTYPE DHT22     // Specify the type of DHT sensor used (DHT22)
DHT dht(DHTPin, DHTTYPE); // Create DHT sensor object

// Time intervals (in milliseconds)
unsigned long eventDHT = 5000;  // Read DHT sensor every 5 seconds
unsigned long eventLDR = 1000;  // Read LDR every 1 second

// Variables to store the last time each sensor was read
unsigned long previousTDHT = 0;
unsigned long previousTLDR = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(br);

  // Initialize the DHT sensor
  dht.begin();

  // Set LDR pin as input
  pinMode(photoPin, INPUT);
}

void loop() {
  // Get the current time since the board started (in milliseconds)
  unsigned long currentTime = millis();

  // Check if it's time to read the LDR
  if (currentTime - previousTLDR >= eventLDR) {
    Serial.print("LDR: ");
    Serial.println(analogRead(photoPin)); // Read and print LDR value

    // Update last LDR read time
    previousTLDR = currentTime;
  }

  // Check if it's time to read the DHT sensor
  if (currentTime - previousTDHT >= eventDHT) {
    Serial.print("DHT: ");
    Serial.println(dht.readTemperature(false)); // Read temperature in Celsius

    // Update last DHT read time
    previousTDHT = currentTime;
  }
}
