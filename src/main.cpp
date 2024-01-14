#include <Arduino.h>

#include <Servo.h>
#include "SerialCommunication.h"

SerialCommunication* communication;

void setup() {
    Serial.begin(9600);
}

void loop() {
  communication->loopSerialConnection();
  delay(5);
}