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
/**
 * @brief This function calculate the luminance of a pixel.
 * 
 * @param byte_red The first(red) byte of the pixel.
 * @param byte_greem The second(green) byte of the pixel.
 * @param byte_blue The third(blue) byte of the pixel.
 */
//static int calculate_luminance(byte red,byte green,byte blue);
/**
 * @brief This function rounds the given number.
 * 
 * @param double_x The number we want to round.
 */
//static int my_round(double x);

#endif