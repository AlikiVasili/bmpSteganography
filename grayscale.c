#include "grayscale.h"

void grayscale_filter(IMAGE *image, char *file){
	int i = 54 , j = 0;
	int size = (image -> header -> bmpInfoHeader -> biWidth) * (image -> header -> bmpInfoHeader -> biHeight);
	size = size + image -> padding_pixels;
	FILE *f;
	if( (f=fopen(file,"wb") )== NULL){
		printf("File %s cannot be opened!\n", file);
		return;
	}
	fwrite((image -> header),sizeof((image -> header)),1,f);
	while( i < size){
		for(j = 0; j< (image -> header -> bmpInfoHeader -> biWidth); j++){
			change_pixel(image -> pixels[i+j]);
			fwrite((image -> pixel[(i-54)+j]),sizeof(PIXEL),1,f);
		}
		i = i+(image -> padding_pixels);
	}
}

int my_round(double x){
	if (x < 0.0)
		return (int)(x - 0.5);
    else
        return (int)(x + 0.5);
}

int calculate_luminance(byte red,byte green,byte blue){
	int luminance  = 0;
	double ntsc = 0;
	//calculate the National Television System Committe (NTSC)
	ntsc = (0.299*red) + (0.587*green) + (0.114 * blue);
	//calculate the luminance based on the NTSC
	luminance = my_round(ntsc);
	//return the luminance
	return luminance;
}

void change_pixel(PIXEL pixel){
	//find the gray version of the pixel
	int gray_version = calculate_luminance(pixel.byte1 , pixel.byte2 , pixel.byte3);
	//change the bytes of the pixel to its gray version 
	pixel.byte1 = (unsigned char)gray_version;
	pixel.byte2 = (unsigned char)gray_version;
	pixel.byte3 = (unsigned char)gray_version;
}

#ifdef DEBUG2
int main(){
	//printf("%d\n", calculate_luminance(9,90,160));
	/*PIXEL *pixel = (PIXEL *)malloc(sizeof(PIXEL));
	pixel -> byte1 = 9;
	pixel -> byte2 = 90;
	pixel -> byte3 = 160;
	change_pixel(pixel);*/
	FILE *f = NULL;
	IMAGE *img = initImage(f,"image1.bmp");
	grayscale_filter(img,"image1.bmp");
}
#endif