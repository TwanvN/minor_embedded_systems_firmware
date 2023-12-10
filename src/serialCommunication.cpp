#include <Arduino.h>
#include "SerialCommunication.h"

SerialCommunication::SerialCommunication(/* args */)
{
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

        if (foundWords[0] == "newTargetPosition") {
            // Call new position to Position Class
            Serial.println("New target position received:");

            int size = foundWords[1].length();
            String xTargetPos = foundWords[1].substring(0, (size / 2));
            String yTargetPos = foundWords[1].substring((size / 2), size);

            Serial.println(xTargetPos + "," + yTargetPos);
        } else if (foundWords[0] == "newObjectDetected") {
            // Call gripper adjustment state in Gripper Overview class
            Serial.println("New gripper action received");
        }
    }
}