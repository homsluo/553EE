/*
	 Author: Yuqing Luo

	 HW2e Recursive Fibonacci
*/
#include <iostream>

using namespace std;

uint64_t fibo(int n){
    if(n == 1 || n == 2)
        return 1;
    static uint64_t fibo2[500] = {0};
    if(fibo2[n] != 0)
        return fibo2[n];
    return fibo2[n] = fibo(n - 1) + fibo(n - 2);
}

int main(){
    int n;
    cout << "input number: ";
    cin >> n;
    uint64_t f = fibo(n);
    cout << f;
}
