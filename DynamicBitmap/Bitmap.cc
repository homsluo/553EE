#include "Bitmap.hh"

Bitmap::Bitmap(int wid, int hei):height(hei), width(wid) {
    pixels = new uint32_t[wid*hei];
    size = height * width * 4;
    memset(pixels, 0xffffffff, size);

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

Bitmap::~Bitmap(){
    delete [] pixels;
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
        pixels[y*width+x] = bgr;
    }
}
void Bitmap::write(const char *name) {
    FILE *output = fopen(name, "wb");
    if(output == nullptr){
        cout << "Cannot open file!\n";
    }
    else {
        fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
        fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
        fwrite(pixels, size, 1, output);
        fclose(output);
    }
}