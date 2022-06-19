#define VERSION "0.5.1"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encrypter.h"
#include "decode.h"

void unknownCommand(){
    printf("Unknown command!\n");
    printf("You can use:\n-e [filename] [step-key] to encrypt string from [filename];\n");
    printf("-d [filename] [step-key] to decode string from [filename]\n");
    printf("-i [word] [step-key] to encrypt single word from command line\n");
    printf("[filename] to decode text with bruting.\n");
    printf("-w [word] [step-key] to decode single word from command line\n");
    printf("-h for help and -v for version\n");
}

int main(int argc, char *argv[]){
    if(argc==2){
        if(strcmp("-h", argv[1]) == 0 || strcmp("-help", argv[1]) == 0 || strcmp("--h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0){
            printf("CaesarCipherTool - console tool for encoding, decoding and bruting text with Caesar cipher.\n");
            printf("You can use:\n-e [filename] [step-key] to encrypt text from [filename];\n");
            printf("-d [filename] [step-key] to decode text from [filename]\n");
            printf("-i [word] [step-key] to encrypt single word from command line\n");
            printf("[filename] to decode text with bruting.\n");
            printf("-w [word] [step-key] to decode single word from command line\n");
            printf("-h for help and -v for version\n");
        }
        else if(strcmp("-v", argv[1]) == 0 || strcmp("-version", argv[1]) == 0 || strcmp("--v", argv[1]) == 0 || strcmp("--version", argv[1]) == 0){
            printf("   ___ ___ _____ \n");
            printf("  / __/ __|_   _|\n");
            printf(" | (_| (__  | |  \n");
            printf("  \\___\\___| |_|  \n");
            printf("Version %s\n", VERSION);
            printf("Website - https://nichney.ru \nGithub - https://github.com/Karasik-piiiip/CaesarCipherTool \n");
        }
        else{
            char filename[strlen(argv[1]) + 1];
            strcpy(filename, argv[1]);
            long size;
            FILE *fp;

            fp = fopen(filename, "r");
            fseek(fp, 0L, SEEK_END);
            size = ftell(fp);
            fseek(fp, 0L, SEEK_SET);
            unsigned char buf[size];
            fread(buf, 1, size, fp);
            fclose(fp);

            char template[255] = "bruted_";
            strcat(template, filename);
            fp = fopen(template, "w");
            char newline[] = "\n";
            
            for(int key=1; key < 255; key++){
                decode(buf, key, size);
                fwrite(buf, 1, size, fp);
                fwrite(newline, 1, 1, fp);
            }
            fclose(fp);  
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

            decode(buf, key, size);
            printf("%s\n", buf);

            char template[255] = "decoded_";
            strcat(template, filename);
            fp = fopen(template, "w");
            fwrite(buf, 1, size, fp);
            fclose(fp);
        }
        else if (strcmp("-i", argv[1]) == 0){
            unsigned char text[strlen(argv[2]) + 1];
            strcpy(text, argv[2]);
            unsigned int key = atoi(argv[3]);
            encrypt(text, key, sizeof(text));
            printf("%s\n", text);
        }
        else if (strcmp("-w", argv[1]) == 0){
            unsigned char text[strlen(argv[2]) + 1];
            strcpy(text, argv[2]);
            unsigned int key = atoi(argv[3]);
            decode(text, key, sizeof(text));
            printf("%s\n", text);
        }
        else{
            unknownCommand();
        }
    }
    else{
        unknownCommand();
    }
}