/*
	 Author: Yuqing Luo

	 HW2D RobotLocationEstimator
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void LocationEstimator(double theta, double dis, double& X, double& Y ){
        X += dis * sin(theta * 3.1415 / 180);
        Y += dis * cos(theta * 3.1415 / 180);
}

int main(){
    ifstream f("hw3c.dat");
    if (!f){
        cout <<"Open failed";
        return 0;
    }

    double array[256] = {0};
    double X = 0, Y = 0;
    int n, i = 0;

    while(true){
        f >> array[i];
        if (array[i] < 0)
            break;
        n = i;
        i++;
    }

    for (i = 0; i <= n - 1; i += 2){
        double theta = array[i];
        double dis = array[i + 1];
        LocationEstimator(theta, dis, X, Y);
        cout << "theta: " << theta << "  distance: " << dis << endl;
        cout << "Location: " << "x = " << X << "  y = " << Y << endl;
    }
}