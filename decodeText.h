/** @file decodeText.h
 *  @brief This module.
 *
 *  @author Aliki Vasili
 *  @bug No known bugs.
 */
#ifndef DECODETEXT_H
#define DECODETEXT_H

#include "encodeText.h"

void decodeText(IMAGE *image , int msgLength, char *filename);

char getChar(byte tempByte , int msgLength, int n, char t);


#endif