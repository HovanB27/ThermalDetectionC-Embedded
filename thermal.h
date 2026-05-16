// Inputs:
#ifndef THERMALDETECTION_THERMAL_H
#define THERMALDETECTION_THERMAL_H

#include <cstdint>

extern "C" {
#include "MLX90640_API.h"
#include "MLX90640_I2C_Driver.h"
}

bool initializeSensor(uint8_t slaveAddr, uint16_t *eeData, paramsMLX90640 *params);
//
// uint8_t slaveAddr — the I2C address of your sensor, which will always be 0x33 for the MLX90640. Main passes this in so the function knows which device to talk to on the I2C bus
// uint16_t *eeData — a pointer to a buffer of 832 unsigned 16-bit integers. This is where the raw EEPROM data gets stored. Main declares this array and passes it in
// paramsMLX90640 *params — a pointer to the params struct. Main declares this too and passes it in. The function will fill it with the extracted calibration data
//
// Output:
//
// bool — simply true if both the EEPROM dump and parameter extraction succeeded, false if either one failed

// Call MLX90640_DumpEE with the address and eeData buffer, check if the return value indicates an error
// If step 1 failed, return false immediately
// Call MLX90640_ExtractParameters with eeData and params
// If everything worked, return true

bool readFrame(uint8_t slaveAddr, uint16_t *frameData);
// Inputs:
//
// uint8_t slaveAddr — the I2C address of your sensor, always 0x33 for the MLX90640.
// Main passes this in so the function knows which device to read from on the I2C bus
//
// uint16_t *frameData — a pointer to a buffer of 834 unsigned 16-bit integers.
// Main declares this array and passes it in empty. The function fills it with
// raw pixel data and housekeeping values from the sensor as a side effect.
// 768 of those slots are pixel readings, the remaining 66 are sensor bookkeeping data.
//
// Output:
//
// bool — true if the frame was read successfully, false if anything went wrong
// Logic the implementation will follow:
// Call MLX90640_GetFrameData with the address and frameData buffer
// If it returns a negative value, return false immediately
// If it succeeded, return true

bool detectHuman(uint16_t *frameData, paramsMLX90640 *params);
// Inputs:
//
// uint16_t *frameData — a pointer to the 834-element buffer that readFrame just filled.
// Main owns this array and passes it in so detectHuman can convert it to temperatures
//
// paramsMLX90640 *params — a pointer to the calibration params struct that
// initializeSensor filled. Needed by CalculateTo to produce accurate temperatures
//
// Output:
//
// bool — true if a human-sized heat blob is detected in the frame, false otherwise

// Logic the implementation will follow:
// Declare a float result[768] array internally to hold the temperature of each pixel
// Hardcode emissivity as 0.95 (human skin) and try as your room temperature
// Call MLX90640_CalculateTo with frameData, params, emissivity, tr, and result
// Scan the 768 floats and find pixels above your heat threshold (~30.0 degrees)
// Group connected hot pixels together into blobs
// Check if any blob is large enough to be a human (minimum pixel count)
// If a human-sized blob exists, return true, otherwise return false
#endif //THERMALDETECTION_THERMAL_H