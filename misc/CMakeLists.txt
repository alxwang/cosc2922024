cmake_minimum_required(VERSION 3.27)
project(misc C)

set(CMAKE_C_STANDARD 99)

add_executable(misc main.c
        functions.h
        functions.c)
