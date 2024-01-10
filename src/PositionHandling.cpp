#include "PositionHandling.h"

PositionHandling::PositionHandling()
{
    this->xAxis = new StepperControl(0, 1);
    this->yAxis = new StepperControl(0, 1);
}

PositionHandling::~PositionHandling()
{
}

void PositionHandling::moveGivenAxis(AXIS axis, uint8_t moveToPercentage)
{
    switch (axis)
    {
    case AXIS::X:
        /* code */
        break;

    case AXIS::Y:

        break;

    default:
        break;
    }
}

void PositionHandling::homeBothAxis()
{
    this->xAxis->homeAxis();
    this->yAxis->homeAxis();
}

void PositionHandling::moveToPosition(Position targetPos)
{
    this->xAxis->moveAxis(targetPos.x);
    this->yAxis->moveAxis(targetPos.y);
}

void PositionHandling::moveToDetections(String listOfPositions)
{
    String foundPositions[10];
    int positionCount = 0;

    while (listOfPositions.length() > 0)
    {
        int index = listOfPositions.indexOf(';');
        if (index == -1) // No space found
        {
            foundPositions[positionCount++] = listOfPositions;
            break;
        }
        else
        {
            foundPositions[positionCount++] = listOfPositions.substring(0, index);
            listOfPositions = listOfPositions.substring(index + 1);
        }
    }
    
    Position calculatedPositions[positionCount];

    for (int i = 0; i < positionCount; i++)
    {
        struct Position pos = {static_cast<uint8_t>(foundPositions[i].charAt(0)), static_cast<uint8_t>(foundPositions[i].charAt(2))};
        calculatedPositions[i] = pos;
    }

    for (Position pos : calculatedPositions) {
        this->moveToPosition(pos);
        delay(5);
    }
    
}