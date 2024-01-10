#ifndef STEPPER_CONTROL_H
#define STEPPER_CONTROL_H

#include <Arduino.h>

#define LEFT LOW
#define RIGHT HIGH

class StepperControl
{
private:
    uint16_t currentSteps = 0;
    uint16_t endSteps = 0;
    float stepsPerPercentage = 0.0;

    uint8_t dirPin;
    uint8_t stepPin;
public:
    StepperControl(uint8_t directionPin, uint8_t stepsPin);
    ~StepperControl();

    void homeAxis();
    void moveAxis(uint8_t targetPosInPercentage);
};


#endif