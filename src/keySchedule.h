#ifndef KEYSCHEDULE
#define KEYSCHEDULE

typedef struct roundKey roundKey;
struct roundKey { //Structure for holding the round keys, global as its in header (move back if we dont need it)
    unsigned char word0[4]; //First COLUMN of the array, etc vals 0 - 255
    unsigned char word1[4];
    unsigned char word2[4];
    unsigned char word3[4];
    unsigned char fullString[17]; //Final part + \0 ? Prob not needed
}; 

void keySchedule(char *keyPhrase); //core of the key expansion alg

//3 operations performed on a given word
void rotWord(roundKey *keyCurrent, roundKey *keyPrevious); //Take two keys ptrs, the previous one from array at the one we are creating 
void subWord(roundKey *keyCurrent); //substitue bytes in the word on the precomputed S-box table
void rCon(roundKey *keyCurrent);

void fillRK(roundKey *keyCurrent, roundKey *keyPrevious); //Fill out the rest of the array after 3 ops computed

#endif