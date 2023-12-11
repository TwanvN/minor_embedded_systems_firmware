#ifndef POSITION_HANDLING_H
#define POSITION_HANDLING_H

#include <Arduino.h>
#include <stdint.h>

#include "StepperControl.h"

class PositionHandling
{
private:
    StepperControl* xAxis;
    StepperControl* yAxis;
public:
    PositionHandling();
    ~PositionHandling();

    void newPositionReceived(uint8_t xTargetPosition, uint8_t yTargetPosition);
};

#endif