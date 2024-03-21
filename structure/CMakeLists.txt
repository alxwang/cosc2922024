cmake_minimum_required(VERSION 3.27)
project(structure C)

set(CMAKE_C_STANDARD 90)

add_executable(structure main.c
        struct.h
        struct.c)
