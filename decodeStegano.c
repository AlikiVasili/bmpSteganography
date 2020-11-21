#include "decodeStegano.h"
void decodeStegano(const IMAGE *cover, unsigned short int numOfBits, const char* newFileName){
    IMAGE *secret = copyImage(cover);
    if(cover==NULL)
        return;
    if(numOfBits<=0 || numOfBits>=8){
        printf("Invalid bit Num given the bits to be changed have to be between 1-7\n");
        return;
    }
    byte getLowBits=1;//Deafult mask to retrieve numOffBits lsb.
    int i,shiftLeftAmount=8-numOfBits; //Calculate amount to shift left the retrieved bits.
    //Create prorper mask based on numOffBits
    for(i=1;i<numOfBits;i++){
        getLowBits = getLowBits << 1;
        getLowBits+=1;
    }
    byte temp;
    for(i=0;i<getPixelAmount(cover);i++){
        //Fetch each byte shift it left and save it in the secret image.
        temp = cover->pixels[i].byte1 & getLowBits;
        temp = temp << shiftLeftAmount;
        secret->pixels[i].byte1 = temp;

        temp = cover->pixels[i].byte2 & getLowBits;
        temp = temp << shiftLeftAmount;
        secret->pixels[i].byte2 = temp;

        temp = cover->pixels[i].byte3 & getLowBits;
        temp = temp << shiftLeftAmount;
        secret->pixels[i].byte3 = temp;
    }
    saveImage(secret,newFileName);
    deleteImage(secret);
}

#ifdef DEBUG3
int main(void){
    IMAGE *test = initImage("testing.bmp");
    decodeStegano(test,4,"testingDecode.bmp");
}
#endif