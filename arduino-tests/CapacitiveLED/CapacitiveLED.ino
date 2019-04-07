#include <CapacitiveSensor.h>

/*
 * Using capacitive touch to turn on a LED.
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin.
 * A wire and a breadboard could also be used.
 */


// Variables:
const int ledPin = 13;                                   // The number of the LED pin.
const int ledFloor = 200;                                // The minimum value needed to turn the LED on.

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);       // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired.

void setup()                    
{
   //cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // Turn off autocalibrate on channel 1 - just as an example.
   Serial.begin(9600);

   pinMode(ledPin, OUTPUT);                      // Set the digital pin as OUTPUT.
}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);

    Serial.print(millis() - start);        // Check on performance in milliseconds.
    Serial.print("\t");                    // Tab character for debug windown spacing.

    Serial.println(total1);                // Print sensor output 1.

    // If total1 is higher than the minimum value, the LED will be turned on.
    // In other words, if the wire/foil is touched just with the tip of a finger, 
    // the LED will not light up. A wire and a breadboard is used in this example.
    // Using a foil, might require readjusting the ledFloor value:  
    if (total1 > ledFloor)
      digitalWrite(ledPin, HIGH);
    else
      digitalWrite(ledPin, LOW);
    
    delay(500);                            // Arbitrary delay to limit data to serial port. 
}
