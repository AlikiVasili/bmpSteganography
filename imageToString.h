/** 
 *	@file imageToString.h
 *  @brief This module decrypts an image to a string and save
 *	the string in a text file named output.txt.
 *
 *  @author Panagiotis Papadopoulos
 *  @bug No known bugs.
 */
#ifndef IMAGETOSTRING_H
#define IMAGETOSTRING_H

#include "image.h"

/**
*@brief This function takes an image and tranforms it to a string
* and then proceed to save that string in a text file named output.txt
*
*@param const_IMAGE_*_coverImage The image to be decrypted back to a string.
*@return void.
*/
PUBLIC void imageToString(const IMAGE *coverImage);


#endif