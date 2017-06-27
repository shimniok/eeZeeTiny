/*
  Blink - example for eeZeeTiny (ATtiny25/45/85)

  Flashes an LED connected to LEDPIN: on for 1 second, off for 1 second.
  
  NOTE: You'll need to connect an LED and resistor to the LEDPIN below.
  Connect LED Anode to LEDPIN. Connect the LED Cathode to a 330 ohm 
  resistor. Connect the other end of the resistor to ground.
 
  This example code is in the public domain.
 */

#define LEDPIN 0  // Arduino pin 0 (ATtiny85 pin PB0)

void setup() {                
  // initialize the digital pin as an output.
  pinMode(LEDPIN, OUTPUT);     
}

void loop() {
  digitalWrite(LEDPIN, HIGH);   // set the LED on
  delay(200);              // wait for a second
  digitalWrite(LEDPIN, LOW);    // set the LED off
  delay(200);              // wait for a second
}
