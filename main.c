#define VERSION "0.1-b"

#include <stdio.h>
#include <string.h>
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
        if(strcmp("-h", argv[1]) == 0 || strcmp("-help", argv[1]) == 0 || strcmp("--h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0){
            printf("CaesarCipherTool - console tool for encrypting, decoding and bruting text with Caesar cipher.\n");
            printf("You can open it in console without arguments and work in console, or\n");
            printf("you can give to arguments 'operation' -e (to encrypt) or -d (to decode) at first argument,\n");
            printf("filename (in this directory only) to encrypt or decode at second argument\n");
            printf("and the key (offset) at third argument.\n");
        }
        else if(strcmp("-v", argv[1]) == 0 || strcmp("-version", argv[1]) == 0 || strcmp("--v", argv[1]) == 0 || strcmp("--version", argv[1]) == 0){
            printf("%s\n", VERSION);
        }
        else{
            //TODO: brute from file argv[1]
        }
    }
    else if(argc==4){
        if (argv[1] == "-e"){
            //TODO: encrypt argv[2] file to "decoded_{argv[2]}" by argv[3] key
        }
        else if (argv[1]== "-d"){
            //TODO: decode argv[2] file to "decoded_{argv[2]}" by argv[3] key
        }
    }
    else{
        printf("invalid arguments!\n");
    }
}