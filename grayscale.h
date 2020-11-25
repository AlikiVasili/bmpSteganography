/** @file grayscale.h
 *  @brief This module turns an image to its grayscale version.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "image.h"

/**
 * @brief This function turns the given image in its grayscale vesion.
 * 
 * @param IMAGE_*_image The bmp image which will be turn into grayscale.
 * @param char_*_file The file name of the bmp file that has the image.
 */
void grayscale_filter(IMAGE *image, char *file);

#endif