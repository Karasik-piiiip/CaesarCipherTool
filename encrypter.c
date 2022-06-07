#include "encrypter.h"

void encrypt(unsigned char *s, unsigned int step, size_t arrsizeof){
    step = step % 25;
    for(size_t i=0; i < arrsizeof; i++){
        if((int)s[i]>=97 && (int)s[i]<=122)
            s[i] = (int)s[i] + step > 122 ? (unsigned char) (96 + (step - (122-(int)s[i]))) : (unsigned char) ((int)s[i] + step);
    }
        
}