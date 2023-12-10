#include <Arduino.h>

#include <Servo.h>
#include "SerialCommunication.h"

SerialCommunication communication;

void setup() {
    Serial.begin(115200);                   // Start serial at baudrate of 115200
    Serial.setTimeout(10);                  // Set max timeout for waiting on chars to 10 ms for fast reactions
}

void loop() {
  communication.loopSerialConnection();
}