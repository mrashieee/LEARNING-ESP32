/*
 * ============================================================================
 * NON-BLOCKING LED EXERCISE
 * ============================================================================
 * 
 * CURRENT BEHAVIOR:
 * This sketch controls three LEDs and a button. However, it uses delay()
 * which blocks the processor and causes poor responsiveness.
 * 
 * YOUR TASK:
 * 1. Convert ALL delay() calls to non-blocking timing using millis()
 *    - Track elapsed time with variables instead of blocking
 *    - Each LED should operate independently without affecting the others
 * 
 * 2. Add debouncing to the button and a hardware interrupt
 *    - Use attachInterrupt() to detect button presses
 *    - The button should ignore rapid state changes (bouncing)
 *    - Only register a press after the state has been stable for a short time
 *    - Remember: ISR functions should be short and use volatile variables
 * 
 * EXPECTED RESULT:
 * - The blink LED should toggle at its own interval
 * - The fade LED should smoothly fade up and down
 * - The button LED should respond instantly to presses via interrupt
 * - All three should operate simultaneously without interfering with each other
 * 
 * HINTS:
 * - You will need to track "previousMillis" for each timed operation
 * - Use state variables to remember what each LED is doing between loop() calls
 * - For the interrupt, remember to use a volatile flag that the ISR sets and loop() reads
 * - For debouncing, track when the button state last changed
 * 
 * ============================================================================
 */

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

int blinkEvent = 500;  // Checking if the delay is correct in millis
int fadeEvent = 10;  // for blink and fade events so i can use it in if ()
int debounceEvent = 20;

unsigned long prevBlinkEvent = 0; // 2 buckets for keeping brevious blinked or faded time
unsigned long prevFadeEvent = 0;
unsigned long prevDebounceEvent = 0;

// ============================================================================
// State Variables
// ============================================================================
int fadeValue = 0;        // Current brightness of the fade LED (0-255)
int fadeDirection = 1;    // 1 = fading up, -1 = fading down

unsigned long currentTime = 0; // unsigned long for millis dunction
bool ledBlinkState = false;  // to turn on led first when executing the code

int ledState = 1; // This is to find modulus and check if its odd or even for fading

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
  attachInterrupt(digitalPinToInterrupt(buttonPin),buttonLed,FALLING);

  Serial.println("Starting LED demo...");
}

// ============================================================================
// loop()
// ============================================================================
void loop() {
  // millis timer saved to currentTime
  currentTime = millis();

  // Blink the first LED
  blinkLed();

  // Fade the second LED
  fadeLed();
  
  // Control the third LED with the button
  // buttonLed();
}

// ============================================================================
// blinkLed() - Toggles the blink LED on and off
// ============================================================================
void blinkLed() {
  // checking if its time for led to blink
  if (currentTime - prevBlinkEvent >= blinkEvent) {
    ledBlinkState = !ledBlinkState;
    digitalWrite(blinkLedPin, ledBlinkState);
    prevBlinkEvent = currentTime;
  }
}

// ============================================================================
// fadeLed() - Fades the LED up and down using PWM
// ============================================================================
void fadeLed() {
  // checking if its time for led to fade
  if (currentTime - prevFadeEvent >= fadeEvent) {
    // Set the LED brightness
    analogWrite(fadeLedPin, fadeValue);

    // Update the fade value
    fadeValue += fadeDirection * fadeStep;

    // Reverse direction at the limits
    if (fadeValue >= 255) {
      fadeValue = 255;
      fadeDirection = -1;
    } 
    else if (fadeValue <= 0) {
      fadeValue = 0;
      fadeDirection = 1;
    }
    prevFadeEvent = currentTime;
  }
}

// ============================================================================
// buttonLed() - Turns LED on when button is pressed
// ============================================================================
// IRAM_ATTR is used so it can run smoothly and safely from flash
// when its unavailable
void IRAM_ATTR buttonLed() {
  // Read the button state (LOW when pressed due to INPUT_PULLUP)
  if (currentTime - prevDebounceEvent >= debounceEvent) {
    if (digitalRead(buttonPin) == LOW) {
      ledState++;
      if (ledState % 2 == 0) {
        digitalWrite(buttonLedPin, HIGH);  // Turn LED on
      }
      else {
        digitalWrite(buttonLedPin, LOW);   // Turn LED off
      }
      if (ledState > 10) { // prevent overflow
        ledState = 1;
      }
      prevDebounceEvent = currentTime;
    }
  }
}
