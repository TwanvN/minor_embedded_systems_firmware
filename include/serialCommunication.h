#ifndef SERIAL_COMMUNICATION_H
#define SERIAL_COMMUNICATION_H

#include "PositionHandling.h"

class SerialCommunication
{
    private:
        PositionHandling* positionHandler;
    public:
        SerialCommunication();
        ~SerialCommunication();

        void loopSerialConnection();
};

#endif