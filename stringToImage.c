#include "stringToImage.h"

static byte * saveText(char *filename, byte *text ,int *textSize){
	FILE *file = NULL;
	
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
			tempByte = temp[i] & mask;
			if(tempByte > 0){
				text[(i*8)+j] = 1;
			}
			else{
				text[i*8+j] = 0;
			}
			mask = 128;
		}
	}
	*textSize=size*8;
	return text;
}

void stringToImage(const char *coverName,byte *binaryText,int size){
	IMAGE *cover = initImage(coverName);
	IMAGE *newImg = copyImage(cover);
	int i,j,k=0;
	for(i=0;i<getPixelAmount(cover);i++){
		newImg->pixels[i].byte1&=0;
		newImg->pixels[i].byte2&=0;
		newImg->pixels[i].byte3&=0;
	}
	for(i=0;i<newImg->header->bmpInfoHeader->biWidth;i++){
		for(j=newImg->header->bmpInfoHeader->biHeight-1;j>=0;j--){
			if(k<size){
				newImg->pixels[i+(j*newImg->header->bmpInfoHeader->biWidth)].byte1=128*binaryText[k];
				newImg->pixels[i+(j*newImg->header->bmpInfoHeader->biWidth)].byte2=128*binaryText[k];
				newImg->pixels[i+(j*newImg->header->bmpInfoHeader->biWidth)].byte3=128*binaryText[k];
				k++;
			}
		}
	}
	saveImage(newImg,"testing.bmp");
	deleteImage(newImg);
}


#ifdef DEBUG5
int main(void){
	int size=0;
	byte *text = saveText("strFile.txt",text,&size);
	stringToImage("tux-pirate.bmp",text,size);
	
}
#endif