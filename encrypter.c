#include "encrypter.h"

void encrypt(unsigned char *s, unsigned int step, size_t arrsizeof){
    step = step % 255;
    for(size_t i=0; i < arrsizeof; i++){
        s[i] = (int)s[i] + step > 255 ? (unsigned char)  (step - (255-(int)s[i])) : (unsigned char) ((int)s[i] + step);
    }
        
}