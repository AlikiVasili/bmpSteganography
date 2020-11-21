
/* bmpSteganography.c -- <-option> image1.bmp [image2.bmp image3.bmp ...]
*
* This is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License, see the file COPYING.
*/

#include <string.h>
#include "decodeStegano.h"
#include "encodeStegano.h"
#include "decodeText.h"
#include "encodeText.h"
#include "grayscale.h"
#include "listImg.h"

int main(int argc, char *argv[]){
    //printf("%d\n",argc);
    if(argc<=2){
        printf("bmpSteganography.c -- <-option> image1.bmp [image2.bmp image3.bmp ...]\n");
        printf("\nThis is free software; you can redistribute it and/or\n");
        printf("modify it under the terms of the GNU General Public\n");
        printf("License, see the file COPYING.\n\n");
        printf("No options or neccessary files given. Exiting.\n");
        return EXIT_FAILURE;
    }
    int i;
    if(strcmp(argv[1],"-list")==0){
        for(i=2;i<argc;i++){
            IMAGE *img = initImage(argv[i]);
            if(isUncompressed24bit(img)){
                list(img);
                printf("\n************************************************************\n");
            }
            deleteImage(img);
        }
        return 0;
    }
    if(strcmp(argv[1],"-grayscale")==0){
        for(i=2;i<argc;i++){
            IMAGE *img = initImage(argv[i]);
            if(img!=NULL){
                char *filename = malloc(sizeof(char)*(strlen(argv[i])+10));
                strcpy(filename,"grayscale-");
                grayscale_filter(img,strcat(filename,argv[i]));
                free(filename);
                deleteImage(img);
            }
        }
        return 0;
    }
    if(strcmp(argv[1],"-encodeStegano")==0){
        int  bits = atoi(argv[2]);
        if(bits<=0){
            printf("Incorrect format or input. Correct format is –encodeStegano nbBits coverImage.bmp secretImage.bmp\n");
            return EXIT_FAILURE;
        }
        IMAGE *cover = initImage(argv[3]);
        IMAGE *secret = initImage(argv[4]);
        if(cover==NULL || secret==NULL){
            printf("Incorrect format or input. Correct format is –encodeStegano nbBits coverImage.bmp secretImage.bmp\n");
            return EXIT_FAILURE;
        }
        char *filename = malloc(sizeof(char)*(strlen(argv[3])+4));
        strcpy(filename,"new-");
        strcat(filename,argv[3]);
        encodeStegano(cover,secret,bits,filename);
        free(filename);
        deleteImage(cover);
        deleteImage(secret);
    }
    if(strcmp(argv[1],"-decodeStegano")==0){
        int  bits = atoi(argv[2]);
        if(bits<=0){
            printf("Incorrect format or input. Correct format is –encodeStegano nbBits encryptedImage.bmp\n");
            return EXIT_FAILURE;
        }
        IMAGE *cover = initImage(argv[3]);
        if(cover==NULL){
            printf("Incorrect format or input. Correct format is –encodeStegano nbBits encryptedImage.bmp\n");
            return EXIT_FAILURE;
        }
        char *filename = malloc(sizeof(char)*(strlen(argv[3])+4));
        strcpy(filename,"new-");
        strcat(filename,argv[3]);
        decodeStegano(cover,bits,filename);
        free(filename);
        deleteImage(cover);
        return 0;
    }
    if(strcmp(argv[1],"-encodeText")==0){
        return 0;
    }




    return 0;
}