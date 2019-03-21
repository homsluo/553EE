/*
	 Author: Yuqing Luo

	 HW3a Complex
*/
#include <iostream>
using namespace std;

class Complex{
private:
    double real, imag;
public:
    Complex(double r, double i) : real(r), imag(i) {}

    void print() const{
        cout << "(" << real << ", " << imag << ")" << '\n';
    }

    friend Complex operator +(Complex a, Complex b);
    friend Complex operator -(Complex b);

    Complex add(Complex b) const {
        Complex ans(this->real + b.real, this->imag + b.imag);
        return ans;
    }

};


int main() {
    const Complex a(1.0, 2.0); // create a complex number with real=1.0 imag=2.0
    const Complex b(0.5, 0.0); // real = 0.5, imag = 0.0
    const Complex c = a + b;   // overload operator + using the first syntax we discussed
    c.print(); // should print the following to cout: (1.5,2.0)
    // (member syntax).  Should look the same as method add where the name add
    // is replaced by operator +
    const Complex d = a.add(b); // this should be the same as the above except the name
    d.print();
    Complex e = -d;
    e.print();
}

Complex operator +(Complex a, Complex b){
    Complex ans(a.real + b.real, a.imag + b.imag);
    return ans;
}
Complex operator -(Complex b){
    Complex ans(-b.real, -b.imag);
    return ans;
}