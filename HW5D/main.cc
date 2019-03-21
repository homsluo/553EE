#include "Bitmap.hh"

int main() {
    Bitmap b(320,200);
    b.line(0,0, 100,100, 0xFF0000);
    b.write("test.bmp");
}