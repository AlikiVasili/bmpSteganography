#include "encodeText.h"

int getBit(char *m, int n){
	int u = 0, i = 0, j = 0;
	
	byte mask = 1; //create a default mask
	byte tempByte = 0;
	//if n is between 0 and 8*strlen(m)
	if(n > 0 && n < (8 * strlen(m))){
		i = n/8;
		j = 7 - (n%8);
		
		//find the mask we want in order to get the bit we want
		mask << j; //shift logical left the mask by j
		
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

#ifdef DEBUG3
int main(){
	printf("%d\n", getBit("Hello World my name is alice" , 10));
}
#endif