/** @file listImg.h
 *  @author Panagiotis Papadopoulos
 */ 
#include "image.h"

void list(IMAGE *img){
    printf("BITMAP_FILE_HEADER\n");
    printf("==================\n");

    printf("bfType: %c%c\n", img -> header -> bitmapfileheader[0],  img -> header -> bitmapfileheader[1]); //print BM
    printf("bfSize: %u\n", img -> header -> bitmapfileheader[2]);//print Size of file
    printf("bfReserved1: %hu\n",img -> header -> bitmapfileheader[6]);
    printf("bfReserved2: %hu\n",img -> header -> bitmapfileheader[8]);
}
#ifdef DEBUG1
int main(void){
    FILE *f = NULL;
	IMAGE *img = initImage(f,"4x3.bmp");
    list(img);
    return 0;
}
#endif