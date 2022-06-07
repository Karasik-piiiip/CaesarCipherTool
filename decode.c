#include "decode.h"

void decode(unsigned char *s, int key, size_t arrsizeof){
    key = key % 25;
    for(size_t i=0; i < arrsizeof / sizeof *s; i++)
        s[i] = (int)s[i] - key < 97 ? (unsigned char)(122 - (key - ((int)s[i] - 96))) : (unsigned char)((int)s[i] - key);
}