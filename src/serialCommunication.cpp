#include <Arduino.h>
#include "SerialCommunication.h"

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

        if (command == "home") {
            // Start homing
        } else if (command == "move_axis") {
            // Move given axis to certain pos
        } else if (command == "target_pos") {
            // Move both axis to given pos
        } else if (command == "new_detections") {
            // Move to multiple pos
        } else {
            Serial.println("Command unknown");
        }
    }
}