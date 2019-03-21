/*
	 Author: Yuqing Luo

	 HW1f Mystery Sum
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    float s = 0,s1 = 0, s2 = 0, temp;

    for (int i = 1; i <= 10000; i++){
        temp = s;
        s += 1.0 / (i * i);
        if (abs(s - temp) <= 0.0000001){
            cout << "Iteration: " << i << '\n';
            cout << "sqrt(6 * s) = " << fixed << setprecision(8) << sqrt(6 * s) << '\n';
            break;
        }
    }

    for (int i = 1; i <= 10000; i++){
        s1 += 1.0/ (i * i);
    }
    for (int i = 10000; i > 0; i--){
        s2 += 1.0/ (i * i);
    }
    cout << "sqrt(6 * s1) = " << sqrt(6 * s1) << '\n';
    cout << "sqrt(6 * s2) = " << sqrt(6 * s2) << '\n';
    return 0;
}
