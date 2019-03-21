#include "Bitmap.hh"

Bitmap::Bitmap(int wid, int hei):height(hei), width(wid) {
    pixels = new uint32_t[wid*hei];
    size = height * width * 3;
    bits = new char[size];
    memset(bits, 0xff, size);

    fileHeader.bfType = 0x4D42;
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + size;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    bitmapHeader.biSize = sizeof(BITMAPINFOHEADER);
    bitmapHeader.biHeight = height;
    bitmapHeader.biWidth = width;
    bitmapHeader.biPlanes = 1;
    bitmapHeader.biBitCount = 24;
    bitmapHeader.biSizeImage = size;
    bitmapHeader.biCompression = 0;
}

Bitmap::~Bitmap(){
    delete [] pixels;
}

void Bitmap::line(double x0, double y0, double x1, double y1, int bgr) {
    int blue = bgr >> 16;
    int green = (bgr >> 8) & 0x00ff;
    int red = bgr & 0x0000ff;
    int color = 0;
    if (blue > 0)
        color = 1;
    if(green > 0)
        color = 2;
    if(red > 0)
        color = 3;
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
        pixels[y*width+x] = color;
    }
}
void Bitmap::write(const char *name) {
    int index;
    for(int i = 0; i < width*height; i++){
        switch (pixels[i]){
            case 1:
                bits[i * 3 + 0] = 255;
                bits[i * 3 + 1] = 0;
                bits[i * 3 + 2] = 0;
                break;
            case 2:
                bits[i * 3 + 0] = 0;
                bits[i * 3 + 1] = 255;
                bits[i * 3 + 2] = 0;
                break;
            case 3:
                bits[i * 3 + 0] = 0;
                bits[i * 3 + 1] = 0;
                bits[i * 3 + 2] = 255;
                break;
        }
    }
    FILE *output = fopen(name, "wb");
    if(output == nullptr){
        cout << "Cannot open file!\n";
    }
    else {
        fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
        fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
        fwrite(bits, size, 1, output);
        fclose(output);
    }
}