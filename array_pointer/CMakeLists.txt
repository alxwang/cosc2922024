cmake_minimum_required(VERSION 3.27)
project(array_pointer C)

set(CMAKE_C_STANDARD 99)

add_executable(array_pointer main.c
        array_pointers.h
        array_pointers.c
        printmem.c
        printmem.h)
