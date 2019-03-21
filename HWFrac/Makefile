frac: Fraction.o main.o
	g++ Fraction.o main.o -o frac

Fraction.o: Fraction.h Fraction.cpp
	g++ -c Fraction.cpp

main.o: main.cpp Fraction.h
	g++ -c main.cpp
