#include "Bitmap.hh"

int main(){
    Bitmap b;
    b.line(0,0,200,100,0xff0000);
    b.rect(50,0,100,50, 0x00FF00);
    b.write("test.bmp");
}
