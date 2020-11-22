
#ifndef STRINGTOIMAGE_H
#define STRINGTOIMAGE_H

#include "image.h"

static byte * saveText(char *filename,byte *text,int *size);
void stringToImage(const char *cover,byte *binaryText,int size);




#endif