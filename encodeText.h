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

int * createPermutationFunction(int N, unsigned int systemkey);

void encodeText(IMAGE *image, char *text);

#endif