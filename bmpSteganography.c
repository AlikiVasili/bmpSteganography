
/* bmpSteganography.c -- <-option> image1.bmp [image2.bmp image3.bmp ...]
*
* This is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License, see the file COPYING.
*/

#include "decodeStegano.h"
#include "encodeStegano.h"
#include "decodeText.h"
#include "encodeText.h"
#include "grayscale.h"
#include "listImg.h"
#include "stringToImage.h"
#include "imageToString.h"

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
    //Check if the minimum amount of arguments has been given.
    if(argc<=1){
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
        //Call list for all images given.
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
            //Check if the image was opened.
            if(img!=NULL){
                char *filename = malloc(sizeof(char)*(strlen(argv[i])+10)); //Create the new file name
                strcpy(filename,"grayscale-");
                grayscale_filter(img,strcat(filename,argv[i])); //Apply the effect
                free(filename);
                deleteImage(img);   //Free the allocated memory
            }
        }
        return 0;
    }
    if(strcmp(argv[1],"-encodeStegano")==0){
        int  bits = atoi(argv[2]); //Amount of bits to encode
        if(bits<=0 || bits>=8){
            printf("Incorrect format or input. Correct format is –encodeStegano nbBits coverImage.bmp secretImage.bmp\n");
            printf("nbBits has to be a integer between 1-7\n");
            return EXIT_FAILURE;
        }
        IMAGE *cover = initImage(argv[3]);
        IMAGE *secret = initImage(argv[4]);
        if(cover==NULL || secret==NULL){
            printf("Incorrect format or input. Correct format is –encodeStegano nbBits coverImage.bmp secretImage.bmp\n");
            return EXIT_FAILURE;
        }
        char *filename = malloc(sizeof(char)*(strlen(argv[3])+4)); //Create new image name
        strcpy(filename,"new-");
        strcat(filename,argv[3]);
        encodeStegano(cover,secret,bits,filename);  //create the new image
        free(filename);
        deleteImage(cover);             //free the allocated memory.
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
        char *filename = malloc(sizeof(char)*(strlen(argv[3])+4)); //Create new image name
        strcpy(filename,"new-");
        strcat(filename,argv[3]);
        decodeStegano(cover,bits,filename); //Decrypt image
        free(filename);
        deleteImage(cover);     //free allocated memory.
        return 0;
    }
	if(strcmp(argv[1],"-encodeText")==0){
		IMAGE *image = initImage(argv[2]);
        if(image==NULL)
            return EXIT_FAILURE;
		char *filename = malloc(sizeof(char)*(strlen(argv[2])));    //Create new image name
        strcpy(filename,"new-");
		encodeText(image,argv[3],strcat(filename,argv[2]));     //Encrypt text.
		free(filename);
		deleteImage(image);         //free allocated memory.
        return 0;
    }
	if(strcmp(argv[1],"-decodeText")==0){
		IMAGE *image = initImage(argv[2]);
        if(image==NULL)
            return EXIT_FAILURE;
		int length = atoi(argv[3]);
		decodeText(image, length, argv[4]);     //Decrypt the text.
        deleteImage(image);     //Free allocated memory.
		return 0;
	}
	if(strcmp(argv[1],"-stringToImage")==0){
		char *newFile = malloc(sizeof(char)*(strlen(argv[2]))); //Create new file name
        strcpy(newFile,"new-");
		strcat(newFile,argv[2]);
		stringToImage(argv[2],argv[3],newFile);	//Create the new image
        free(newFile);		//Free allocated memory.
	}
	if(strcmp(argv[1],"-imageToString")==0){
		IMAGE *image = initImage(argv[2]);	//Open image
		if(image==NULL)
            return EXIT_FAILURE;
		imageToString(image);	//Create text file output.txt
		deleteImage(image);		//Free allocated memory.
	}
    return 0;
}