/** @file grayscale.h
 *  @brief This is a header file that haa the functions in order to create a grayscale image.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef GRAYSCALE_H
#define GRAYSCALE_H

#include "image.h"

void grayscale_filter(IMAGE *image, char *file);
int calculate_luminance(byte red,byte green,byte blue);
//bytes * read_pixel(IMAGE img);
void change_pixel(PIXEL pixel);
int my_round(double x);

#endif