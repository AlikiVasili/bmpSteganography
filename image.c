#include "image.h"

IMAGE * initImage(FILE *file,char *fileName){
	IMAGE *image = NULL;
	image = (IMAGE *)malloc(sizeof(IMAGE));
	image->header = (HEADER *)malloc(sizeof(HEADER)); //Need space for header
	image -> header -> bmpFileHeader =(BMPFILEHEADER *) malloc(sizeof(byte)*14);
	image -> header -> bmpInfoHeader =(BMPINFOHEADER *) malloc(sizeof(byte)*40);

	
	if(image == NULL){
		printf("Reseve space in memory can't be done");
		return NULL;
	}
	
	if( (file=fopen(fileName,"rb") )== NULL){
		printf("File %s cannot be opened!\n", fileName);
		return NULL;
	}
	//image->header->bitmapfileheader = malloc(sizeof(byte)*14);	//Need to allocate space for bitmapfileheader
	fread(image -> header -> bmpFileHeader,sizeof(byte)*14, 1, file);
	//image->header->bitmapinfoheader = malloc(sizeof(byte)*40);//Need to allocate space for bitmapinfoheader
	fread(image -> header -> bmpInfoHeader,sizeof(byte)*40, 1, file);
	return image;
}

#ifdef DEBUG
int main(){
	FILE *f = NULL;
	IMAGE *img = initImage(f,"4x3.bmp");
	printf("%c%c ", img -> header -> bitmapfileheader[0],  img -> header -> bitmapfileheader[1]); //print BM
	printf("%dBytes\n", img -> header -> bitmapfileheader[2]);//print Size of file 
}
#endif