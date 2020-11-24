/* 
* This is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License, see the file COPYING.
*/
#include "grayscale.h"
/**
 * @brief This function rounds the given number.
 * 
 * @param double_x The number we want to round.
 */
static int my_round(double x);
/**
 * @brief This function calculate the luminance of a pixel.
 * 
 * @param byte_red The first(red) byte of the pixel.
 * @param byte_greem The second(green) byte of the pixel.
 * @param byte_blue The third(blue) byte of the pixel.
 */
static int calculate_luminance(byte red,byte green,byte blue);

void grayscale_filter(IMAGE *image, char *file){
	//if image is null then return
	if(image == NULL)
		return;
	
	//make a copy of the image
	IMAGE *cover = copyImage(image);
	int i = 0 ;
	int gray_version = 0;
	//go through all the pixels of the image
	for(i = 0 ; i < getPixelAmount(cover); i++){
		//calculate the luminance of the current pixel and save it to the gray_version
		gray_version = calculate_luminance(cover -> pixels[i].byte1 , cover -> pixels[i].byte2 , cover -> pixels[i].byte3);
		//change all the bytes of the pixel to the pixel's gray_version
		cover -> pixels[i].byte1 = (unsigned char)gray_version;
		cover -> pixels[i].byte2 = (unsigned char)gray_version;
		cover -> pixels[i].byte3 = (unsigned char)gray_version;
	}
	//save the copy image
	saveImage(cover,file);
	deleteImage(cover);
}

static int my_round(double x){
	if (x < 0.0)
		return (int)(x - 0.5);
    else
        return (int)(x + 0.5);
}

static int calculate_luminance(byte red,byte green,byte blue){
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
#include <assert.h>
int main(){
	IMAGE *img = initImage("image1.bmp"); 	//read the image1
	grayscale_filter(img,"testing.bmp"); 	//make it to its graysclae version
	FILE *f;
	assert((f=fopen("testing.bmp","rb"))!=NULL);	//Try and open the file that must be created
	fclose(f);
	deleteImage(img);
	
	assert(my_round(1.258) == 1);	//check the function my_round
	assert(calculate_luminance(9,90,160) == 74);	//check the function calculate_luminance
}
#endif