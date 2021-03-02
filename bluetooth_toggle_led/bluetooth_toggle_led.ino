#include <SoftwareSerial.h>
#define ledPin LED_BUILTIN

SoftwareSerial EEBlue(0, 1); // RX | TX

void setup() {
  Serial.begin(9600);
  
  // while the serial stream is not open, do nothing:
   while (!Serial) ;

  pinMode(ledPin, OUTPUT);
  
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}
 
void loop() {
  // Toggle LED when data is sent to bluetooth
  if (EEBlue.available()) {
    Serial.println("We in this bitch");
    Serial.write(EEBlue.read());
    Serial.println(!digitalRead(ledPin));
    digitalWrite(ledPin, !digitalRead(ledPin));
  }
}
