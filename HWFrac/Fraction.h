//
// Created by KimLAB on 2/17/2019.
//
#include <iostream>

class Fraction{
private:
    int num, den;
    static int count;
public:
    Fraction(int n, int d);
    Fraction(int n);
    Fraction();

    Fraction add(Fraction a) const{
        Fraction ans(this->num*a.den + a.num*this->den, this->den*a.den);
        return ans;
    }
    static int getCount(){
        return  count;
    }

    friend Fraction operator +(Fraction a, Fraction b);
    friend Fraction operator -(Fraction a, Fraction b);
    friend Fraction operator -(Fraction a);
    friend std::ostream& operator <<(std::ostream& s, Fraction a);
};
