#include "StepperControl.h"

StepperControl::StepperControl(uint8_t directionPin, uint8_t stepsPin)
{
    this->dirPin = directionPin;
    this->stepPin = stepsPin;

    pinMode(this->dirPin, OUTPUT);
    pinMode(this->stepPin, OUTPUT);

    this->homeAxis();
}

StepperControl::~StepperControl()
{
}

void StepperControl::homeAxis() {
    digitalWrite(this->dirPin, LEFT);

    while (true) { //TODO: Add check for homing button
        digitalWrite(this->stepPin, HIGH);
		delayMicroseconds(500);
		digitalWrite(this->stepPin, LOW);
		delayMicroseconds(500);
    }

    Serial.println("Found home position");
    
    digitalWrite(this->dirPin, RIGHT);

    while (true) { //TODO: Add check for end position button
        digitalWrite(this->stepPin, HIGH);
		delayMicroseconds(500);
		digitalWrite(this->stepPin, LOW);
		delayMicroseconds(500);

        this->currentSteps++;
    }

    this->endSteps = this->currentSteps;

    Serial.println("Found end position");

    digitalWrite(this->dirPin, LEFT);

    while (this->currentSteps > 0) {
        digitalWrite(this->stepPin, HIGH);
		delayMicroseconds(500);
		digitalWrite(this->stepPin, LOW);
		delayMicroseconds(500);

        this->currentSteps--;
    }

    Serial.println("Done homing");

}

void StepperControl::moveAxis() {

}