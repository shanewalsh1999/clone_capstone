static const int muscleOnePin = A0;
static const int muscleTwoPin = A1;
static const int muscleThreePin = A2;

int muscleOneReading;
int muscleTwoReading;
int muscleThreeReading;

void setup() {
  // Start serial monitor
  Serial.begin(9600);
}

void loop() {
  muscleOneReading = analogRead(muscleOnePin);
  muscleTwoReading = analogRead(muscleTwoPin);
  muscleThreeReading = analogRead(muscleThreePin);

  // Encode to serial monitor
  Serial.print("A");
  Serial.println(muscleOneReading);
  Serial.print("B");
  Serial.println(muscleTwoReading);
  Serial.print("C");
  Serial.println(muscleThreeReading);

}
