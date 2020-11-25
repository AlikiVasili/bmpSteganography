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


#endif