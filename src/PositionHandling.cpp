#include "PositionHandling.h"

PositionHandling::PositionHandling()
{
    this->xAxis = new StepperControl(0, 1);
    this->yAxis = new StepperControl(0, 1);
}

PositionHandling::~PositionHandling()
{
}

void PositionHandling::newPositionReceived(uint8_t xTargetPosition, uint8_t yTargetPosition) {

}