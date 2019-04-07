/*
 * Blink without delay():
 * Turns on and off a LED withoud using the delay() function. Thus,
 * other code can be run at the same time without being interrupted
 * by the LED code.
 */

// Constants:
const int ledPin = 13;  // The number of the LED pin.

// Variables:
int ledState = LOW;  // Used to set the LED.
long previousMillis = 0;  // Will store the last time the LED was updated. 

// A long is used since because the time, measured in milliseconds, will
// quickly become bigger than the value an int can store.
long interval = 1000;  // Blinking interval.

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the digital pin as OUTPUT.
}

void loop() {
  // Check to see if it is time to blink the LED. That is, if the
  // difference between the current and the last time is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {
    // Save the last time you blinked the LED.
    previousMillis = currentMillis;

    // If the LED is off, turn it on and vice-versa:
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    // Set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
