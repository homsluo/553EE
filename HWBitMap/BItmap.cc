#include "Bitmap.hh"

Bitmap::Bitmap()
{
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 300; j++)
        {
            pixels[i][j] = 0;
        }
    }
    height = 200;
    width = 300;
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
        pixels[y][x] = color;
    }
//    double x, y;
//    int index;
//    double deltax = x1 - x0;
//    double deltay = y1 - y0;
//    double error = 0;
//    double deltaerr = deltay/deltax;
//    y = y0;
//    for(x = x0; x < x1; x++)
//    {
//        error = error + deltaerr;
//        if(abs(error) >= 0.5)
//        {
//            y = y+1;
//            error = error-1.0;
//        }
//        index = (int)y * 300 * 3 + (int)x * 3;
//
//        int blue = bgr >> 16;
//        int green = (bgr >> 8) & 0x00ff;
//        int red = bgr & 0x0000ff;
//        bits[index + 0] = blue;
//        bits[index + 1] = green;
//        bits[index + 2] = red;
//    }
}
void Bitmap::rect(double x0, double y0, double x1, double y1, int bgr) {
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
    for(y = y0; y < y1; y++)
    {
        pixels[y][int(x0)] = color;
        pixels[y][int(x1)] = color;
    }
    for(x = x0; x < x1; x++)
    {
        pixels[int(y0)][x] = color;
        pixels[int(y1)][x] = color;
    }
//    double x, y;
//    int index1, index2;
//    for(y = y0; y < y1; y++)
//    {
//        index1 = (int)y * 300 * 3 + (int)x0 * 3;
//        index2 = (int)y * 300 * 3 + (int)x1 * 3;
//
//        int blue = bgr >> 16;
//        int green = (bgr >> 8) & 0x00ff;
//        int red = bgr & 0x0000ff;
//        bits[index1 + 0] = bits[index2 + 0] = blue;
//        bits[index1 + 1] = bits[index2 + 1] = green;
//        bits[index1 + 2] = bits[index2 + 2] = red;
//    }
//    for(x = x0; x < x1; x++)
//    {
//        index1 = (int)y0 * 300 * 3 + (int)x * 3;
//        index2 = (int)y1 * 300 * 3 + (int)x * 3;
//
//        int blue = bgr >> 16;
//        int green = (bgr >> 8) & 0x00ff;
//        int red = bgr & 0x0000ff;
//        bits[index1 + 0] = bits[index2 + 0] = blue;
//        bits[index1 + 1] = bits[index2 + 1] = green;
//        bits[index1 + 2] = bits[index2 + 2] = red;
//    }
}
void Bitmap::write(const char* name) {
    int index;
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 300; j++){
            switch(pixels[i][j]){
                case 1:
                    bits[i*300*3 + j*3 + 0] = 255;
                    bits[i*300*3 + j*3 + 1] = 0;
                    bits[i*300*3 + j*3 + 2] = 0;
                    break;
                case 2:
                    bits[i*300*3 + j*3 + 0] = 0;
                    bits[i*300*3 + j*3 + 1] = 255;
                    bits[i*300*3 + j*3 + 2] = 0;
                    break;

                case 3:
                    bits[i*300*3 + j*3 + 0] = 0;
                    bits[i*300*3 + j*3 + 1] = 0;
                    bits[i*300*3 + j*3 + 2] = 255;
                    break;

            }
//            if(pixels[i][j] == 1){
//                bits[i*300*3 + j*3 + 0] = 255;
//                bits[i*300*3 + j*3 + 1] = 0;
//                bits[i*300*3 + j*3 + 2] = 0;
//            }
        }
    }
    FILE *output = fopen(name, "wb");
    if(output == nullptr){
        cout << "Cannot open file!\n";
    }
    else{
        fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
        fwrite(&bitmapHeader, sizeof(BITMAPINFOHEADER), 1, output);
        fwrite(bits, size, 1, output);
        fclose(output);
    }
}