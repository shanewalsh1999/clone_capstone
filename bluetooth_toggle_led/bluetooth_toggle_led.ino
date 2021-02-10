#include <SoftwareSerial.h>
SoftwareSerial EEBlue(0, 1); // RX | TX

void setup() {
  Serial.begin(9600);
  EEBlue.begin(9600);  //Default Baud for comm, it may be different for your Module. 
  Serial.println("The bluetooth gates are open.\n Connect to HC-05 from any other bluetooth device with 1234 as pairing key!.");
}

void loop() {
  // Toggle LED when data is sent to bluetooth
  if (EEBlue.available()) {
    Serial.write(EEBlue.read());
    Serial.println(!digitalRead(LED_BUILTIN));
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  }
}
