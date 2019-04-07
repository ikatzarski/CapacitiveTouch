/*
 * AnalogReadSerial
 * Reads analog input on pin 0, prints the result to the serial
 * monitor.
 * Pin A0 is attached to the center pin of a 10K potentiometer.
 * The outside pins of the potentiometer are attached to +5V and
 * to ground.
 */

void setup() {
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Print out the value you read:
  Serial.println(sensorValue);
  delay(1);     // Delay in between reads for stability.
}
