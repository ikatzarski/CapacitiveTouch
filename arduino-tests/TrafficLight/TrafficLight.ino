/*
 * TRAFFIC LIGHT
 * Turn the LEDs on and off in 1 sec intervals in the order -
 * red, yellow, green.
 */

// The anodes of the LEDs should be connected to these pins:
int redLED = 13;
int yellowLED = 11;
int greenLED = 9;

void setup() {
  // Initialize the LED digital pins as output:
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Turn the red LED on and off:
  digitalWrite(redLED, HIGH);
  delay(1000);
  digitalWrite(redLED, LOW);

  // Turn the yellow LED on and off:
  digitalWrite(yellowLED, HIGH);
  delay(1000);
  digitalWrite(yellowLED, LOW);

  // Turn the green LED on and off:
  digitalWrite(greenLED, HIGH);
  delay(1000);
  digitalWrite(greenLED, LOW);
}
