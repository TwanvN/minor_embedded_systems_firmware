#include <Arduino.h>
#include "SerialCommunication.h"
#include <stdlib.h>

SerialCommunication::SerialCommunication(/* args */)
{
    this->positionHandler = new PositionHandling();
}

SerialCommunication::~SerialCommunication()
{
}

void SerialCommunication::loopSerialConnection()
{
    if (Serial.available() > 0)
    {
        String input = Serial.readString();
        String foundWords[2];
        int wordsCount = 0;

        while (input.length() > 0)
        {
            int index = input.indexOf(' ');
            if (index == -1) // No space found
            {
                foundWords[wordsCount++] = input;
                break;
            }
            else
            {
                foundWords[wordsCount++] = input.substring(0, index);
                input = input.substring(index + 1);
            }
        }

        String command = foundWords[0];

        if (command == "homeAxis") {
            // Start homing
            AXIS targetAxis = static_cast<AXIS>(atoi(foundWords[1].c_str()));
            this->positionHandler->homeGivenAxis(targetAxis);

        } else if (command == "newAxisPos") {
            // Move given axis to certain pos
            AXIS targetAxis = static_cast<AXIS>(atoi(foundWords[1].c_str()));
            this->positionHandler->moveGivenAxis(targetAxis, atoi(foundWords[2].c_str()));

        } else if (command == "newTargetPos") {
            // Move both axis to given pos
            uint8_t xValue = atoi(foundWords[1].substring(0, foundWords[1].indexOf(",")).c_str());
            uint8_t yValue = atoi(foundWords[1].substring(foundWords[1].indexOf(",") + 1).c_str());

            Position targetPos;
            targetPos.x = xValue;
            targetPos.y = yValue;

            this->positionHandler->moveToPosition(targetPos);

        } else if (command == "new_detections") {
            // Move to multiple pos
            this->positionHandler->moveToDetections(foundWords[1]);
        } else {
            Serial.println("Command unknown");
        }
    }
}