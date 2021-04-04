#include <ArduinoBLE.h>
#include <SPI.h>


byte address = 0x00;
static const int muscleOneVoltagePin = 9; // D9
static const int muscleTwoVoltagePin = 8; // D8
static const int muscleThreeVoltagePin = 7; // D7

// BLE Muscle Voltage Service
BLEService muscleVoltageService("19B10000-E8F2-537E-4F6C-D204768A1214"); 
// BLE Muscle Voltage characteristics - custom 16-bit UUIDs, read and writable by central
BLEUnsignedIntCharacteristic muscleOneVoltage("00B1", BLERead | BLEWrite);
BLEUnsignedIntCharacteristic muscleTwoVoltage("00B2", BLERead | BLEWrite);
BLEUnsignedIntCharacteristic muscleThreeVoltage("00B3", BLERead | BLEWrite);

void setup() {
  Serial.begin(9600);

  // Set pin modes
  pinMode(muscleOneVoltagePin, OUTPUT);
  pinMode(muscleTwoVoltagePin, OUTPUT);
  pinMode(muscleThreeVoltagePin, OUTPUT);

  SPI.begin();
  
  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting BLE failed!");

    while (1);
  }

  // set advertised local name and service UUID:
  BLE.setDeviceName("Arduino Nano 33 IoT");
  BLE.setLocalName("TENS Unit Interface");
  BLE.setAdvertisedService(muscleVoltageService);

    // add the characteristic to the service
  muscleVoltageService.addCharacteristic(muscleOneVoltage);
  muscleVoltageService.addCharacteristic(muscleTwoVoltage);
  muscleVoltageService.addCharacteristic(muscleThreeVoltage);

  // add service
  BLE.addService(muscleVoltageService);

  // set the initial value for the characeristic:
  muscleThreeVoltage.writeValue(0);
  muscleTwoVoltage.writeValue(0);
  muscleOneVoltage.writeValue(0);

  // start advertising
  BLE.advertise();

  Serial.println("TENS Unit Interface");
}

void loop() {
  // listen for BLE peripherals to connect:
  BLEDevice central = BLE.central();

  // if a central is connected to peripheral:
  if (central) {
    Serial.print("Connected to central: ");
    // print the central's MAC address:
    Serial.println(central.address());

    // while the central is still connected to peripheral:
    while (central.connected()) {
      if (muscleOneVoltage.written()) { updateMuscleOneVoltage(muscleOneVoltage.value()); }
      if (muscleTwoVoltage.written()) { updateMuscleTwoVoltage(muscleTwoVoltage.value()); }
      if (muscleThreeVoltage.written()) { updateMuscleThreeVoltage(muscleThreeVoltage.value()); }
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }
}

void updateMuscleOneVoltage(int value) {
  digitalWrite(muscleOneVoltagePin, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(muscleOneVoltagePin, HIGH);
}

void updateMuscleTwoVoltage(int value) {
  digitalWrite(muscleTwoVoltagePin, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(muscleTwoVoltagePin, HIGH);
}

void updateMuscleThreeVoltage(int value) {
  digitalWrite(muscleThreeVoltagePin, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  digitalWrite(muscleThreeVoltagePin, HIGH);
}
