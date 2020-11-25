/* This is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License, see the file COPYING.
*/
#include "stringToImage.h"

/**
 * @brief This function transforms the contents of a given txt file to
 * their binary representation.
 * 
 * @param const_char_*_filename The txt file to be opened. 
 * @param int_*_textSize A pointer to an integer where the size of the resulting binary table will be saved.
 * @return byte* The resulting binary representation as a table of bytes. 
 */
static byte * saveText(const char *filename, int *textSize);

static byte * saveText(const char *filename, int *textSize){
	FILE *file = NULL;
	byte *text;
	//open the file
	if((file = fopen(filename,"r"))== NULL){
		printf("File %s cannot be opened.\n", filename);
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
	fclose(file);
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
	free(temp);
	*textSize=size*8;
	return text;
}

void stringToImage(const char *coverName,const char *textFile,char *newFile){
	int size=0;
	byte *binaryText = saveText(textFile,&size);
	if(binaryText==NULL){
		return;
	}
	IMAGE *cover = initImage(coverName);
	if(cover==NULL){
		printf("Image file does not exist or is invalid.\n");
		free(binaryText);
		return;
	}
	//create a new image
	IMAGE *newImg = copyImage(cover);
	deleteImage(cover);
	int i,j,k=0;	//k is a temporary counter - we count the size of the text
	
	//make all the pixels of the new image black RGB=(0,0,0)
	int pixelAmount=getPixelAmount(newImg);
	for(i=0;i<pixelAmount;i++){
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
	free(binaryText);
	//save the new image
	saveImage(newImg,newFile);
	//free the space we reseve in memory
	deleteImage(newImg);
}


#ifdef DEBUG5
int main(void){
	
	stringToImage("tux-pirate.bmp","strFile.txt");
	
}
#endif