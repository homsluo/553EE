#include "Bitmap.hh"

Bitmap::Bitmap()
{
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 300; j++)
        {
            pixels[i][j] = 0xffffffff;
        }
    }
    height = 200;
    width = 300;
    size = height * width * 4;

    fileHeader.bfType = 0x4D42;
    fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapHeader.biWidth = width;
    bitmapHeader.biHeight = height;
    bitmapHeader.biPlanes = 1;
    bitmapHeader.biBitCount = 32;
    bitmapHeader.biCompression = 0;
    bitmapHeader.biSizeImage = 0;
    bitmapHeader.biXPelsPerMeter = 0;
    bitmapHeader.biYPelsPerMeter = 0;
    bitmapHeader.biClrUsed = 0;
    bitmapHeader.biClrImportant = 0;
}
void Bitmap::line(double x0, double y0, double x1, double y1, int bgr) {
    int x, y;
    double deltax = x1 - x0;
    double deltay = y1 - y0;
    double error = 0;
    double deltaerr = deltay/deltax;
    y = y0;
    for(x = x0; x < x1; x++)
    {
        error = error + deltaerr;
        if(abs(error) >= 0.5)
        {
            y = y+1;
            error = error - 1.0;
        }
        pixels[y][x] = bgr;
    }
}
void Bitmap::rect(double x0, double y0, double x1, double y1, int bgr) {
    int x, y;
    for(y = y0; y < y1; y++)
    {
        pixels[y][int(x0)] = bgr;
        pixels[y][int(x1)] = bgr;
    }
    for(x = x0; x < x1; x++)
    {
        pixels[int(y0)][x] = bgr;
        pixels[int(y1)][x] = bgr;
    }
}
void Bitmap::write(const char* name) {
    FILE *output = fopen(name, "wb");
    if(output == nullptr){
        cout << "Cannot open file!\n";
    }
    else{
        fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
        fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
        fwrite(pixels, size, 1, output);
        fclose(output);
    }
}