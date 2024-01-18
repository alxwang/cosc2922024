cmake_minimum_required(VERSION 3.27)
project(header C)

set(CMAKE_C_STANDARD 11)

add_executable(header main.c
        test.h
        test.c
        other.c
        other.h)
