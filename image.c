#include "image.h"

IMAGE * initImage(FILE *file,char *fileName){
	IMAGE *image = NULL;
	image = (IMAGE *)malloc(sizeof(IMAGE));
	image->header = (HEADER *)malloc(sizeof(HEADER)); //Need space for header
	image -> header -> bmpFileHeader =(BMPFILEHEADER *) malloc(sizeof(BMPFILEHEADER));
	image -> header -> bmpInfoHeader =(BMPINFOHEADER *) malloc(sizeof(BMPINFOHEADER));

	
	if(image == NULL){
		printf("Reseve space in memory can't be done");
		return NULL;
	}
	
	if( (file=fopen(fileName,"rb") )== NULL){
		printf("File %s cannot be opened!\n", fileName);
		return NULL;
	}
	fread(&(image -> header -> bmpFileHeader ->bfType1),sizeof(byte), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfType2),sizeof(byte), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfSize),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfReserved1),sizeof(word), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfReserved2),sizeof(word), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfOffBits),sizeof(dword), 1, file);

	fread(image -> header -> bmpInfoHeader,sizeof(BMPINFOHEADER)*40, 1, file);
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