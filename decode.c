#include "decode.h"

void decode(unsigned char *s, unsigned int key, size_t arrsizeof){
    key = key % 255;
    for(size_t i=0; i < arrsizeof / sizeof *s; i++){
        s[i] = (int)s[i] - key < 0 ? (unsigned char)(255 - (key - (int)s[i])) : (unsigned char)((int)s[i] - key);
    }
}