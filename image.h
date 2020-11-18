#ifndef IMAGE_H
#define IMAGE_H

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

typedef struct pixel{
	byte byte1;
	byte byte2;
	byte byte3;
}PIXEL;

typedef struct header{
	byte *bitmapfileheader;
	byte *bitmapinfoheader;
}HEADER;

typedef struct image{
	HEADER *header;
	PIXEL *pixels;
}IMAGE;

IMAGE * init_image(FILE *file,char *fileName);

#endif