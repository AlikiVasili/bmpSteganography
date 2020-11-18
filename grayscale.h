/** @file grayscale.h
 *  @brief This is a header file that haa the functions in order to create a grayscale image.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef GRAYSCALE_H
#define GRAYSCALE_H

void grayscale_filter(FILE img);
int calculate_luminance(byte red,byte green,byte blue);
bytes * read_pixel(FILE img);
void change_pixel(FILE img);

#endif