#include "image.h"

int getPixelAmount(IMAGE *src){
	return src->padding_pixels + src->header->bmpInfoHeader->biHeight * src->header->bmpInfoHeader->biWidth;
}

IMAGE * initImage(char *fileName){
	FILE *file=NULL;
	IMAGE *image = NULL;
	//Allocate space for all pointers.
	image = (IMAGE *)malloc(sizeof(IMAGE));
	image->header = (HEADER *)malloc(sizeof(HEADER));
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
	//Read each individual information (it appears that the struct padding can mess with reading if we read all bytes directly)
	fread(&(image -> header -> bmpFileHeader ->bfType1),sizeof(byte), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfType2),sizeof(byte), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfSize),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfReserved1),sizeof(word), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfReserved2),sizeof(word), 1, file);
	fread(&(image -> header -> bmpFileHeader ->bfOffBits),sizeof(dword), 1, file);

	//fread(image -> header -> bmpInfoHeader,sizeof(BMPINFOHEADER), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biSize),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biWidth),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biHeight),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biPlanes),sizeof(word), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biBitCount),sizeof(word), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biCompression),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biImageSize),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biXPelsPerMeter),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biYPelsPerMeter),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biClrUsed),sizeof(dword), 1, file);
	fread(&(image -> header -> bmpInfoHeader->biClrImportant),sizeof(dword), 1, file); 
	
	//see if there are padding pixels and calcuate how many.
	int padding_pixels = 0;
	int temp = 0;
	temp = ((image -> header -> bmpInfoHeader -> biWidth)*3) % 4;
	if(temp != 0){
		padding_pixels = temp;
		padding_pixels = padding_pixels * (image -> header -> bmpInfoHeader -> biHeight);
	}
	
	image -> padding_pixels = padding_pixels; //Save this inforamtion for other functions.
	
	//find how much pixels the image has
	int how_much_pixels = (image -> header -> bmpInfoHeader -> biWidth) * (image -> header -> bmpInfoHeader -> biHeight);
	how_much_pixels = how_much_pixels + padding_pixels;
	//reseve space in memory from the pixels
	image -> pixels = (PIXEL *)malloc(how_much_pixels * sizeof(PIXEL));

	int i = 0;
	//Read each byte for every pixel.
	for(i = 0; i<how_much_pixels ; i++){
		fread(&(image -> pixels[i].byte1), sizeof(byte), 1 , file); 
		fread(&(image -> pixels[i].byte2), sizeof(byte), 1 , file);
		fread(&(image -> pixels[i].byte3), sizeof(byte), 1 , file);
	}
	
	
	return image;
}

void saveImage(IMAGE *src, char *imageName){
	FILE *output = fopen(imageName,"wb"); //Create a new file with the given name.

	//Save the file header info in the file (If we copy directly the padding gets copied as well).
	fwrite(&(src -> header -> bmpFileHeader ->bfType1),sizeof(byte), 1, output);
	fwrite(&(src -> header -> bmpFileHeader ->bfType2),sizeof(byte), 1, output);
	fwrite(&(src -> header -> bmpFileHeader ->bfSize),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpFileHeader ->bfReserved1),sizeof(word), 1, output);
	fwrite(&(src -> header -> bmpFileHeader ->bfReserved2),sizeof(word), 1, output);
	fwrite(&(src -> header -> bmpFileHeader ->bfOffBits),sizeof(dword), 1, output);

	//fwrite(src->header->bmpInfoHeader,sizeof(BMPINFOHEADER),1,output);
	fwrite(&(src -> header -> bmpInfoHeader->biSize),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biWidth),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biHeight),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biPlanes),sizeof(word), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biBitCount),sizeof(word), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biCompression),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biImageSize),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biXPelsPerMeter),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biYPelsPerMeter),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biClrUsed),sizeof(dword), 1, output);
	fwrite(&(src -> header -> bmpInfoHeader->biClrImportant),sizeof(dword), 1, output);

	int pixelCount = getPixelAmount(src);
	int i=0;
	//Save each pixel's bytes 1 by 1 to avoid copying the structs padding.
	for(i=0;i<pixelCount;i++){
		fwrite(&(src->pixels[i].byte1),sizeof(byte),1,output);
		fwrite(&(src->pixels[i].byte2),sizeof(byte),1,output);
		fwrite(&(src->pixels[i].byte3),sizeof(byte),1,output);
	}
	fclose(output);
}

#ifdef DEBUG
int main(){
	IMAGE *img = initImage("image3.bmp");
	printf("%c\n", img -> pixels[0].byte2);
	saveImage(img,"testing.bmp");
}
#endif