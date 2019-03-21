/*
	 Author: Yuqing Luo

	 HW2c Multiple primes
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

int countPrimes(unsigned long long a, unsigned long long b){
    int count = 0;
    for (unsigned long long i = a; i <= b; i++){
        bool f = isPrime(i);
        if (f)
            count++;
    }
    return count;
}

int main(){
    unsigned long long a, b;
    cout << "Please input the range: ";
    cin >> a >> b;
    int s = countPrimes(a,b);
    cout <<s;
}