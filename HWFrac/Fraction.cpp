//
// Created by KimLAB on 2/17/2019.
//
#include "Fraction.h"

using namespace std;

int Fraction::count = 0;

Fraction::Fraction(int n, int d):num(n), den(d){count++;}
Fraction::Fraction(int n) :num(n),den(1){count++;}
Fraction::Fraction() :num(1),den(1){count++;}

Fraction operator+(Fraction a, Fraction b) {
    Fraction ans(a.num*b.den+a.den*b.num, a.den*b.den);
    return ans;
}
Fraction operator-(Fraction a, Fraction b) {
    Fraction ans(a.num*b.den-a.den*b.num, a.den*b.den);
    return ans;
}
Fraction operator-(Fraction a){
    Fraction ans(-a.num, -a.den);
    return ans;
}
ostream& operator <<(ostream& s, Fraction a){
    return s << a.num << "/" << a.den;
}
