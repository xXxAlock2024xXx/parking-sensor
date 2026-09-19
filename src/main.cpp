#include "UltrasonicSensor.h"
#include <Arduino.h>


const int RED_LED = 5;
const int YELLOW_LED = 6;
const int GREEN_LED = 7;

UltrasonicSensor sensor(9,10); //Trig , Echo

void setup() {
  Serial.begin(9600);
  sensor.begin();

  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}


void loop() {
  long distance = sensor.readDistanceCm();

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
