//
// Created by Hovannes Baboudjian on 5/11/26.
//

#include "thermal.h"
#include <iostream>

extern "C" {
#include "MLX90640_API.h"
#include "MLX90640_I2C_Driver.h"
}

bool initializeSensor(uint8_t slaveAddr, uint16_t* eeData, paramsMLX90640* params)
{
    MLX90640_I2CInit();

    if (const int eepromReading = MLX90640_DumpEE(slaveAddr, eeData); eepromReading < 0)
    {
        return false;
    }

    MLX90640_ExtractParameters(eeData, params);
    return true;
}

bool readFrame(uint8_t slaveAddr, uint16_t* frameData)
{
    int frameReading = MLX90640_GetFrameData(slaveAddr, frameData);

    if (frameReading < 0)
    {
        return false;
    }
    return true;
}

bool detectHuman(uint16_t* frameData, paramsMLX90640* params)
{
    float result[768];

    constexpr float humanEmissivity = 0.95f;
    constexpr float roomTemperature = 23.0f;

    MLX90640_CalculateTo(frameData, params, humanEmissivity, roomTemperature, result);

    int humanPixelCount = 0;

    for (const float i : result)
    {
        if (i > 30.0f)
        {
            humanPixelCount++;
        }
        if (humanPixelCount >= 20)
        {
            return true;
        }
    }

    return false;
}
