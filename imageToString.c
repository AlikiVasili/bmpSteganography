 /* 
 * This is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License, see the file COPYING.
 */
 /**
 *  @author Panagiotis Papadopoulos
 *  @bug No known bugs.
 */
#include "imageToString.h"

PUBLIC void imageToString(const IMAGE *coverImage){
	FILE *output = fopen("outputText.txt","w");
	char *text = malloc(sizeof(char));
	char tempChar=0;
	int i,j,k=0,size = 1;
	for(i=0;i<coverImage->header->bmpInfoHeader->biWidth;i++){
		//starting from the pixel at the left up corner
		for(j=coverImage->header->bmpInfoHeader->biHeight-1;j>=0;j--){
			if(k<7){
				tempChar+=(coverImage->pixels[i+(j*coverImage->header->bmpInfoHeader->biWidth)].byte1/128);
				tempChar=tempChar<<1;
				k++;
			}
			else{
				tempChar+=(coverImage->pixels[i+(j*coverImage->header->bmpInfoHeader->biWidth)].byte1/128);
				k=0;
				text[size-1] = tempChar;
				size++;
				text = realloc(text,sizeof(char)*size);
				tempChar=0;
			}
		}
	}
	fwrite(text,sizeof(char),size,output);
	free(text);
	fclose(output);
}
#ifdef DEBUG7
int main(void){
	IMAGE *cover = initImage("testing.bmp");
	imageToString(cover);
	deleteImage(cover);
}
#endif