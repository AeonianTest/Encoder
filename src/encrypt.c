//Center of all things that handle the enrcyption of the data 

#include "encrypt.h"

extern char fileBuf[]; //Buffer that holds the files contents, defined in fileBuffer.c

void encrypt(int fileSize) { //accept fileSize (Number of Bytes)
    int filePos = 0;
    unsigned char stateArray[16];

    while (filePos < fileSize) { //while position in buffer is less then the elements in it
        filePos++; //temp
    }

    return; //return to main
}