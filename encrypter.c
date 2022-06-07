#include "encrypter.h"

void encrypt(unsigned char *s, int step, size_t arrsizeof){
    step = step % 25;
    for(size_t i=0; i < arrsizeof / sizeof *s; i++)
        s[i] = (int)s[i] + step > 122 ? (unsigned char) (96 + (step - (122-(int)s[i]))) : (unsigned char) ((int)s[i] + step);
}