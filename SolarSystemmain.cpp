//
// Created by KimLAB on 2/21/2019.
//
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Vec3d{
private:
    double x, y, z;
public:
};
class Body{
private:
    string name;
    double mass;
    Vec3d pos;
    Vec3d vel;
    Vec3d a;
    static const double G;
public:
    Body(const string& name, double mass, Vec3d pos, Vec3d vel)
    :name(name), mass(mass), pos(pos),vel(vel){}
};

const double Body::G = 6.67E-11;

class SolarSystem{
private:
    vector<Body>bodies;
};

int main(){
    SolarSystem s("solarsystem.dat")
    cout << s; //print out each body with name, mass, etc....
}