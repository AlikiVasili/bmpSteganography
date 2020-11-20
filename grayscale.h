/** @file grayscale.h
 *  @brief This module turn an image to its grayscale version.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "image.h"

/**
 * @brief This function turn the given image in its grayscale vesion.
 * 
 * @param image The bmp image which will be turn into grayscale.
 * @param file The file name of the bmp file that has the image.
 */
void grayscale_filter(IMAGE *image, char *file);
/**
 * @brief This function calculate the luminance of a pixel.
 * 
 * @param red The first(red) byte of the pixel.
 * @param greem The second(green) byte of the pixel.
 * @param blue The third(blue) byte of the pixel.
 */
int calculate_luminance(byte red,byte green,byte blue);
/**
 * @brief This function rounds the given number.
 * 
 * @param x The number we want to round.
 */
int my_round(double x);

#endif