/*
	 Author: Yuqing Luo

	 HW2b Primes
*/
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long long p){
    if (p < 2)
        return false;
    if (p == 2 || p == 3)
        return true;
    if ((p % 6 != 1) && (p % 6 != 5))
        return false;
    else {
        for (int i = 3; i <= sqrt(p); i += 2){
            if (p % i == 0)
                return false;
        }
    }
    return true;
}

int main(){
    unsigned long long p;
    cout << "Please input an integer:";
    cin >> p;
    bool f = isPrime(p);
    if (f)
        cout << p << " is prime number";
    else
        cout << p << " is not prime number";
    return 0;
}