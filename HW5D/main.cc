#include "Bitmap.hh"

int main() {
    Bitmap b(320,200);
    b.line(0,0, 100,100, 0xff0000);
    b.rect(50,0,100,50, 0x00FF00);
    b.write("test.bmp");
    b.load("red10x10.bmp");
    b.save("copy.bmp");
}