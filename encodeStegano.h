/**
 * @file encodeStegano.h
 * @author Panagiotis Papadopoulos
 * @brief This file contains the function with which one bmp image file can be steganographied in another.
 */
#include "image.h"
/**
 * @brief This method takes 2 bmp a cover and a secret one and proceeds to hide the secret in the cover using steganography. 
 * The resulting quality of the hidden image depends on the amount of bits to be copied however as more bits are copied the cover image quality
 * drops. The function then saves this new image that contains the inforamtion of both and saves it in a new image.
 * 
 * @param IMAGE_*_cover The cover photo in which the secret photo will be steganographied.
 * @param IMAGE_*_secret The photo to be steganographied.
 * @param unsigned_short_int_bitNum The amount of bits of the secret image to copy to the cover photo.
 * @param char_*_newFileName The name of the new image file.
 */
void encodeStegano(IMAGE *cover, IMAGE *secret, unsigned short int bitNum, char *newFileName );