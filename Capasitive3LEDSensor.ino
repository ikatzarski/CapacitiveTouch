#include <CapacitiveSensor.h> // Capacitive Sense library.

/*
 * 3 CAPACITIVE SENSORS CONTROLLING 3 LEDs.
 * Using capacitive touch to switch between 3 LEDs.
 * Uses 1M resistors between the send pin (2) and the receive/sensor (3, 5, and 7) pins.
 * The 1M resistor requires absolute touch to activate. Larger resistor values yield larger sensor values.
 */


// Variables:
const int RED_LED = 13;        // The number of the RED_LED pin.
const int AMBER_LED = 11;      // The number of the AMBER_LED pin.
const int GREEN_LED = 9;       // The number of the GREEN_LED pin.
const int THRESHOLD = 150;     // The minimum value a sensor needs to reach to turn an LED on.

CapacitiveSensor cs_2_3 = CapacitiveSensor(2,3);    // 1M resistor between pins 2 & 3, pin 3 is sensor/receive pin.
CapacitiveSensor cs_2_5 = CapacitiveSensor(2,5);    // 1M resistor between pins 2 & 5, pin 5 is sensor/receive pin.
CapacitiveSensor cs_2_7 = CapacitiveSensor(2,7);    // 1M resistor between pins 2 & 7, pin 7 is sensor/receive pin.

void setup()                    
{
   Serial.begin(9600);             // Starts a serial port needed for the communication
                                   // between the Arduino and the computer.

   pinMode(RED_LED, OUTPUT);       // Set digital pin 13 as OUTPUT.
   pinMode(AMBER_LED, OUTPUT);     // Set digital pin 11 as OUTPUT.
   pinMode(GREEN_LED, OUTPUT);     // Set digital pin 9 as OUTPUT.
}

void loop()                    
{
    long start = millis();         // Keeps track of the lowest (baseline) capacitance.

    // The three longs contain the sensed capacitance when a sensor has been touched.
    // The capacitance is in arbitrary units. The value in the brackets (30) is in
    // bytes and it adjusts the sensitivity of the sensor.
    long greenSensor = cs_2_3.capacitiveSensor(30);
    long amberSensor = cs_2_5.capacitiveSensor(30);   
    long redSensor = cs_2_7.capacitiveSensor(30);   

    // All data is printed on the Serial Monitor.
    Serial.print(millis() - start);     // Check on performance in milliseconds.
    Serial.print("\t");                 // Tab character for debug windown spacing.

    Serial.print(greenSensor);          // Print the output of the greenSensor.
    Serial.print("\t");                 // Print space.
    Serial.print(amberSensor);          // Print the output of the amberSensor.
    Serial.print("\t");                 // Print space.
    Serial.println(redSensor);          // Print the output of the redSensor.
    
    
    if (amberSensor > THRESHOLD) {                   // If amberSensor is higher than the minimum value (THRESHOLD),
      digitalWrite(RED_LED, LOW);                    // only the AMBER_LED will light up.
      digitalWrite(GREEN_LED, LOW);                  
      digitalWrite(AMBER_LED, HIGH);
    } else if (greenSensor > THRESHOLD) {            // If greenSensor is higher than the minimum value, only
      digitalWrite(RED_LED, LOW);                    // the GREEN_LED will light up.
      digitalWrite(AMBER_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    } else if (redSensor > THRESHOLD) {              // If redSensor is higher than the minimum value, only
      digitalWrite(AMBER_LED, LOW);                  // the RED_LED will light up.
      digitalWrite(GREEN_LED, LOW);                  
      digitalWrite(RED_LED, HIGH);
    }
    
    delay(500);    // Arbitrary delay to limit data to serial port. 
}
