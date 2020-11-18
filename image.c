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

	fread(image -> header -> bmpInfoHeader,sizeof(BMPINFOHEADER), 1, file);
	
	//see if there are padding pixels
	int padding_pixels = 0;
	int temp = 0;
	temp = ((image -> header -> bmpInfoHeader -> biWidth)*3) % 4;
	if(temp != 0){
		padding_pixels = 4 - temp;
		padding_pixels = padding_pixels * (image -> header -> bmpInfoHeader -> biHeight);
	}
	
	//find how much pixels the image has
	int how_much_pixels = (image -> header -> bmpInfoHeader -> biWidth) * (image -> header -> bmpInfoHeader -> biHeight);
	how_much_pixels = how_much_pixels + padding_pixels;
	//reseve space in memory from the pixels
	image -> pixels = (PIXEL *)malloc(how_much_pixels * sizeof(PIXEL));
	
	int i = 0;
	for(i = 0; i<how_much_pixels ; i++){
		fread(&(image -> pixels[i].byte1), sizeof(byte), 1 , file);
		fread(&(image -> pixels[i].byte2), sizeof(byte), 1 , file);
		fread(&(image -> pixels[i].byte3), sizeof(byte), 1 , file);
	}
	
	return image;
}

#ifdef DEBUG
int main(){
	FILE *f = NULL;
	IMAGE *img = initImage(f,"4x3.bmp");
	printf("%c\n", img -> pixels[0].byte2);
}
#endif