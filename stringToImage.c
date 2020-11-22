#include "stringToImage.h"

int * saveText(char *filename, int * text ){
	FILE *file = NULL;
	
	//open the file
	if((file = fopen(filename,"r"))== NULL){
		printf("File %s cannot be open!\n)", filename);
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
	text = (int *)malloc(sizeof(int)* (size *8));
	
	//create a mask
	byte mask = 128;
	byte tempByte = 0;
	int j = 0 , i =0; 
	
	//for every char of the text we read
	for(i = 0; i < size*8; i+=8){
		//save its 8 bits to the table text
		for(j = 0;j <8 ;j++){
			//shift the mask 
			mask = mask >> j;
			tempByte = temp[i] & mask;
			if(tempByte > 0){
				text[i+j] = 1;
			}
			else{
				text[i+j] = 0;
			}
			mask = 128;
		}
	}
	return text;
}


#ifdef DEBUG5
int main(void){
	int *text = saveText("input.txt",text);
}
#endif