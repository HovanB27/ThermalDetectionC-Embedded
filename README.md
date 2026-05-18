# ThermalDetection

Project description goes here

## Materials & Hardware

 * MLX90640 IR Array Thermal Imaging Camera
 * Raspberry Pi 4
 * Raspberry Pi Camera Module
 * Breadboard and jumper wires

%% Libraries & References

 * melexis/mlx90640-library (GitHub) — Official Melexis C driver: MLX90640_API.c/h, MLX90640_I2C_Driver.h
 * Linux kernel I2C headers: linux/i2c-dev.h, linux/i2c.h
 * Raspberry Pi 4 GPIO Pinout Reference

### Project Timeline

May 1 - 4: 6 Hours
> Project planning, Human detection system with a thermal, rapsberry pi, and camera.

May 5: 3 Hours
> Hardware research, MLX90640 IR Array Thermal Camera. Raspberry pi 4 setup.

May 6: 2 Hours
> Went over MLX90640 library and manufacterer documentation. Studied I2C communication fundamentals.

May 7: 3 Hours
> Studied thermal imaging, figured out accurate emissivity, reflected temperatures, pixel to temperature conversions.

May 8: 2 Hours
> Project file structure outlined chose CLion IDE and did some more planning

May 9: 3 Hours
> Studied Melexis library source code. Identified key functions to use (MLX90640_API.c, MLX90640_API.h). MLX90640_DumpEE, MLX90640_ExtractParameters, MLX90640_GetFrameData, MLX90640_CalculateTo)

May 10: 2 Hours
> Hardware organized set up planning. Organized available components, Rapsberry pi 4, MLX90640 themral. Decided to use terminal for outputs instead of buzzer because there were voltage issues.

May 11: 7 Hours
> Created ThermalDetection CLion project. Set up file structure: main.cpp, thermal.h, thermal.cpp, CMakeLists.txt, lib/mlx90640/. Configured CMakeLists.txt with C++17 standard. Researched melexis library on github cloned the library on mac terminal. Tracked down missing components. Set up Hardware and enabled I2C on Raspberry pi and wired MLX90640 to Pi GPIO: GND→Pin6, VCC→Pin1 (3.3V), SDA→Pin3, SCL→Pin5.

May 12: 5 Hours
> Transferred melexis library files from Mac to raspberry pi. Linux I2C driver implemntation completed. Finalized CMakeLists.txt added melexis headers and made sure each file was compatible with one another.

May 13: 5 Hours
> thermal.cpp implementation. Implemented initializeSensor(): MLX90640_I2CInit(), MLX90640_DumpEE() with error checking, MLX90640_ExtractParameters(). Implemented readFrame(): MLX90640_GetFrameData() with error checking.

May 14: 4 Hours
> Implemented detectHuman() implemented hot pixel counting loop with 30°C threshold and 20-pixel minimum blob size for human classification. Also implemented main.cpp implementation startup initialization with error handling. Implemented infinite while(true) detection loop calling readFrame() and detectHuman() with terminal output.

May 15: 3 Hours
> Last review over project. Resolved undefined reference link errors. Worked on compilation and debugging issues with Raspberry pi. Renamed MLX90640_I2C_Driver.cpp to .c to fix C/C++ linkage mismatch. Cleaned build directory. Then did some test runs to make sure evrything was working as wanted.
