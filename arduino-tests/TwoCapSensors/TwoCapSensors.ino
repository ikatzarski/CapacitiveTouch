#include <CapacitiveSensor.h>

/*
 * TWO CAP SENSORS 
 * Using two capacitive sensors just for testing purposes.
 * Uses 2 1M resistors between the send pin (4) and the receive 
 * (sensor) pins (2 and 6).
 * The 1M resistors ensure absolute touch.
 */

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);   // 1M resistor between pins 4 & 2.
CapacitiveSensor cs_4_6 = CapacitiveSensor(4, 6);   // 1M resisotr between pins 4 & 6.

void setup() {
  Serial.begin(9600);
}

void loop() {
  long start = millis();
  long total1 = cs_4_2.capacitiveSensor(30);
  long total2 = cs_4_6.capacitiveSensor(30);

  Serial.print(millis() - start);   // Check on performance in millisencs.
  Serial.print("\t");               // Tab character for debug window spacing.

  Serial.print(total1);             // Print sensor output 1.
  Serial.print("\t");               // Print space.
  Serial.println(total2);           // Print sensor output 2.

  delay(500);                       // Arbitrary delay to limit data to serial port.
}
