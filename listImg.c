/** @file listImg.h
 *  @author Panagiotis Papadopoulos
 */ 
#include "image.h"

void list(IMAGE *img){
    printf("BITMAP_FILE_HEADER\n");
    printf("==================\n");
    printf("bfType: %c%c\n", img -> header -> bmpFileHeader -> bfType1, img -> header -> bmpFileHeader -> bfType2 ); 
    printf("bfSize: %u\n", img -> header -> bmpFileHeader -> bfSize);                                         
    printf("bfReserved1: %hu\n",img -> header -> bmpFileHeader -> bfReserved1);                                     
    printf("bfReserved2: %hu\n",img -> header -> bmpFileHeader -> bfReserved2);                                   
    printf("bfOffBits: %u\n\n", img -> header -> bmpFileHeader -> bfOffBits);                                   

    printf("BITMAP_INFO_HEADER\n");
    printf("==================\n");
    printf("biSize: %u\n", img->header->bmpInfoHeader -> biSize);
    printf("biWidth: %u\n", img->header->bmpInfoHeader -> biWidth);
    printf("biHeight: %u\n", img->header->bmpInfoHeader -> biHeight);
    printf("biPlanes: %hu\n", img->header->bmpInfoHeader -> biPlanes);
    printf("biBitCount: %hu\n", img->header->bmpInfoHeader -> biBitCount);
    printf("biCompression: %u\n", img->header->bmpInfoHeader -> biCompression);
    printf("biSizeImage: %u\n", img->header->bmpInfoHeader -> biImageSize);
    printf("biXPelsPerMeter: %u\n", img->header->bmpInfoHeader -> biXPelsPerMeter);
    printf("biYPelsPerMeter: %u\n", img->header->bmpInfoHeader -> biYPelsPerMeter);
    printf("biClrUsed: %u\n", img->header->bmpInfoHeader -> biClrUsed);
    printf("biClrImportant: %u\n", img->header->bmpInfoHeader -> biClrImportant);

}
#ifdef DEBUG1
int main(void){
    FILE *f = NULL;
	IMAGE *img = initImage(f,"4x3.bmp");
    list(img);
    return 0;
}
#endif