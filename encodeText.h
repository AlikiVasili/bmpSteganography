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
 *	@brief This function calculade the u(n) bit of the given text.
 *
 *	@param char_*_m The text.
 *	@param int_n A number we want to know can bit we want.
 *
 *	@return the u(n) bit.
 */
//static int getBit(char *m, int n);

/**
 *	@brief This function create a permutation.
 *
 *	@param int_N An integer number which shows the size of the table we want to create.
 *	@param unsigned_int_systemkey An unsigned integer in which the permutation is based.
 *
 *	@return the table that we create.
 */
int * createPermutationFunction(int N, unsigned int systemkey);

/**
 *	@brief This function encode a text to an image.
 *
 *	@param IMAGE_*_image The image where the text will be encode.
 *	@param char_*_filename The name of the file with the text we want to hide in the image.
 *	@param char_*_newFile the name of the file we want to create
 *
 *	@return Void.
 */
void encodeText(IMAGE *image,char *filename,char *newFile);

#endif