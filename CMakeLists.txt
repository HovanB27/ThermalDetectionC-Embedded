cmake_minimum_required(VERSION 3.10)
project(ThermalDetection)

set(CMAKE_CXX_STANDARD 17)

include_directories(lib/mlx90640/headers)

add_executable(ThermalDetection
        main.cpp
        thermal.cpp
        thermal.h
        lib/mlx90640/functions/MLX90640_API.c
        lib/mlx90640/functions/MLX90640_I2C_Driver.cpp
        lib/mlx90640/functions/MLX90640_I2C_Driver.cpp
)