/* 
* This is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License, see the file COPYING.
*/
#include "decodeText.h"

/**
 *	@brief This function add to a character a bit based on n.
 *
 * 	@param byte_tempByte The byte that we got from the image.
 *	@param int_msgLength The size of the secret text.
 *	@param int_n A number which gives us the place from where we take the bit.
 *	@param char_t The charcter that we want to change.
 *
 *	@return The character we change.
 */
static char editChar(byte tempByte , int msgLength, int n, char t);

void decodeText(IMAGE *image , int msgLength, char *filename){
	int msgBitLength = ( 1 + msgLength) * 8;
	
	//create the permutation table
	int *permutation = createPermutationFunction(getPixelAmount(image),100);
	
	//open the given txt file
	FILE *file = NULL;
	if((file = fopen(filename,"w")) == NULL){
		printf("File %s cannot be open",filename);
	}
	
	int i = 0, o = 0, t=0;;
	byte tempByte  = 0;
	//create a mask
	byte mask = 1;
	
	char *text = NULL;
	//create a text table to save the message inside
	text = (char *)malloc(sizeof(char)*msgLength);
	//make all the places of the text table 0
	for(t=0;t<msgLength;t++){
		text[t] = 0;
	}
	
	//make (1+msgLength)*8 the followings
	for(i = 0 ; i < msgBitLength; i++){
		//find o - o is the permutation of i
		o = permutation[i];
		
		//get from the o-byte of the image's pixels table the lsb, and it with the mask
		//and save it to tempByte
		PIXEL pixel = image -> pixels[o/3];
		int pByte = (o%3); 
		
		if(pByte == 0){
			tempByte =(pixel.byte3) & mask ;
		}
		else if(pByte ==2){
			tempByte =(pixel.byte2) & mask ;
		}
		else{
			tempByte =(pixel.byte1) & mask ;
		}
		
		//add to the character at the i/8 place in the text table the bit we just find
		text[i/8] = editChar(tempByte,msgLength ,i, text[i/8] );
	}
	
	//print the message in the file
	fprintf(file,"%s\n" , text);
	fclose(file);
	free(permutation);
	free(text);
}

static char editChar(byte tempByte , int msgLength, int n, char t){
	int j = 0;

	//if n is between 0 and 8*strlen(m)
	if(n >= 0 && n <= msgLength*8){
		//calculate j
		j = 7 - (n%8);
		tempByte = tempByte << j; //shift logical left the byte by j
		return (tempByte | t);	//add to the character the tempByte and return it
	}
	return 0;
}


#ifdef DEBUG4
#include <assert.h>
int main(){
	IMAGE *img = initImage("new-tux-bonaparte.bmp");	//take the image new-tux-bonaparte
	int msgLength = 280;	
	decodeText(img,msgLength,"testing.txt");	//find the text that has in it
	FILE *f;
	assert((f=fopen("testing.bmp","rb"))!=NULL);	//Try and open the file that must be created
	fclose(f);	//close the file
	deleteImage(img);	//delete the image
	
	assert(editChar(0,1,8,0) == 0);	//check the function editChar
}
#endif