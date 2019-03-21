/*
	 Author: Yuqing Luo

	 HW1c sum the numbers from 1 to 100
*/
#include <iostream>

using namespace std;

int main(){
    int sum_G, sum = 0, n = 100;

    sum_G = n * (n + 1) / 2;

    for (int i = 1; i <= n; i++){
        sum += i;
    }

    cout << "sum_G = " << sum_G << ", ";
    cout << "sum = " << sum << '\n';

    if (sum_G == sum){
        cout << "same" << '\n';
    }
    else{
        cout << "not same" << '\n';
    }
    return 0;
}