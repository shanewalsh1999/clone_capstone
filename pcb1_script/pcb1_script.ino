static const int cyclesOn = 256;
static const int muscleOneThreshold = 700;
static const int muscleTwoThreshold = 700;
static const int muscleThreeThreshold = 700;

static const int muscleOnePin = A0;
static const int muscleTwoPin = A1;
static const int muscleThreePin = A2;

int muscleOneReading;
int muscleTwoReading;
int muscleThreeReading;

int muscleOneCyclesRemaining = 0;
int muscleTwoCyclesRemaining = 0;
int muscleThreeCyclesRemaining = 0;

String muscleOneEncoding = "0";
String muscleTwoEncoding = "0";
String muscleThreeEncoding = "0";

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

    // Enable muscle Three for cyclesOn when a spike is detected
  if (muscleThreeCyclesRemaining <= 0) {
    muscleThreeEncoding = "0";

    muscleThreeReading = analogRead(muscleThreePin); 
    if (muscleThreeReading > muscleThreeThreshold) { 
      muscleThreeCyclesRemaining = cyclesOn; 
      muscleThreeEncoding = "1";
    }
  } else {
    muscleThreeCyclesRemaining--;
  }

  Serial.print(muscleOneEncoding + muscleTwoEncoding + muscleThreeEncoding + "\n");

}
