#pragma once
#pragma pack(2)
#include <iostream>
#include <cstring>

using namespace std;
typedef struct {
    short   bfType;
    int     bfSize;
    short   bfReserved1;
    short   bfReserved2;
    int     bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    int      biSize;
    int      biWidth;
    int      biHeight;
    short    biPlanes;
    short    biBitCount;
    int      biCompression;
    int      biSizeImage;
    int      biXPelsPerMeter;
    int      biYPelsPerMeter;
    int      biClrUsed;
    int      biClrImportant;
} BITMAPINFOHEADER;
class Bitmap{
private:
    uint32_t* pixels;
    int height;
    int width;
    int size;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER bitmapHeader;
    char *bits;
public:
    Bitmap(int wid, int hei);
    BitmapRead(const char* name);
    ~Bitmap();

    void line(double x0, double y0, double x1, double y1, int bgr);
    void writeBMP(const char* name);
};