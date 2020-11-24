
#ifndef STRINGTOIMAGE_H
#define STRINGTOIMAGE_H

#include "image.h"

/**
 * @brief This function given a sample cover bmp image and a text file
 * creates a bmp image file with the contents of the text file encrypted 
 * inside it.
 * 
 * @param const_IMAGE_*_cover The bmp image to be used as a sample for the resulting image. 
 * @param const_char_*_textFile The name of the text file to be encrypted. 
 * @param char_*_newFile The name of the new image that will be created.
 */
void stringToImage(const char *cover,const char *textFile,char *newFile);

#endif