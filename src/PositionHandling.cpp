#include "PositionHandling.h"

PositionHandling::PositionHandling()
{
    this->xAxis = new StepperControl(PD2, PD5, 9);
    this->yAxis = new StepperControl(PD3, PD6, 10);
}

PositionHandling::~PositionHandling()
{
}

void PositionHandling::moveGivenAxis(AXIS axis, uint8_t moveToPercentage)
{
    switch (axis)
    {
    case AXIS::X:
        Serial.println("Moving X-axis");
        this->xAxis->moveAxis(moveToPercentage);
        break;

    case AXIS::Y:
        Serial.println("Moving Y-axis");
        this->yAxis->moveAxis(moveToPercentage);
        break;

    default:
        break;
    }
}

void PositionHandling::homeGivenAxis(AXIS axis)
{
    switch (axis)
    {
    case AXIS::X:
        Serial.println("Homing X-axis");
        this->xAxis->homeAxis();
        break;

    case AXIS::Y:
        Serial.println("Homing Y-axis");
        this->yAxis->homeAxis();
        break;

    case AXIS::ALL:
        Serial.println("Homing all axis");
        this->xAxis->homeAxis();
        this->yAxis->homeAxis();
        break;

    default:
        break;
    }
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
        if (index == -1) // No ; found
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