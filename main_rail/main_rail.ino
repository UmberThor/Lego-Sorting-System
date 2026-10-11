#define STEP_PIN 18       // Step pin connected to A4988 STEP
#define DIR_PIN 19        // Direction pin connected to A4988 DIR
#define ENABLE_PIN 21     // Enable pin connected a A4988 EN (optional)
#define LED_PIN 2         // Led pin

int stepsPerRevolution = 200;

void setup() {
  Serial.begin(115200);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);

  digitalWrite(ENABLE_PIN, LOW);  // Enable driver (LOW = ON)
  Serial.print("Stepper Motor Test Start");
}

void loop() {
  // Rotare clockwise
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(DIR_PIN, HIGH);
  stepMotor(stepsPerRevolution);
  delay(1000);

  // Rotare counterclockwise
  digitalWrite(LED_PIN, LOW);
  digitalWrite(DIR_PIN, LOW);
  stepMotor(stepsPerRevolution);
  delay(1000);
}

void stepMotor(int steps) {
  for (int i = 0; i < steps; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(2000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(2000);
  }
}