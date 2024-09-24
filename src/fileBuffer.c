//This src file handles the buffer that contains what is read from the file given as an arg to the program

#include <stdio.h> //Get FILE library support
#include <stdlib.h>
#include "fileBuffer.h"

#define FILEBUFFERSIZE 8192 // 2^13 bytes. Char = 1 byte, 512 blocks

unsigned char fileBuf[FILEBUFFERSIZE]; //Hold the characters 
static int fileFreePos = 0; //Free pos in the buffer

void fileBufferRead(FILE *fptr, int *fileSize) {

    int ch; //int to hold the EOF signal
    while ((ch = getc(fptr)) != EOF) {//Get next char, assign it to ch, check if we just received EOF
        fileBuf[fileFreePos++] = ch;

         if (fileFreePos == FILEBUFFERSIZE + 1) { //Abort program if file length too long
            printf("File length is too long: Exited\n");
            exit(EXIT_FAILURE);
        }  
    }

    fclose(fptr); //close the ptr
    *fileSize = fileFreePos;

    return;
}