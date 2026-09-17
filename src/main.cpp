#include <Arduino.h>

const int TRIG_PIN = 9;
const int ECHO_PIN = 10;

const int RED_LED = 5;
const int YELLOW_LED = 6;
const int GREEN_LED = 7;

long readDistance() {
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the duration of the pulse
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return -1; // Indicate an error or out of range
  }

  // Calculate the distance in centimeters
  long distance = duration * 0.034 / 2;

  return distance;
}

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  long distance = readDistance();

  Serial.print("Distance: ");
  if (distance == -1) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }


  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  if ( distance < 0 ||distance > 50) {
    digitalWrite(GREEN_LED, HIGH); // clear
  } else if (distance > 20) {
    digitalWrite(YELLOW_LED, HIGH); // getting close
  } else {
    digitalWrite(RED_LED, HIGH); // very close
  }
  delay(150);
}
