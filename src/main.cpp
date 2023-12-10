#include <Arduino.h>

#include <Servo.h>
#include "SerialCommunication.h"

Servo gripper;
SerialCommunication communication;

#define GRIPPER_OUTPUT_PIN PIN7

void setup() {
    Serial.begin(115200);                   // Start serial at baudrate of 115200
    Serial.setTimeout(10);                  // Set max timeout for waiting on chars to 10 ms for fast reactions

    gripper.attach(GRIPPER_OUTPUT_PIN);
}

void loop() {
  communication.loopSerialConnection();
}