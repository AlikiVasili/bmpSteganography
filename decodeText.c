#include "decodeText.h"

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
	text = (char *)malloc(sizeof(char)*msgLength);
	for(t=0;t<msgLength;t++){
		text[t] = 0;
	}
	
	for(i = 0 ; i < msgBitLength; i++){
		//o is the permutation of i
		o = permutation[i];
		
		//get from the o pixel of the image's pixels table we want the lsb so and it with the mask
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
		
		
		text[i/8] = getChar(tempByte,msgLength ,i, text[i/8] );
	}
	
	fprintf(file,"%s\n" , text);
}

char getChar(byte tempByte , int msgLength, int n, char t){
	int j = 0;

	//if n is between 0 and 8*strlen(m)
	if(n >= 0 && n <= msgLength*8){
		j = 7 - (n%8);
		tempByte = tempByte << j; //shift logical left the byte by j
		return (tempByte | t);
	}
	return 0;
}


#ifdef DEBUG4
int main(){
	IMAGE *img = initImage("new-tux-bonaparte.bmp");
	
	int msgLength = 5;
	decodeText(img,msgLength,"new-poem.txt");
}
#endif