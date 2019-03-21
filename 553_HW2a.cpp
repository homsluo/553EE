/*
	 Author: Yuqing Luo

	 HW2a Windchill
*/
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    double C[12][18] = {0};
    int i, j;
    for (int v = 5; v <= 60; v += 5){
        cout << '\n';
        i = (v - 5)/5;
        j = 0;
        for (signed int t = 40; t >= -45; t -= 5){
            C[i][j] = 35.74 + 0.6215 * t - 35.75*pow(v,0.16) + 0.4275 *t* pow(v,0.16);
            cout << (int)C[i][j] << " ";
            j++;
        }
    }
    return 0;
}
