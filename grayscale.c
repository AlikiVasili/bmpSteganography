#include "grayscale.h"

void grayscale_filter(IMAGE *image, char *file){
	//if image is null then return
	if(image == NULL)
		return;
	
	//make a copy of the image
	IMAGE *copy = copyImage(image);
	int i = 0 ;
	int gray_version = 0;
	//go through all the pixels of the image
	for(i = 0 ; i < getPixelAmount(copy); i++){
		//calculate the luminance of the current pixel and save it to the gray_version
		gray_version = calculate_luminance(copy -> pixels[i].byte1 , copy -> pixels[i].byte2 , copy -> pixels[i].byte3);
		//change all the bytes of the pixel to the pixel's gray_version
		copy -> pixels[i].byte1 = (unsigned char)gray_version;
		copy -> pixels[i].byte2 = (unsigned char)gray_version;
		copy -> pixels[i].byte3 = (unsigned char)gray_version;
	}
	//save the copy image
	saveImage(copy,file);
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

#ifdef DEBUG2
int main(){
	IMAGE *img = initImage("image1.bmp");
	grayscale_filter(img,"image1_copy.bmp");
}
#endif