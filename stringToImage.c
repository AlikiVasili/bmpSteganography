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
	
	//read the text from the file and save it to temp
	while(fscanf(file,"%c",&temp[size]) != EOF){
		size++;
		temp = (char * )realloc(temp,(size+1) * sizeof(char));
	}
	//close the file
	fclose(file);
	
	//to the table text we will save the index of temp bit by bit
	text = (byte *)malloc(sizeof(byte)* (size *8));
	
	//create a mask
	byte mask = 128;
	//create a temporary byte to save the bit we will read for the image
	byte tempByte = 0;
	int j = 0 , i =0; 
	
	//for every char of the text we read(temp)
	for(i = 0; i < size; i++){
		//save its 8 bits to the table text
		for(j = 0;j <8 ;j++){
			//shift the mask right by j
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
	//free the temp
	free(temp);
	//save the size of the text
	*textSize=size*8;
	return text;
}

void stringToImage(const char *coverName,const char *textFile,char *newFile){
	int size=0;
	//binary text is the text bit by bit
	byte *binaryText = saveText(textFile,&size);
	if(binaryText==NULL){
		return;
	}
	//open and read the given image
	IMAGE *cover = initImage(coverName);
	if(cover==NULL){
		printf("Image file does not exist or is invalid.\n");
		free(binaryText);
		return;
	}
	
	//create a new image based on the cover image
	IMAGE *newImg = copyImage(cover);
	//delete cover image
	deleteImage(cover);
	int i,j,k=0;	//k is a temporary counter - we count the size of the text
	
	//make all the pixels of the new image black RGB=(0,0,0)
	int pixelAmount=getPixelAmount(newImg);
	for(i=0;i<pixelAmount;i++){
		newImg->pixels[i].byte1&=0;
		newImg->pixels[i].byte2&=0;
		newImg->pixels[i].byte3&=0;
	}
	
	//save to the right places in the image the right bit of the text
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
	//free the space we reseve for binaryText in memory 
	free(binaryText);
	//save the new image to the newFile
	saveImage(newImg,newFile);
	//free the space we reseve in memory for the image(delete the image)
	deleteImage(newImg);
}


#ifdef DEBUG5
#include <assert.h>
int main(void){
	stringToImage("tux-pirate.bmp","strFile.txt","testing.txt");	//create an image testing from the strFile.txt
	FILE *f;
	assert((f=fopen("testing.bmp","rb"))!=NULL);	//Try and open the file that must be created
	fclose(f);
	
	int size = 0;
	assert((saveText("strFile.txt",&size)) != NULL);	//check the function saveText
}
#endif