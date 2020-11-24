/** @file decodeText.h
 *  @brief This module finds the secret message that an image has(decode a text from an image).
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef DECODETEXT_H
#define DECODETEXT_H

#include "encodeText.h"

/**
 *	@brief This function decodes a text from an image.
 *
 *	@param int_msgLength The size of the secret text.
 *	@param char_*_filename The output file.
 *
 *	@return Void.
 */
void decodeText(IMAGE *image , int msgLength, char *filename);

/**
 *	@brief This function add to a character a bit based on n.
 *
 * 	@param byte_tempByte The byte that we got from the image
 *	@param int_msgLength The size of the secret text.
 *	@param int_n A number that we want to find the place from where we take the bit.
 *	@param char_t The charcter that we want to change.
 *
 *	@return The character we change.
 */
//static char editChar(byte tempByte , int msgLength, int n, char t);


#endif