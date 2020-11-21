#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

typedef struct pixel{
	byte byte1;
	byte byte2;
	byte byte3;
}PIXEL;

typedef struct BMPINFOHEADER{
	dword biSize;
	dword biWidth;
	dword biHeight;
	word biPlanes;
	word biBitCount;
	dword biCompression;
	dword biImageSize;
	dword biXPelsPerMeter;
	dword biYPelsPerMeter;
	dword biClrUsed;
	dword biClrImportant;
}BMPINFOHEADER;

typedef struct BMPFILEHEADER{
	byte bfType1;
	byte bfType2;
	dword bfSize;
	word bfReserved1;
	word bfReserved2;
	dword bfOffBits;
}BMPFILEHEADER;

typedef struct header{
	BMPFILEHEADER *bmpFileHeader;
	BMPINFOHEADER *bmpInfoHeader;
}HEADER;

typedef struct image{
	HEADER *header;
	PIXEL *pixels;
	int padding_pixels;
}IMAGE;

/**
 * @brief This function opens a given file and
 * save it in an IMAGE struct if it's a bmp image.
 * 
 * @param fileName The name of the file to be opened.
 * @return IMAGE* The pointer to that IMAGE struct.
 */
IMAGE *initImage(char *fileName);
/**
 * @brief This function deletes an IMAGE struct from memory.
 * 
 * @param img The IMAGE to be deleted.
 */
void deleteImage(IMAGE *img);
/**
 * @brief This function checks if a given IMAGE is a bmp file or not.
 * 
 * @param img THE IMAGE to be cjecked.
 * @return int 1 if the IMAGE is a bmp file 0 if otherwise.
 */
int isBmp(IMAGE *img);
/**
 * @brief This function checks if a given IMAGE is a bmp file
 * with no compression and 24-bit color depth.
 * 
 * @param img The IMAGE to be checked.
 * @return int 1 if there is no compression and 
 * the color depth is 24-bits, 0 if otherwise.
 */
int isUncompressed24bit(IMAGE *img);
/**
 * @brief This function creates a copy of a given IMAGE.
 * 
 * @param src The IMAGE to be copied.
 * @return IMAGE* The copy of the given IMAGE or NULL in case of failure.
 */
IMAGE *copyImage(const IMAGE *src);
/**
 * @brief This function saves an IMAGE in a file with a given filename.
 * 
 * @param src The IMAGE to be saved.
 * @param imageName The filename.
 */
void saveImage(const IMAGE *src, char *imageName);
/**
 * @brief This function retruns the amount of pixels in the IMAGE struct.
 * 
 * @param src The IMAGE whose pixel amount to get.
 * @return int The amount of pixels including padding pixels.
 */
int getPixelAmount(const IMAGE *src);

#endif