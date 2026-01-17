/*
 * ================================================================
 * NON-BLOCKING LED EXERCISE
 * ================================================================
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
 * ================================================================
 */

#include <Arduino.h>

// ================================================================
// Pin Definitions - Define which GPIO pins each component uses
// ================================================================
// Each pin is dedicated to one LED or the button input
int blinkLedPin = 5;       // GPIO 5: LED that toggles on/off at regular intervals
int fadeLedPin = 18;       // GPIO 18: LED that fades in/out smoothly (PWM capable pin)
int buttonLedPin = 12;     // GPIO 12: LED controlled by button press (toggle on/off)
int buttonPin = 39;        // GPIO 39: Button input pin (triggers hardware interrupt)

// ================================================================
// Timing Configuration - Control the speed of LED operations
// ================================================================
// These values define HOW LONG to wait before performing the next action
// Using non-blocking timing (millis()) instead of delay() keeps the processor responsive
int blinkEvent = 500;      // Delay between blink toggles (500ms = 0.5 seconds)
int fadeEvent = 10;        // Delay between fade brightness steps (10ms = faster fading)
int fadeStep = 5;          // How much to increase/decrease brightness each step (0-255 range)
int debounceEvent = 20;    // Time to wait for button signal to stabilize (debouncing: 20ms)

// ================================================================
// Timing Tracking Variables - Remember when the last action happened
// ================================================================
// These track the PREVIOUS time an action occurred, so we can calculate elapsed time
// Formula: if (currentTime - previousTime >= interval) then perform action
unsigned long prevBlinkEvent = 0;    // Stores the last time the blink LED toggled
unsigned long prevFadeEvent = 0;     // Stores the last time the fade LED brightness changed
unsigned long prevDebounceEvent = 0; // Stores the last time button state was checked

// ================================================================
// State Variables - Remember the current state of each component
// ================================================================
// These variables PERSIST between loop() iterations, so we can track ongoing states
int fadeValue = 0;         // Current brightness of fade LED (0=off, 255=max brightness)
int fadeDirection = 1;     // Direction of fade: 1 = fading up, -1 = fading down

unsigned long currentTime = 0; // Current millis() value - updated every loop iteration
bool ledBlinkState = false;    // Current state of blink LED: false=off, true=on

// VOLATILE keyword is CRITICAL for variables modified in ISR (Interrupt Service Routine)
// When a variable is volatile, the compiler won't cache it in a register - it will always
// read the actual memory value. This prevents timing issues when ISR changes the variable
volatile int ledState = 1;              // Modified in ISR, read in main loop - NEEDS VOLATILE
volatile unsigned long lastButtonPress = 0; // ISR will update this time - NEEDS VOLATILE

// ================================================================
// Function Prototypes - Declare function names before they're used
// ================================================================
// This tells the compiler these functions exist (defined later in the file)
void blinkLed();      // Controls the blinking LED
void fadeLed();       // Controls the fading LED
void buttonLed();     // ISR (Interrupt Service Routine) for button press

// ================================================================
// setup() - Runs ONCE when the microcontroller powers on or resets
// ================================================================
void setup() {
  // Initialize serial communication at 115200 baud rate
  // This allows us to send debug messages to the Serial Monitor
  Serial.begin(115200);

  // Configure all LED pins as OUTPUT (we're sending signals TO them)
  pinMode(blinkLedPin, OUTPUT);  // Blink LED starts off
  pinMode(fadeLedPin, OUTPUT);   // Fade LED starts at brightness 0
  pinMode(buttonLedPin, OUTPUT); // Button LED starts off

  // Configure button pin as INPUT with internal pull-up resistor
  // INPUT_PULLUP means: pin reads HIGH normally, goes LOW when button is pressed
  // This requires the button to connect to GND (not VCC)
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Attach hardware interrupt to the button pin
  // When button goes from HIGH to LOW (FALLING edge), call buttonLed() immediately
  // This is MUCH faster than checking the button in loop()
  // digitalWrite(blinkLedPin, LOW) at the beginning would set initial LED state
  attachInterrupt(digitalPinToInterrupt(buttonPin), buttonLed, FALLING);
  
  Serial.println("Starting LED demo...");
}

// ================================================================
// loop() - Runs continuously after setup() completes
// ================================================================
// The loop runs as fast as possible (thousands of times per second)
// Each function checks: is it time to do something? If yes, do it. If no, skip it.
void loop() {
  // Update currentTime at the START of each loop iteration
  // This ensures all functions use the SAME time value for that iteration
  // If we called millis() inside each function, times might differ slightly
  currentTime = millis();

  // Blink the first LED (toggles on/off every 500ms)
  blinkLed();

  // Fade the second LED (adjusts brightness every 10ms)
  fadeLed();
  
  // NOTE: buttonLed() is NOT called here because it's called by the hardware interrupt
  // When button is pressed, the ISR buttonLed() executes immediately, regardless of loop()
}

// ================================================================
// blinkLed() - Toggles the blink LED on and off at regular intervals
// ================================================================
// This function implements NON-BLOCKING timing:
// Instead of using delay() which STOPS the entire program,
// we check how much time has elapsed and only toggle when enough time has passed
void blinkLed() {
  // Calculate elapsed time since last blink toggle
  // If currentTime - prevBlinkEvent >= 500ms, then toggle
  // Example: if currentTime = 2000ms and prevBlinkEvent = 1500ms, elapsed = 500ms → toggle
  if (currentTime - prevBlinkEvent >= blinkEvent) {
    // Toggle the LED: if it was on (true), turn it off (false), and vice versa
    ledBlinkState = !ledBlinkState;
    
    // Send the new state to the GPIO pin (HIGH=on, LOW=off)
    digitalWrite(blinkLedPin, ledBlinkState);
    
    // Update the timer to THIS moment, so next toggle waits another 500ms
    prevBlinkEvent = currentTime;
  }
  // If NOT enough time has passed, function exits without doing anything
}

// ================================================================
// fadeLed() - Fades the LED brightness up and down using PWM
// ================================================================
// PWM (Pulse Width Modulation) on GPIO 18 lets us control brightness
// analogWrite() accepts values 0-255 (0=completely off, 255=full brightness)
void fadeLed() {
  // Check if it's time to update the brightness (every 10ms)
  if (currentTime - prevFadeEvent >= fadeEvent) {
    // Write the CURRENT fade value to the PWM pin
    // This sets the LED brightness right now
    analogWrite(fadeLedPin, fadeValue);

    // Increase or decrease the brightness value by fadeStep (5 units)
    // fadeDirection is 1 (increasing) or -1 (decreasing)
    // Example: if fadeValue=100 and fadeDirection=1, next value=105
    fadeValue += fadeDirection * fadeStep;

    // Check if we've reached the brightness limits and reverse direction if so
    if (fadeValue >= 255) {
      // We're at maximum brightness, so reverse direction to fade DOWN
      fadeValue = 255;           // Cap it at max (prevent overflow)
      fadeDirection = -1;        // Change direction: start decreasing
    } 
    else if (fadeValue <= 0) {
      // We're at minimum brightness, so reverse direction to fade UP
      fadeValue = 0;             // Cap it at min (prevent underflow)
      fadeDirection = 1;         // Change direction: start increasing
    }
    
    // Update the timer - remember we just updated brightness
    prevFadeEvent = currentTime;
  }
  // If NOT enough time has passed, nothing happens (LED brightness unchanged)
}

// ================================================================
// buttonLed() - ISR (Interrupt Service Routine) for button press
// ================================================================
// IMPORTANT: This function runs IMMEDIATELY when the button is pressed
// It does NOT wait for loop() to check it - the hardware interrupts the processor
// 
// ISR RULES:
// 1. Keep ISR code SHORT - don't do heavy processing
// 2. Use VOLATILE for all variables modified in ISR or read from main code
// 3. Avoid calling functions that take time (like Serial.println with lots of text)
// 4. IRAM_ATTR ensures this code stays in fast RAM memory (not slower flash)
// 
// DEBOUNCING EXPLANATION:
// Mechanical buttons bounce - they rapidly make/break contact for ~20ms when pressed
// This causes multiple interrupts from a single button press
// Solution: Only toggle LED if enough time has passed since last valid press (debouncing)
void IRAM_ATTR buttonLed() {
  // CRITICAL FIX: Cannot use currentTime inside ISR reliably because:
  // - currentTime is only updated once per loop() iteration
  // - While ISR is running, currentTime might be outdated
  // Solution: Use millis() directly inside ISR to get the CURRENT time
  
  unsigned long now = millis(); // Get current time RIGHT NOW
  
  // Check if enough time has passed since the last button press (debouncing)
  // 20ms is enough time for button contacts to stabilize
  if (now - lastButtonPress >= debounceEvent) {
    // Button press is valid (not just a bounce)
    
    // Increment ledState counter (used to toggle LED on/off)
    ledState++;
    
    // If ledState is EVEN, turn LED ON; if ODD, turn LED OFF
    // We use modulus (%) to check if the number divides evenly by 2
    if (ledState % 2 == 0) {
      digitalWrite(buttonLedPin, HIGH);  // Turn ON: send 3.3V to the pin
    }
    else {
      digitalWrite(buttonLedPin, LOW);   // Turn OFF: send 0V to the pin
    }
    
    // Safety check: prevent ledState from growing too large and overflowing
    // If ledState exceeds 10, reset it back to 1
    // This prevents integer overflow after many button presses
    if (ledState > 10) {
      ledState = 1;
    }
    
    // Update the debounce timer to RIGHT NOW
    // This prevents the next button press from being recognized for another 20ms
    lastButtonPress = now;
  }
  // If NOT enough time has passed, ISR just exits without doing anything
}
