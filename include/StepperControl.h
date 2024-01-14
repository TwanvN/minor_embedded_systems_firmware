#ifndef STEPPER_CONTROL_H
#define STEPPER_CONTROL_H

#include <Arduino.h>

#define LEFT LOW
#define RIGHT HIGH
#define MAX_DISTANCE_IN_STEPS 1000

class StepperControl
{
private:
    uint16_t currentSteps = 0;
    float stepsPerPercentage = MAX_DISTANCE_IN_STEPS / 100;

    uint8_t dirPin;
    uint8_t stepPin;
    uint8_t homePin;
public:
    StepperControl(uint8_t directionPin, uint8_t stepsPin, uint8_t homeButtonPin);
    ~StepperControl();

    void homeAxis();
    void moveAxis(uint8_t targetPosInPercentage);
};


#endif