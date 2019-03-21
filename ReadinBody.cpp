//
// Created by KimLAB on 2/20/2019.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class Body{
private:
    string name;
    double mass, radius, position_x, position_y, position_z;
public:
    Body(string n, double m, double r, double x, double y, double z):name(n),
    mass(m),radius(r), position_x(x), position_y(y), position_z(z){}
    void print() const{
        cout << "Name: " << this->name << ", Mass: " << this->mass << ", Radius: " << this->radius << ", Position: (" << this->position_x << ", " << this->position_y << ", " << this->position_z
        << ")" << '\n';
    }
};

int main(){
    char s[] = "solarsystem.dat";
    ifstream f(s);
    char buf[1024];
    string n, orb;
    double m, dia, per, aph, orbp, rot, axi, orbi;
    f.getline(buf, sizeof(buf));

    while(!f.eof()){
        f.getline(buf, sizeof(buf));
        istringstream linestr(buf);
        linestr >> n >> orb >> m >> dia >> per >> aph >> orbp >> rot >>axi >> orbi;
        const Body a(n, m, dia/2, (per+aph)/2, 0, 0);
        a.print();

    }
}