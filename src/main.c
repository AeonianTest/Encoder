//Core of program. Can revise as needed to add more features/revise as needed

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "fileBuffer.h"
#include "keySchedule.h"
#include "encrypt.h"

extern char fileBuf[]; //Buffer that holds the files contents, defined in fileBuffer.c

int main(int argc, char *argv[]) { //The menu of options will have to be revised to be more responsive/protective of user

    //Review args given
    if (argc == 1) { //Check if no args passed
        printf("No arguments passed to program: Exited\n");
        exit(EXIT_FAILURE);
    }
    if (argc == 2) { //Check if insufficient args passed
        printf("Insufficient arguments provided to program: Exited\n");
        exit(EXIT_FAILURE);
    }

    char *filename1 = argv[1]; //Get the second arg, a pointer to the filename
    FILE *fptr = NULL;

    //Check if the file exists
    if ((fptr = fopen(filename1, "r")) == NULL) { // if fopen returns an error (NULL value) because it cant find the file
        printf("No such file found under %s: Exited\n", filename1);
        exit(EXIT_FAILURE);
    }

    int arg2length = 0;
    char *keyPhrase = argv[2];
    for (; *(keyPhrase + arg2length) != '\0'; ++arg2length) 
        ;
    
    if (arg2length != 16) {
        printf("Keyphrase \"%s\" is not 16 characters: Exited\n", keyPhrase); 
        exit(EXIT_FAILURE);
    }

    int fileSize; //fileSize in bytes/chars
    fileBufferRead(fptr, &fileSize); //read the contents of the file into fileBuf, return the filesize
    printf("%d\n", fileSize); //testing

    // For testing print out the file contents
    for (int i = 0; fileBuf[i] != '\0'; ++i) 
        printf("%c", fileBuf[i]);
    printf("\n");
    //

    memset(keyPhrase, 0, strlen(keyPhrase)); //Testing keyphrases. Assign it all to \0

    keySchedule(keyPhrase); //call the key generation
    encrypt(fileSize); //call the encyption process over fileBuf
    
    return EXIT_SUCCESS; //Return a successful execution of the program
}