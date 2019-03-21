/*
	 Author: Yuqing Luo

	 Read In Object From File
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;


class Vec3d{
private:
    double x, y, z;
public:
    Vec3d(double x, double y, double z):x(x), y(y), z(z){}

    friend ostream &operator<<(ostream &s, Vec3d a);


};

class Body{
private:
    string name;
    double mass;
    double radius;
    Vec3d pos;
    static const double G;
public:
    Body(const string& name, double mass, double radius, Vec3d pos)
    :name(name), mass(mass), radius(radius), pos(pos){}

    friend ostream &operator<<(ostream &s, Body a);


};

const double Body::G = 6.67E-11;

class SolarSystem {
private:
    vector<Body> Bodies;
public:
    SolarSystem(const string &x) {
        ifstream f(x);
        char buf[1024];
        string n, orb;
        double m, dia, per, aph, orbp, rot, axi, orbi;
        f.getline(buf, sizeof(buf));

        while (!f.eof()) {
            f.getline(buf, sizeof(buf));
            istringstream linestr(buf);
            linestr >> n >> orb >> m >> dia >> per >> aph >> orbp >> rot >> axi >> orbi;
            Body a(n, m, dia / 2, Vec3d((per + aph) / 2, 0, 0));
            Bodies.push_back(a);
        }
    }


    friend ostream &operator<<(ostream &s, SolarSystem a);
};

ostream& operator << (ostream& s, Vec3d a){
    s << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return s;
}

ostream& operator <<(ostream& s, Body a){
    s << "Name: " << a.name << ", Mass: " << a.mass << "kg, Radius: " << a.radius << "m, Postion: "<< a.pos << '\n';
    return s;
}

ostream& operator << (ostream& s, SolarSystem a){
    for(auto i: a.Bodies)
        s << i ;
    return  s;
}


int main(){
    SolarSystem s("solarsystem.dat");
    cout << s;
    return 0;
}
