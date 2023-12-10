#include <Arduino.h>

#include <Servo.h>

Servo gripper;

#define GRIPPER_OUTPUT_PIN PIN7

void setup() {
    gripper.attach(GRIPPER_OUTPUT_PIN);
}

void loop() {
  
}