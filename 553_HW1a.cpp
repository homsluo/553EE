/*
	 Author: Yuqing Luo

	 HW1a 3n + 1 conjecture
*/


#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Please input a number: " << endl;
    cin >> n;

    while(n != 1){
        if(n % 2){
            n = n * 3 + 1;
            cout << n << '\n';
        }
        else{
            n = n / 2;
            cout << n << '\n';
        }
    }
    return 0;
}
