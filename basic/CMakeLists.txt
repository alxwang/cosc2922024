cmake_minimum_required(VERSION 3.27)
project(basic C)

set(CMAKE_C_STANDARD 99)

add_executable(basic main.c
        strfuncs.h
        strfuncs.c)
