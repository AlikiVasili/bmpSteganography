/**
 * @file decodeStegano.h
 * @author Panagiotis Papadopoulos
 * @brief This library contains the function to decode a steganographied bmp image from a cover image.
 *
 * @bug No known bugs.
 * 
 */
#include "image.h"
/**
 * @brief This function decodes a hidden image from a cover image.
 * 
 * @param const_IMAGE_*_cover The cover bmp image in which the hidden image is steganographied.
 * @param unsigned_short_int_numOfBits The number of bits that where used in steganography.
 * @param const_char_*_newFileName The filename to be given to the image file.
 */
PUBLIC void decodeStegano(const IMAGE *cover, unsigned short int numOfBits, const char *newFileName);