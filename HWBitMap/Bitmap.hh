#pragma once
#pragma pack(2)
#include <iostream>
#include <cstring>

using namespace std;
typedef struct {
    uint16_t  bfType;
    uint32_t  bfSize;
    uint16_t  bfReserved1;
    uint16_t  bfReserved2;
    uint32_t  bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t  biSize;
    uint32_t  biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t  biBitCount;
    uint32_t  biCompression;
    uint32_t  biSizeImage;
    uint32_t  biXPelsPerMeter;
    uint32_t  biYPelsPerMeter;
    uint32_t  biClrUsed;
    uint32_t  biClrImportant;
} BITMAPINFOHEADER;
class Bitmap{
private:
    uint32_t pixels[200][300];
    uint32_t height;
    uint32_t width;
    uint32_t size;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER bitmapHeader;
public:
    Bitmap();

    void line(double x0, double y0, double x1, double y1, int bgr);
    void rect(double x0, double y0, double x1, double y1, int bgr);
    void write(const char* name);
};