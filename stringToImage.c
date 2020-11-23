#include "stringToImage.h"

static byte * saveText(const char *filename, int *textSize){
	FILE *file = NULL;
	byte *text;
	//open the file
	if((file = fopen(filename,"r"))== NULL){
		printf("File %s cannot be open!\n)", filename);
		return NULL;
	}
	
	char *temp;
	int size = 0;
	temp = (char * )malloc(sizeof(char));
	
	//read the text from the file
	while(fscanf(file,"%c",&temp[size]) != EOF){
		size++;
		temp = (char * )realloc(temp,(size+1) * sizeof(char));
	}
	
	//save to the table text the text we read bit by bit
	text = (byte *)malloc(sizeof(byte)* (size *8));
	
	//create a mask
	byte mask = 128;
	byte tempByte = 0;
	int j = 0 , i =0; 
	
	//for every char of the text we read
	for(i = 0; i < size; i++){
		//save its 8 bits to the table text
		for(j = 0;j <8 ;j++){
			//shift the mask 
			mask = mask >> j;
			//find the bit we want from the character
			//and save it to the tempByte
			tempByte = temp[i] & mask;
			//if the tempByte is bigger than zero
			if(tempByte > 0){
				//then the bit of the character at the current place is 1
				text[(i*8)+j] = 1;
			}
			else{
				//else is zero
				text[i*8+j] = 0;
			}
			//make the mask again 128 to start from the begging for the other character
			mask = 128;
		}
	}
	//save the size of the text
	*textSize=size*8;
	return text;
}

void stringToImage(const char *coverName,const char *textFile){
	int size=0;
	byte *binaryText = saveText(textFile,&size);
	IMAGE *cover = initImage(coverName);
	//create a new image
	IMAGE *newImg = copyImage(cover);
	int i,j,k=0;	//k is a temporary counter - we count the size of the text
	
	//make all the pixels of the new image black RGB=(0,0,0)
	for(i=0;i<getPixelAmount(cover);i++){
		newImg->pixels[i].byte1&=0;
		newImg->pixels[i].byte2&=0;
		newImg->pixels[i].byte3&=0;
	}
	for(i=0;i<newImg->header->bmpInfoHeader->biWidth;i++){
		//starting from the pixel at the left up corner
		for(j=newImg->header->bmpInfoHeader->biHeight-1;j>=0;j--){
			//if the k is not equal or bigger than the size of the text
			if(k<size){
				//change the byte of the pixel based on the bit in binaryText array
				//if the bit = 1 then the pixel we want to be bring - (128,128,128)
				//else if the bit = 0 the pixel we want to be black - (0,0,0)
				newImg->pixels[i+(j*newImg->header->bmpInfoHeader->biWidth)].byte1=128*binaryText[k];
				newImg->pixels[i+(j*newImg->header->bmpInfoHeader->biWidth)].byte2=128*binaryText[k];
				newImg->pixels[i+(j*newImg->header->bmpInfoHeader->biWidth)].byte3=128*binaryText[k];
				//make k plus one
				k++;
			}
		}
	}
	//save the new image
	saveImage(newImg,"testing.bmp");
	//free the space we reseve in memory
	deleteImage(newImg);
}


#ifdef DEBUG5
int main(void){
	
	stringToImage("tux-pirate.bmp","strFile.txt");
	
}
#endif