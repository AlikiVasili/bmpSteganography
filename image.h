#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>

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

IMAGE *initImage(char *fileName);
void saveImage(IMAGE *src, char *imageName);
int getPixelAmount(IMAGE *src);

#endif