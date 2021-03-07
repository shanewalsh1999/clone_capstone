#include <SoftwareSerial.h>
SoftwareSerial EEBlue(0, 1); // RX | TX

static const int lowFreqPin = 3;
static const int medFreqPin = 6;
static const int highFreqPin = 9;

// Frequency and pulse width variables
int encodedValue;
int frequencyID;
int pulseWidthID;

void setup() {
  Serial.begin(9600);
  EEBlue.begin(9600);
  
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
  //  e.g. analogWrite(6, 1) = pulse width of 64.25us on pin 5
  // --------------------------------------------
  
  //------- Set PWM frequency for D9 & D10 -------
  // set timer 1 divisor to 256 for PWM frequency of 122.07 Hz
  TCCR1B = TCCR1B & B11111000 | B00000100;

  // pulse width can be adjusted in steps of 32.13 microseconds
  //  e.g. analogWrite(9, 3) = pulse width of 32.13*3us on pin 9
  //----------------------------------------------
}

void loop() { 
  if (EEBlue.available()) {
    // encodedValue:
    //  - frequencyID in tens place
    //  - pulseWidthID in ones place
    encodedValue = EEBlue.read();

    // Parse encoded value for frequency and pulse width IDs
    frequencyID = encodedValue / 10;
    pulseWidthID = encodedValue % 10;

    // Reset all output pins to avoid concurrent output signals
    analogWrite(lowFreqPin, 0);
    analogWrite(medFreqPin, 0);
    analogWrite(highFreqPin, 0);
    
    // Output clock signal
    switch(frequencyID) {
      // 30.64 Hz 
      case 1:
        analogWrite(lowFreqPin, pulseWidthID);
        break;
      
      // 61.04 Hz
      case 2:
        analogWrite(medFreqPin, pulseWidthID);
        break;
      
      // 122.07 Hz
      case 3:
        analogWrite(highFreqPin, pulseWidthID);
        break;
    }
    
    // Display data on serial monitor
    Serial.print("frequencyID: ");
    Serial.println(frequencyID);
    Serial.print("pulseWidthID: ");
    Serial.println(pulseWidthID);
    Serial.println();
  }
}
