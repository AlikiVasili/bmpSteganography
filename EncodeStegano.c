/**
 * @file EncodeStegano.c
 * @author Panagiotis Papadopoulos
 * @brief This file contains the source code for the encodeStegano library.
 * 
 */
#include "image.h"

void encodeStegano(IMAGE *cover, IMAGE *secret, unsigned short int bitNum, char *newFileName ){
    if(cover==NULL || secret == NULL)
        return;
    byte getHighBits = 128; //default 1 bit to move = 1 0 0 0 0 0 0 0
    unsigned short int shiftRightAmount = 8-bitNum; //Amount of bits to shift so that the bits to be copied are properly placed.
    //Exit if invalid bitNum is given.
    if(bitNum<=0 || bitNum >=8 ){
        printf("Invalid bit Num given the bits to be changed have to be between 1-7\n");
        return;
    }
    
    int i;
    //Create proper mask based on bits requested.
    for(i=1;i<bitNum;i++){
        getHighBits = getHighBits >> 1;
        getHighBits+=128;  
    }
    int pixelCount = getPixelAmount(cover);
    byte temp; 
    for(i=0;i<pixelCount;i++){
        temp = secret->pixels[i].byte1 & getHighBits;
        temp = temp >> shiftRightAmount;
        cover->pixels[i].byte1 = cover->pixels[i].byte1 | temp;
        temp = secret->pixels[i].byte2 & getHighBits;
        temp = temp >> shiftRightAmount;
        cover->pixels[i].byte2 = cover->pixels[i].byte2 | temp;
        temp = secret->pixels[i].byte3 & getHighBits;
        temp = temp >> shiftRightAmount;
        cover->pixels[i].byte3 = cover->pixels[i].byte3 | temp;
    }
    saveImage(cover, newFileName);

}

#ifdef DEBUG2
int main(void){
    printf("%u", 4|4);
    IMAGE *img1 = initImage("IMG_6865.bmp");
    IMAGE *img2 = initImage("IMG_6875.bmp");
    encodeStegano(img1,img2,4,"testing.bmp");
}
#endif