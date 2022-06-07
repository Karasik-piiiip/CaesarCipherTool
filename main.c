#define VERSION "0.1-b"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        unsigned char a[] = "abz\n";
        decode(a, 1, sizeof(a));
        for(int i=0; i< 6; i++)
            printf("%c", a[i]);
    }
    else if(argc==2){
        if(strcmp("-h", argv[1]) == 0 || strcmp("-help", argv[1]) == 0 || strcmp("--h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0){
            printf("CaesarCipherTool - console tool for encrypting, decoding and bruting text with Caesar cipher.\n");
            printf("You can open it in console without arguments and work in console, or\n");
            printf("you can give to arguments 'operation' -e (to encrypt) or -d (to decode) at first argument,\n");
            printf("filename (in this directory only) to encrypt or decode at second argument\n");
            printf("and the key (offset) at third argument.\n");
            printf("Use -i to encrypt text in command line without writing to file and\n");
            printf("-w to decode without writing to file.\n");
        }
        else if(strcmp("-v", argv[1]) == 0 || strcmp("-version", argv[1]) == 0 || strcmp("--v", argv[1]) == 0 || strcmp("--version", argv[1]) == 0){
            printf("%s\n", VERSION);
        }
        else{
            //TODO: brute from file argv[1]
        }
    }
    else if(argc>=3){
        if (strcmp("-e", argv[1]) == 0){
            char filename[strlen(argv[2]) + 1];
            strcpy(filename, argv[2]);
            unsigned int key = atoi(argv[3]);
            long size;
            FILE *fp;

            fp = fopen(filename, "r");
            fseek(fp, 0L, SEEK_END);
            size = ftell(fp);
            fseek(fp, 0L, SEEK_SET);
            unsigned char buf[size];
            fread(buf, 1, size, fp);
            fclose(fp);

            encrypt(buf, key, size);
            printf("%s\n", buf);

            char template[255] = "encrypted_";
            strcat(template, filename);
            fp = fopen(template, "w");
            fwrite(buf, 1, size, fp);
            fclose(fp);
        }
        else if (strcmp("-d", argv[1]) == 0){
            //TODO: decode argv[2] file to "decoded_{argv[2]}" by argv[3] key
        }
        else if (strcmp("-i", argv[1]) == 0){
            //TODO: decode string at argv[2] and print it.
        }
    }
    else{
        printf("invalid arguments!\n");
    }
}