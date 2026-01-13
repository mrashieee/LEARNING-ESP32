#include <Arduino.h>

// ============================================================================
// Pin Definitions
// ============================================================================
int blinkLedPin = 5;      // LED that blinks on and off
int fadeLedPin = 18;       // LED that fades up and down (PWM capable pin)
int buttonLedPin = 12;     // LED controlled by the button
int buttonPin = 39;        // Button input pin

// ============================================================================
// Timing Configuration
// ============================================================================
int blinkDelay = 500;     // Delay between blink states (in milliseconds)
int fadeDelay = 10;       // Delay between fade steps (in milliseconds)
int fadeStep = 5;         // Amount to change brightness each step

// ============================================================================
// State Variables
// ============================================================================
int fadeValue = 0;        // Current brightness of the fade LED (0-255)
int fadeDirection = 1;    // 1 = fading up, -1 = fading down

// ============================================================================
// Function Prototypes
// ============================================================================
void blinkLed();
void fadeLed();
void buttonLed();

// ============================================================================
// setup()
// ============================================================================
void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Set LED pins as outputs
  pinMode(blinkLedPin, OUTPUT);
  pinMode(fadeLedPin, OUTPUT);
  pinMode(buttonLedPin, OUTPUT);

  // Set button pin as input with internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.println("Starting LED demo...");
}

// ============================================================================
// loop()
// ============================================================================
void loop() {
  // Blink the first LED
  blinkLed();

  // Fade the second LED
  fadeLed();

  // Control the third LED with the button
  buttonLed();
}

// ============================================================================
// blinkLed() - Toggles the blink LED on and off
// ============================================================================
void blinkLed() {
  digitalWrite(blinkLedPin, HIGH);  // Turn LED on
  delay(blinkDelay);                // Wait
  digitalWrite(blinkLedPin, LOW);   // Turn LED off
  delay(blinkDelay);                // Wait
}

// ============================================================================
// fadeLed() - Fades the LED up and down using PWM
// ============================================================================
void fadeLed() {
  // Set the LED brightness
  analogWrite(fadeLedPin, fadeValue);

  // Update the fade value
  fadeValue += fadeDirection * fadeStep;

  // Reverse direction at the limits
  if (fadeValue >= 255) {
    fadeValue = 255;
    fadeDirection = -1;
  } else if (fadeValue <= 0) {
    fadeValue = 0;
    fadeDirection = 1;
  }

  delay(fadeDelay);
}

// ============================================================================
// buttonLed() - Turns LED on when button is pressed
// ============================================================================
void buttonLed() {
  // Read the button state (LOW when pressed due to INPUT_PULLUP)
  int buttonState = digitalRead(buttonPin);

  // Turn LED on if button is pressed, off otherwise
  if (buttonState == LOW) {
    digitalWrite(buttonLedPin, HIGH);
  } else {
    digitalWrite(buttonLedPin, LOW);
  }
}