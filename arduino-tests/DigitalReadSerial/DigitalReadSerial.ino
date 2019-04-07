/*
 * DigitalReadSerial
 * Reads a digital input on pin 2.
 * Prints the result to the serial monitor.
 */

// Digital pin 2 has a pushbutton attached to it:
int pushButton = 2;

// The setup routine runs once when you press reset:
void setup() {
  // Initialize serial communication at 9600 bits per sec:
  Serial.begin(9600);
  // Make the pushbutton's pin an input:
  pinMode(pushButton, INPUT);
}

// The loop routine runs over and over again forever:
void loop() {
  // Read the input pin:
  int buttonState = digitalRead(pushButton);
  // Print out the state of the button:
  Serial.println(buttonState);
  delay(1);   // Delay in between reads for stability.
}
