/*
 * BLINK
 * Turns a LED on for 1 second, then turns it off for 1 second,
 * repeatedly.
 */

// The anode (the positive and longer leg of the LED) is connected
// to pin 13. The cathode should be connected to to the GND.
int led = 13;

// Setup routine - it runs once when reset is pressed:
void setup() {
  // Initialize the digital pin as output.
  pinMode(led, OUTPUT);
}

// Loop routine - runs over and over indefinitely:
void loop() {
  digitalWrite(led, HIGH); // Turn the LED on (voltage level = HIGH).
  delay(1000); // Wait for 1 second.
  digitalWrite(led, LOW); // Turn the LED off (voltage level = LOW).
  delay(1000); // Wait for 1 second.
}
