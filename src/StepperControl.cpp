#include "StepperControl.h"

StepperControl::StepperControl(uint8_t directionPin, uint8_t stepsPin, uint8_t homeButtonPin)
{
    this->dirPin = directionPin;
    this->stepPin = stepsPin;

    this->homePin = homeButtonPin;

    pinMode(this->dirPin, OUTPUT);
    pinMode(this->stepPin, OUTPUT);

    pinMode(this->homePin, INPUT);

    this->homeAxis();
}

StepperControl::~StepperControl()
{
}

void StepperControl::homeAxis()
{
    digitalWrite(this->dirPin, LEFT);

    while (!digitalRead(this->homePin))
    {
        digitalWrite(this->stepPin, HIGH);
        delayMicroseconds(500);
        digitalWrite(this->stepPin, LOW);
        delayMicroseconds(500);
    }

    Serial.println("Found home position");

    Serial.println("Done homing");
}

void StepperControl::moveAxis(uint8_t targetPosInPercentage)
{
    uint16_t percentageInSteps = static_cast<uint16_t>(targetPosInPercentage * this->stepsPerPercentage);
    int stepsToTake = (percentageInSteps - this->currentSteps);

    if (stepsToTake < 0)
    {
        stepsToTake *= -1;
        digitalWrite(this->stepPin, LEFT);

        for (int i = 0; i < stepsToTake; i++)
        {
            digitalWrite(this->stepPin, HIGH);
            delayMicroseconds(500);
            digitalWrite(this->stepPin, LOW);
            delayMicroseconds(500);

            this->currentSteps--;
        }
    }
    else if (stepsToTake > 1)
    {
        digitalWrite(this->stepPin, RIGHT);

        for (int i = 0; i < stepsToTake; i++)
        {
            digitalWrite(this->stepPin, HIGH);
            delayMicroseconds(500);
            digitalWrite(this->stepPin, LOW);
            delayMicroseconds(500);

            this->currentSteps++;
        }
    } else {
        return;
    }
}