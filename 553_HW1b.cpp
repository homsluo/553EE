/*
	 Author: Yuqing Luo

	 HW1b convergence of n-gons
*/

#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

int main(){
    double r = 1;

    for ( int i = 3; i <= 1000000; i++){
        double theta = PI / i;
        r = r / cos(theta);
        if(i == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000){
            cout << "n = " << i << ", " << "r = " << r << '\n';
        }
    }
    return 0;
}