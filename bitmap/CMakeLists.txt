cmake_minimum_required(VERSION 3.27)
project(bitmap C)

set(CMAKE_C_STANDARD 90)
add_executable(bitmap main.c
        bitmap.h
        bitmap.c)
