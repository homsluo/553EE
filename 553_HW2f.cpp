/*
	 Author: Yuqing Luo

	 HW2f string manipulation
*/
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string b, c;
    getline(cin, b);
    int n = b.size();
    int j = 0;
    for (int i = n-1; i>=0; i--){
        c += b[i];
    }
    cout << "1.Backward: " << c << endl;
    cout << "2.Compare: ";
    if (b == c)
        cout << "Same" << endl;
    else
        cout << "Different" << endl;

    for (int i = 0; i <= n-1; i++){
        if(b[j] == 'a' || b[j] == 'e' || b[j] == 'i' || b[j] == 'o' || b[j] == 'u') {
            b.erase(j, 1);
            j--;
        }
        j++;
    }
    cout << "3.Delete: " << b;
}
