#include <stdio.h>
#include "encrypter.h"
#include "decode.h"

int main(int argc, char *argv[]){
    /*
    'a' on unsigned char = 97
    'z' on unsigned char = 122
    '0' on unsigned char = 48
    '9' on unsigned char = 57
    */
    if(argc==1){
        // TODO: inprogram interface.

        // Test funcs
        unsigned char a[] = {'a', 'b', 'z'};
        encrypt(a, 2, sizeof(a));
        decode(a, 2, sizeof(a));
        for(int i=0; i< 3; i++)
            printf("%c\n", a[i]);
    }
    else if(argc==2){
        //TODO: brute from file argv[0]
    }
    else if(argc==4){
        if (argv[0] == "-e"){
            //TODO: encrypt argv[1] file to "decoded_{argv[1].txt}" by argv[2] key
        }
        else if (argv[0]== "-d"){
            //TODO: decode argv[1] file to "decoded_{argv[1].txt}" by argv[2] key
        }
    }
    else{
        printf("invalid arguments!\n");
    }
    

    
}