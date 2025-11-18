#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)
struct bmp_header {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
    
    unsigned int biSize;
    unsigned int biWidth;
    unsigned int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
};
#pragma pack()

int main() {
    FILE *f = fopen("./image.bmp", "rb");

    struct bmp_header header;
    fread(&header, sizeof(struct bmp_header), 1, f);

    printf("Width: %d\n", header.biWidth);
    printf("Height: %d\n", header.biHeight);
}