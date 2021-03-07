#include <SoftwareSerial.h>
SoftwareSerial EEBlue(0, 1); // RX | TX

void setup() {
  //------- Set PWM frequency for D3 & D11 -------
  // set timer 2 divisor to  1024 for PWM frequency of 30.64 Hz
  TCCR2B = TCCR2B & B11111000 | B00000111;    

  // pulse width can be adjusted in steps of 128.5 microseconds
  //  e.g. analogWrite(3, 2) = pulse width of 128.5*2us on pin 3
  // ---------------------------------------------
  
  //------- Set PWM frequency for D5 & D6 -------
  // NOTE: Changing this timer affects millis() and delay!
  // set timer 0 divisor to 1024 for PWM frequency of 61.04 Hz
  TCCR0B = TCCR0B & B11111000 | B00000101;  
  
  // pulse width can be adjusted in steps of 64.25 microseconds
  //  e.g. analogWrite(5, 1) = pulse width of 64.25us on pin 5
  // --------------------------------------------
  
  //------- Set PWM frequency for D9 & D10 -------
  // set timer 1 divisor to 256 for PWM frequency of 122.07 Hz
  TCCR1B = TCCR1B & B11111000 | B00000100;

  // pulse width can be adjusted in steps of 32.13 microseconds
  //  e.g. analogWrite(9, 2) = pulse width of 32.13*2us on pin 9
  //----------------------------------------------

  // Pin 5: 61.04 Hz, 64.25*1 = 64.245us pulse width
  // analogWrite(5, 1);
  
  // Pin 9: 30.64 Hz, 127.49*3 = 382.47us pulse width
  // analogWrite(9, 3);
  
}

void loop() { 
  // Display data sent over bluetooth
  if (EEBlue.available()) {
    int encodedVal = EEBlue.read();
    Serial.write(encodedValue);
  }
}
