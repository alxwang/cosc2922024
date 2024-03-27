//
// Created by Alex Wang on 2024-03-27.
//

#ifndef STUDENT_FILEIO_H
#define STUDENT_FILEIO_H
#include <stdio.h>
FILE* openFile(const char* fileName, const char* fileMode);

int readFile(FILE* filePtr, unsigned char * data, int bytesToRead);

int writeFile(FILE* filePtr, unsigned char * data, int bytesToWrite);
#endif //STUDENT_FILEIO_H
