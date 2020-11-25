/** @file listImg.h
 *  @author Panagiotis Papadopoulos
 *	@brief This module contains a function to list the header of a bmp image.
 *
 *  @bug No known bugs.
 */ 
#include "image.h"
/**
 * @brief This function takes a bmp image as an argument and proceeds to print it's header. 
 * 
 * @param const_IMAGE_*_img The Image whose header we want to print.
 */
PUBLIC void list(const IMAGE *img);