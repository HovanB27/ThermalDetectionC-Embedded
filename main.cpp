#include <cstdint>

#include "MLX90640_API.h"
#include "thermal.h"
#include <iostream>
//
// Created by Hovannes Baboudjian on 5/1/26.
//
int main() {
    uint8_t slaveAddr = 0x33;
    uint16_t eeData[832];
    paramsMLX90640 params;
    uint16_t frameData[834];

    if (bool success = initializeSensor(slaveAddr, eeData, &params); !success) {
        std::cout << "Sensor initialization failed" << std::endl;
        return -1;
    }

    while (true)
    {
        readFrame(slaveAddr, frameData);
        if (bool result = detectHuman(frameData, &params))
        {
            std::cout << "Human detected" << std::endl;
        } else
        {
            std::cout << "Human not detected" << std::endl;
        }
    }
    return 0;
}