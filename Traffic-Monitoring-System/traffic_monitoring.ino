// ==========================================
// SMART TRAFFIC MONITORING SYSTEM
// Arduino UNO - Two Roads
// ==========================================

// ---------- ROAD 1 ----------
const int R1_RED = 2;
const int R1_YELLOW = 3;
const int R1_GREEN = 4;

const int R1_TRIG = 5;
const int R1_ECHO = 6;


// ---------- ROAD 2 ----------
const int R2_RED = 7;
const int R2_YELLOW = 8;
const int R2_GREEN = 9;

const int R2_TRIG = 10;
const int R2_ECHO = 11;



void setup() {

  // Road 1 LEDs
  pinMode(R1_RED, OUTPUT);
  pinMode(R1_YELLOW, OUTPUT);
  pinMode(R1_GREEN, OUTPUT);

  // Road 2 LEDs
  pinMode(R2_RED, OUTPUT);
  pinMode(R2_YELLOW, OUTPUT);
  pinMode(R2_GREEN, OUTPUT);

  // Ultrasonic sensors
  pinMode(R1_TRIG, OUTPUT);
  pinMode(R1_ECHO, INPUT);

  pinMode(R2_TRIG, OUTPUT);
  pinMode(R2_ECHO, INPUT);

  Serial.begin(9600);

  // Start with both roads RED
  allRed();

  delay(1000);
}


// READ DISTANCE
long getDistance(int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 999;
  }

  long distance = duration * 0.034 / 2;

  return distance;
}

// TRAFFIC LIGHT FUNCTIONS

void road1Green() {

  digitalWrite(R1_RED, LOW);
  digitalWrite(R1_YELLOW, LOW);
  digitalWrite(R1_GREEN, HIGH);

  digitalWrite(R2_RED, HIGH);
  digitalWrite(R2_YELLOW, LOW);
  digitalWrite(R2_GREEN, LOW);
}


void road2Green() {

  digitalWrite(R1_RED, HIGH);
  digitalWrite(R1_YELLOW, LOW);
  digitalWrite(R1_GREEN, LOW);

  digitalWrite(R2_RED, LOW);
  digitalWrite(R2_YELLOW, LOW);
  digitalWrite(R2_GREEN, HIGH);
}


void road1Yellow() {

  digitalWrite(R1_GREEN, LOW);
  digitalWrite(R1_YELLOW, HIGH);
  digitalWrite(R1_RED, LOW);
}


void road2Yellow() {

  digitalWrite(R2_GREEN, LOW);
  digitalWrite(R2_YELLOW, HIGH);
  digitalWrite(R2_RED, LOW);
}


void allRed() {

  digitalWrite(R1_RED, HIGH);
  digitalWrite(R1_YELLOW, LOW);
  digitalWrite(R1_GREEN, LOW);

  digitalWrite(R2_RED, HIGH);
  digitalWrite(R2_YELLOW, LOW);
  digitalWrite(R2_GREEN, LOW);
}

void loop() {

  // Read both sensors
  long road1Distance = getDistance(R1_TRIG, R1_ECHO);
  long road2Distance = getDistance(R2_TRIG, R2_ECHO);


  // Show readings in Serial Monitor
  Serial.print("Road 1: ");
  Serial.print(road1Distance);
  Serial.print(" cm");

  Serial.print("   |   Road 2: ");
  Serial.print(road2Distance);
  Serial.println(" cm");


  // A vehicle is considered detected, if it is closer than 30 cm.

  bool road1HasCar = road1Distance < 30;
  bool road2HasCar = road2Distance < 30;


  // CASE 1:Car on Road 1 only

  if (road1HasCar && !road2HasCar) {

    Serial.println("Traffic detected on ROAD 1");

    road1Green();
    delay(7000);

    road1Yellow();
    delay(2000);

    allRed();
    delay(1000);
  }

  // CASE 2: Car on Road 2 only
  else if (!road1HasCar && road2HasCar) {

    Serial.println("Traffic detected on ROAD 2");

    road2Green();
    delay(7000);

    road2Yellow();
    delay(2000);

    allRed();
    delay(1000);
  }

  // CASE 3: Cars on BOTH roads

  else if (road1HasCar && road2HasCar) {

    Serial.println("Traffic detected on BOTH ROADS");

    // Give Road 1 priority first
    road1Green();
    delay(5000);

    road1Yellow();
    delay(2000);

    allRed();
    delay(1000);

    // Then Road 2
    road2Green();
    delay(5000);

    road2Yellow();
    delay(2000);

    allRed();
    delay(1000);
  }

  // CASE 4: No cars detected

  else {

    Serial.println("No traffic detected");

    // Normal cycle
    road1Green();
    delay(5000);

    road1Yellow();
    delay(2000);

    allRed();
    delay(1000);

    road2Green();
    delay(5000);

    road2Yellow();
    delay(2000);

    allRed();
    delay(1000);
  }
}
