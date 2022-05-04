static const int cyclesOn = 256;
static const int muscleOneThreshold = 300;
static const int muscleTwoThreshold = 300;

static const int muscleOnePin = A2;
static const int muscleTwoPin = A1;

int muscleOneReading;
int muscleTwoReading;

int muscleOneCyclesRemaining = 0;
int muscleTwoCyclesRemaining = 0;

String muscleOneEncoding = "0";
String muscleTwoEncoding = "0";

void setup() {
  // Start serial monitor
  Serial.begin(9600);
}

void loop() {
  // Enable muscle one for cyclesOn when a spike is detected
  if (muscleOneCyclesRemaining <= 0) {
    muscleOneEncoding = "0";

    muscleOneReading = analogRead(muscleOnePin); 
    if (muscleOneReading > muscleOneThreshold) { 
      muscleOneCyclesRemaining = cyclesOn; 
      muscleOneEncoding = "1";
    }
  } else {
    muscleOneCyclesRemaining--;
  }

  // Enable muscle two for cyclesOn when a spike is detected
  if (muscleTwoCyclesRemaining == 0) {
    muscleTwoEncoding = "0";

    muscleTwoReading = analogRead(muscleTwoPin); 
    if (muscleTwoReading > muscleTwoThreshold) { 
      muscleTwoCyclesRemaining = cyclesOn; 
      muscleTwoEncoding = "1";
    }
  } else {
    muscleTwoCyclesRemaining--;
  }

  Serial.print(muscleOneEncoding + muscleTwoEncoding + "\n");

}
