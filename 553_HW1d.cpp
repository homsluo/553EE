/*
	 Author: Yuqing Luo

	 HW1d Sum reciprocals
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    float sum1f = 0, sum2f = 0;
    double sum1d = 0, sum2d = 0;

    for (int i = 1; i <= 100; i++){
        sum1f += 1.0/i;
        sum1d += 1.0/i;
    }
    for (int i = 100; i > 0; i--){
        sum2f += 1.0/i;
        sum2d += 1.0/i;
    }
    cout << "sum1f = " << fixed << setprecision(8) << sum1f  <<'\n';
    cout << "sum1d = " << fixed << setprecision(16) << sum1d  <<'\n';
    cout << "sum2f = " << fixed << setprecision(8) << sum2f  <<'\n';
    cout << "sum2d = " << fixed << setprecision(16) << sum2d  <<'\n';

    return 0;
}