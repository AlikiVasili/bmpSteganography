/**
 * @file decodeStegano.h
 * @author Panagiotis Papadopoulos
 * @brief This library contains the function to decode a steganographied bmp image from a cover image.
 * 
 */
#include "image.h"
/**
 * @brief This function decodes a hidden image from a cover image.
 * 
 * @param cover The cover bmp image in which the hidden image is steganographied.
 * @param numOfBits The number of bits that where used in steganography.
 * @param newFileName The filename to be given to the image file.
 */
void decodeStegano(const IMAGE *cover, unsigned short int numOfBits, char *newFileName);