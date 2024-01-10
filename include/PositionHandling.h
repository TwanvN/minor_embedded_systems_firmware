#ifndef POSITION_HANDLING_H
#define POSITION_HANDLING_H

#include <Arduino.h>
#include <stdint.h>

#include "StepperControl.h"

enum AXIS
{
    X = 0,
    Y = 1
};

struct Position
{
    uint8_t x;
    uint8_t y;
};


class PositionHandling
{
private:
    StepperControl *xAxis;
    StepperControl *yAxis;

public:
    PositionHandling();
    ~PositionHandling();

    void moveGivenAxis(AXIS axis, uint8_t moveToPercentage);
    void homeBothAxis();
    void moveToPosition(Position targetPos);
    void moveToDetections(String listOfPositions);
};

#endif