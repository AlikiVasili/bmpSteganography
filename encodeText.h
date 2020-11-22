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
 *	@param m The text.
 *	@param n the number of the bit we want to find.
 *
 *	@return the u(n) bit.
 */
int getBit(char *m, int n);

/**
 *	@brief This function create a permutation.
 *
 *	@param N An integer number which shows the size of the table we want to create.
 *	@param systemkey An unsigned integer in which the permutation is based.
 *
 *	@return the table that we create.
 */
int * createPermutationFunction(int N, unsigned int systemkey);

/**
 *	@brief This function encode a text to an image.
 *
 *	@param image The image where the text will be encode.
 *	@param filename The name of the file with the text we want to hide in the image.
 *	@param newFile the name of the file we want to create
 *
 *	@return Void.
 */
void encodeText(IMAGE *image,char *filename,char *newFile);

#endif