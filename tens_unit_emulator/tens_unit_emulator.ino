void setup() {
  //------- Set PWM frequency for D5 & D6 -------
  // NOTE: Changing this timer affects millis() and delay!
  // set timer 0 divisor to 1024 for PWM frequency of 61.04 Hz
  TCCR0B = TCCR0B & B11111000 | B00000101;  
  
  // pulse width can be adjusted in steps of 64.25 microseconds
  //  e.g. analogWrite(5, 1) = pulse width of 64.25us on pin 5
  // --------------------------------------------
  
  //------- Set PWM frequency for D9 & D10 -------
  // set timer 1 divisor to 1024 for PWM frequency of 30.64 Hz
  TCCR1B = TCCR1B & B11111000 | B00000101;

  // pulse width can be adjusted in steps of 127.49 microseconds
  //  e.g. analogWrite(9, 2) = pulse width of 127.49*2us on pin 9
  //----------------------------------------------

  // Pin 5: 61.04 Hz, 64.25*1 = 64.245us pulse width
  analogWrite(5, 1);
  
  // Pin 9: 30.64 Hz, 127.49*3 = 382.47us pulse width
  analogWrite(9, 3);
  
}

void loop() { }
