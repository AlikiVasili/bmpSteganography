/**
 * @file encodeStegano.c
 * @author Panagiotis Papadopoulos
 * @brief This file contains the source code for the encodeStegano library.
 * 
 */
#include "encodeStegano.h"

void encodeStegano(const IMAGE *coverImage, const IMAGE *secret, unsigned short int bitNum, const char *newFileName){
    IMAGE *cover = copyImage(coverImage);
    if(cover==NULL || secret == NULL)
        return;
    byte getHighBits = 128; //default mask to retrieve bitNum msb = 1 0 0 0 0 0 0 0
    unsigned short int shiftRightAmount = 8-bitNum; //Amount of bits to shift so that the bits to be copied are properly placed.
    //Exit if invalid bitNum is given.
    if(bitNum<=0 || bitNum >=8 ){
        printf("Invalid bit Num given the bits to be changed have to be between 1-7\n");
        return;
    }
    
    int i;
    //Create proper mask based on bits requested.
    for(i=1;i<bitNum;i++){
        getHighBits = getHighBits >> 1; //Shift the bits right by 1
        getHighBits+=128;  //Set the msb to 1 again.
    }
    byte temp;
    byte removeLowBits = 255 - getHighBits;    //This mask will set the bitNum lsb to 0
    removeLowBits <<= bitNum;
    int pixelAmount =getPixelAmount(cover);
    for(i=0;i<pixelAmount;i++){
        temp = secret->pixels[i].byte1 & getHighBits;//Fetch the bitNum msb from the secret image.
        temp = temp >> shiftRightAmount;            //Shift them right by 8-bitNum so that they become bitNum lsb
        cover->pixels[i].byte1 = cover->pixels[i].byte1 & removeLowBits; //Set the bitNum lsb of the cover to 0
        cover->pixels[i].byte1 = cover->pixels[i].byte1 | temp;          //With bitwise or set the bitNum lsb of the cover to the bitNum msb of the secret.

        temp = secret->pixels[i].byte2 & getHighBits;
        temp = temp >> shiftRightAmount;
        cover->pixels[i].byte2 = cover->pixels[i].byte2 & removeLowBits;
        cover->pixels[i].byte2 = cover->pixels[i].byte2 | temp;

        temp = secret->pixels[i].byte3 & getHighBits;
        temp = temp >> shiftRightAmount;
        cover->pixels[i].byte3 = cover->pixels[i].byte3 & removeLowBits;
        cover->pixels[i].byte3 = cover->pixels[i].byte3 | temp;
    }
    saveImage(cover, newFileName);
    deleteImage(cover);

}

#ifdef DEBUG2
#include <assert.h>
int main(void){
    IMAGE *cover = initImage("IMG_6865.bmp");
    IMAGE *secret = initImage("IMG_6875.bmp");
    encodeStegano(cover,secret,4,"testing.bmp");
    IMAGE *newImg = initImage("testing.bmp");
    assert(newImg!=NULL); //Check if the new image exists.
    byte secretMsd = secret->pixels[0].byte1 & 240;
    secretMsd=secretMsd>>4;
    byte newImgLsd = newImg->pixels[0].byte1 & 15;
    assert(secretMsd==newImgLsd);//Check if the 4 msb of the secret mage are equal to the last 
    deleteImage(cover);
    deleteImage(secret);
    deleteImage(newImg);
    return 0;

}
#endif