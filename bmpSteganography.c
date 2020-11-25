
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
#include "stringToImage.h"
//#include "imageToString.h"

static void listOptions(){
    printf("Available functions:\n");
    printf("-list image1.bmp [image2.bmp image3.bmp ...]\n");
    printf("-grayscale image1.bmp [image2.bmp image3.bmp ...]\n");
    printf("-encodeStegano numOffBits coverImg.bmp secretImage.bmp\n");
    printf("-decodeStegano numOffBits encryptedImage.bmp\n");
    printf("–encodeText coverImage.bmp inputText.txt\n");
    printf("–decodeText encryptedImage.bmp msgLength output.txt\n");
    printf("–stringToImage sampleImage.bmp inputText.txt\n");
    printf("–imageToString sampleImage.bmp inputText.txt\n");
}

int main(int argc, char *argv[]){
    if(argc<=2){
        printf("bmpSteganography.c -- <-option> image1.bmp [image2.bmp image3.bmp ...]\n");
        printf("\nThis is free software; you can redistribute it and/or\n");
        printf("modify it under the terms of the GNU General Public\n");
        printf("License, see the file COPYING.\n\n");
        listOptions();
        printf("No options or neccessary files given. Exiting.\n");
        return EXIT_FAILURE;
    }
    int i;
    if(strcmp(argv[1],"-list")==0){
        for(i=2;i<argc;i++){
            IMAGE *img = initImage(argv[i]);
            if(img!=NULL){
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
		IMAGE *image = initImage(argv[2]);
        if(image==NULL)
            return EXIT_FAILURE;
		char *filename = malloc(sizeof(char)*(strlen(argv[2])));
        strcpy(filename,"new-");
		encodeText(image,argv[3],strcat(filename,argv[2]));
		free(filename);
		deleteImage(image);
        return 0;
    }
	if(strcmp(argv[1],"-decodeText")==0){
		IMAGE *image = initImage(argv[2]);
		int length = atoi(argv[3]);
		decodeText(image, length, argv[4]);
        deleteImage(image);
		return 0;
	}
	if(strcmp(argv[1],"-stringToImage")==0){
		char *newFile = malloc(sizeof(char)*(strlen(argv[2])));
        strcpy(newFile,"new-");
		strcat(newFile,argv[2]);
		stringToImage(argv[2],argv[3],newFile);
        free(newFile);
	}
	/*if(strcmp(argv[1],"-imageToString")==0){
		IMAGE *image = initImage(argv[2]);
		imageToString(image);
	}*/
    return 0;
}