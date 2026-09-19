#ifndef ULTRASONIC_SENSOR_H
#define ULTRASONIC_SENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
private:

    uint8_t _trigPin;
    uint8_t _echoPin;

public:
   UltrasonicSensor(uint8_t trigPin, uint8_t echoPin) : _trigPin(trigPin), _echoPin(echoPin) {}

   void begin(){
        pinMode(_trigPin, OUTPUT);
        pinMode (_echoPin, INPUT);
    }

    long readDistanceCm(){
        digitalWrite(_trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(_trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(_trigPin, LOW);

        long duration = pulseIn(_echoPin, HIGH, 30000);
        if(duration == 0){
            return -1;
        }
        return duration * 0.0343 / 2;

    }
};

#endif 