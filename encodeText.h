/** 
 *	@file encodeText.h
 *  @brief This module encodes a text into an image.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef ENCODETEXT_H
#define ENCODETEXT_H

#include "image.h"

/**
 *	@brief This function create a permutation.
 *
 *	@param int_N An integer number which shows the size of the table we want to create.
 *	@param unsigned_int_systemkey An unsigned integer in which the permutation is based.
 *
 *	@return the table that we create.
 */
PUBLIC int * createPermutationFunction(int N, unsigned int systemkey);

/**
 *	@brief This function encode a text to an image.
 *
 *	@param IMAGE_*_image The image where the text will be encode.
 *	@param char_*_filename The name of the file with the text we want to hide in the image.
 *	@param char_*_newFile the name of the file we want to create
 *
 *	@return Void.
 */
PUBLIC void encodeText(IMAGE *image,char *filename,char *newFile);

#endif