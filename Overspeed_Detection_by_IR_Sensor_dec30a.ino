#include "arduino_secrets.h"
#include "thingProperties.h"  // Include Arduino IoT Cloud library

// IR Sensor Pins
#define IR1_PIN 35  // Lane 1, Sensor 1
#define IR2_PIN 34  // Lane 1, Sensor 2
#define IR3_PIN 39  // Lane 2, Sensor 1 (VN)
#define IR4_PIN 36  // Lane 2, Sensor 2 (VP)

// Distance between sensors (in cm)
const float SENSOR_DISTANCE_CM = 6.0;

// Speed limit (in cm/ms, equivalent to 20 km/h)
const float SPEED_LIMIT_CM_MS = (20.0 * 100000) / (60 * 60 * 1000);

// Variables to store timings
unsigned long timeIR1 = 0;
unsigned long timeIR2 = 0;
unsigned long timeIR3 = 0;
unsigned long timeIR4 = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);

  // Initialize IR sensor pins
  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);
  pinMode(IR4_PIN, INPUT);

  // Initialize IoT Cloud properties
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Debug message
  Serial.println("Speed Monitoring System Initialized.");
}

void loop() {
  ArduinoCloud.update(); // Update IoT Cloud

  // Lane 1 speed calculation and violation check
  if (digitalRead(IR1_PIN) == LOW) { // Vehicle triggers IR1
    timeIR1 = millis();
  }
  if (digitalRead(IR2_PIN) == LOW) { // Vehicle triggers IR2
    timeIR2 = millis();
    speed01 = calculateSpeed(timeIR1, timeIR2);
    status01 = checkViolation(speed01);
  }

  // Lane 2 speed calculation and violation check
  if (digitalRead(IR3_PIN) == LOW) { // Vehicle triggers IR3
    timeIR3 = millis();
  }
  if (digitalRead(IR4_PIN) == LOW) { // Vehicle triggers IR4
    timeIR4 = millis();
    speed02 = calculateSpeed(timeIR3, timeIR4);
    status02 = checkViolation(speed02);
  }

  // Debugging output
  Serial.print("Lane 1 Speed: ");
  Serial.print(speed01);
  Serial.println(" cm/ms");
  Serial.print("Lane 1 Violation: ");
  Serial.println(status01);

  Serial.print("Lane 2 Speed: ");
  Serial.print(speed02);
  Serial.println(" cm/ms");
  Serial.print("Lane 2 Violation: ");
  Serial.println(status02);

  delay(100); // Short delay for stability
}

// Function to calculate speed (cm/ms)
float calculateSpeed(unsigned long startTime, unsigned long endTime) {
  if (endTime > startTime) {
    unsigned long timeDifference = endTime - startTime; // Time in milliseconds
    return (SENSOR_DISTANCE_CM / timeDifference);
  } else {
    return 0.0; // Invalid time difference
  }
}

// Function to check for speed violation
bool checkViolation(float speed) {
  return speed > SPEED_LIMIT_CM_MS;
}

// Callback functions
void onSpeed01Change() {
  Serial.print("Lane 1 Speed Updated: ");
  Serial.println(speed01);
}

void onSpeed02Change() {
  Serial.print("Lane 2 Speed Updated: ");
  Serial.println(speed02);
}

void onStatus01Change() {
  Serial.print("Lane 1 Violation Status Updated: ");
  Serial.println(status01);
}

void onStatus02Change() {
  Serial.print("Lane 2 Violation Status Updated: ");
  Serial.println(status02);
}
