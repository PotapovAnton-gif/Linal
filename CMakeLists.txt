cmake_minimum_required(VERSION 3.13.0)

project(CMAKE_Linal)

set(CMAKE_GXX_STANDART 11)

file(GLOB
        cpps "*.cpp"    )

add_executable(${PROJECT_NAME} ${cpps})  