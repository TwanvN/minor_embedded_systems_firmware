#ifndef POSITION_HANDLING_H
#define POSITION_HANDLING_H

#include <stdint.h>

class PositionHandling
{
private:
    uint16_t currentSteps = 0;
    uint16_t endSteps = 0;

    void homeAxis();
    void moveAxis();
public:
    PositionHandling();
    ~PositionHandling();

    void newPositionReceived();
};

#endif