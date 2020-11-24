/** @file imaeg.h
 *  @brief This module represents an image.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;
typedef unsigned short int word;
typedef unsigned int dword;

/**
 * @brief This struct represents a pixel in a bmp image
 * with 24-bit color depth.
 * 
 */
typedef struct pixel{
	byte byte1;
	byte byte2;
	byte byte3;
}PIXEL;

/**
 * @brief This struct represents the bmpInfoHeader in a bmp image.
 * 
 */
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

/**
 * @brief This struct represents the bmpFileHeader in a bmp image.
 * 
 */
typedef struct BMPFILEHEADER{
	byte bfType1;
	byte bfType2;
	dword bfSize;
	word bfReserved1;
	word bfReserved2;
	dword bfOffBits;
}BMPFILEHEADER;

/**
 * @brief This struct represents the header in a bmp image.
 * 
 */
typedef struct header{
	BMPFILEHEADER *bmpFileHeader;
	BMPINFOHEADER *bmpInfoHeader;
}HEADER;

/**
 * @brief This struct represents a bmp image.
 * 
 */
typedef struct image{
	HEADER *header;
	PIXEL *pixels;
	int padding_pixels;
}IMAGE;

/**
 * @brief This function opens a given file and
 * save it in an IMAGE struct if it's a bmp image.
 * 
 * @param char_*_fileName The name of the file to be opened.
 * @return IMAGE* The pointer to that IMAGE struct.
 */
IMAGE *initImage(const char *fileName);
/**
 * @brief This function deletes an IMAGE struct from memory.
 * 
 * @param IMAGE_*_img The IMAGE to be deleted.
 */
void deleteImage(IMAGE *img);
/**
 * @brief This function creates a copy of a given IMAGE.
 * 
 * @param const_IMAGE_*_src The IMAGE to be copied.
 * @return IMAGE* The copy of the given IMAGE or NULL in case of failure.
 */
IMAGE *copyImage(const IMAGE *src);
/**
 * @brief This function saves an IMAGE in a file with a given filename.
 * 
 * @param const_IMAGE_*_src The IMAGE to be saved.
 * @param const_char_*_imageName The filename.
 */
void saveImage(const IMAGE *src, const char *imageName);
/**
 * @brief This function retruns the amount of pixels in the IMAGE struct.
 * 
 * @param const_IMAGE_*_src The IMAGE whose pixel amount to get.
 * @return int The amount of pixels including padding pixels.
 */
int getPixelAmount(const IMAGE *src);

#endif