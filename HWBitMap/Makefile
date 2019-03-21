
Bitmap: Bitmap.o main.o
	g++ Bitmap.o main.o -o Bitmap

Bitmap.o: Bitmap.hh Bitmap.cc
	g++ -c Bitmap.cc

main.o: main.cc Bitmap.hh
	g++ -c main.cc
