#include "encodeText.h"

void encodeText(IMAGE *image, char *filename,char *newFile){
	int i = 0;
	int b = 0, o = 0;
	//systemkey = 100
	int *permutation = createPermutationFunction(getPixelAmount(image), 100);
	//create the cover image
	IMAGE *cover = copyImage(image);
	
	FILE *f = NULL;
	if((f=fopen(filename,"r")) == NULL){
		printf("File %s cannot be open!\n)", filename);
		return;
	}
	
	char *m = (char *)malloc(sizeof(char));
	int size = 0;
	while( fscanf(f,"%c",&m[size]) != EOF){
		size++;
		m = (char *)realloc(m,sizeof(char) * (size+1));
	}
	
	int msgBitLength = ( 1 + strlen(m) )* 8;
	
	for(i = 0; i < msgBitLength; i++){
		//find b
		b = getBit(m , i);
		//find o
		o = permutation[i];
		
		//delete the lsb of the o byte of the table of the pixels
		//then make it equal to b
		int pByte = (o%3); 
		if(pByte == 0){
			cover -> pixels[o/3].byte3 = (cover -> pixels[o/3].byte3) & 254; 
			cover -> pixels[o/3].byte3 = (cover -> pixels[o/3].byte3) | b;
		}
		else if(pByte ==2){
			cover -> pixels[o/3].byte2 = (cover -> pixels[o/3].byte2) & 254; 
			cover -> pixels[o/3].byte2 = (cover -> pixels[o/3].byte2) | b;
		}
		else{
			cover -> pixels[o/3].byte1 = (cover -> pixels[o/3].byte1) & 254; 
			cover -> pixels[o/3].byte1 = (cover -> pixels[o/3].byte1) | b;
		}
	}
	
	saveImage(cover , newFile);
	
}

int getBit(char *m, int n){
	int u = 0, i = 0, j = 0;
	
	byte mask = 1; //create a default mask
	byte tempByte = 0;
	//if n is between 0 and 8*strlen(m)
	if(n >= 0 && n <= (8 * strlen(m))){
		i = n/8;
		j = 7 - (n%8);
		
		//find the mask we want in order to get the bit we want
		mask = mask << j; //shift logical left the mask by j
		
		//save to the tempByte the m[i] AND mask
		tempByte = (m[i] & mask);
		//if the tempByte is bigger than zero then the bit we want to see is 1
		//so return 1
		if(tempByte > 0){
			return 1;
		}
		//else is zero so return 0
		else{
			return 0;
		}
	}
	//else return 0
	else{
		return 0;
	}
}

int * createPermutationFunction(int N, unsigned int systemkey){
	//create the table
	int *table = NULL;
	table = (int *)malloc(sizeof(int) * N);
	if(table == NULL){
		printf("reseve space in memory can't be done\n");
		return NULL;
	}
	
	int k = 0 , i = 0, j = 0;
	
	//set the k place of the table equals to k
	for(k = 0; k < N ; k++){
		table[k] = k;
	}
	
	srand(systemkey);
	int temp = 0 ;
	
	//change random the index of the table
	for( k = 0; k < N; k++){
		//find two random numbers
		i = rand();
		j = rand();
		//convert them to a number between 0 and N - 1
		i = i % (N);
		j = j % (N);
		//change the index of the places i and j of the table (swap them)
		temp = table[i];
		table[i] = table[j];
		table[j] = temp;
	}
	return table;
}

#ifdef DEBUG3
int main(){
	//printf("%d\n", getBit("Hello World my name is alice" , 10));
	//createPermutationFunction(5,15);
	IMAGE *img = initImage("tux-bonaparte.bmp");
	encodeText(img,"poem.txt","new-tux-bonaparte.bmp");
}
#endif