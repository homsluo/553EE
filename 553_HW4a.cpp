#include <iostream>
#include <cmath>
using namespace std;

class Vec3d{
private:
    double axis_x, axis_y, axis_z;
    static double dot(Vec3d a, Vec3d b){
        double ans(a.axis_x * b.axis_x + a.axis_y * b.axis_y + a.axis_z * b.axis_z);
        return ans;
    }
public:
    Vec3d() : axis_x(0), axis_y(0), axis_z(0){}
    Vec3d(double x) : axis_x(x), axis_y(0), axis_z(0){}
    Vec3d(double x, double y) : axis_x(x), axis_y(y), axis_z(0){}
    Vec3d(double x, double y, double z) : axis_x(x), axis_y(y), axis_z(z){}

    double dot(Vec3d a) const {
        double ans(this->axis_x * a.axis_x + this->axis_y * a.axis_y + this->axis_z * a.axis_z);
        return ans;
    }

    double mag() const{
        double ans(sqrt(pow(this->axis_x, 2)+pow(this->axis_y, 2)+pow(this->axis_z, 2)));
        return ans;
    }
    double magSq() const{
        double ans(pow(this->axis_x, 2)+pow(this->axis_y, 2)+pow(this->axis_z, 2));
        return ans;
    }
    double dist(Vec3d a) const{
        double ans(sqrt(pow(this->axis_x - a.axis_x, 2)+pow(this->axis_y - a.axis_y, 2)+pow(this->axis_z - a.axis_z, 2)));
        return ans;
    }

    friend Vec3d operator +( Vec3d a,  Vec3d b);
    friend Vec3d operator -( Vec3d a,  Vec3d b);
    friend Vec3d operator -( Vec3d a);
    friend ostream& operator <<(ostream& out,const Vec3d& a);
    friend double dot( Vec3d a,  Vec3d b);

};

Vec3d operator +(const Vec3d a,const Vec3d b) {
    Vec3d ans(a.axis_x + b.axis_x, a.axis_y + b.axis_y, a.axis_z + b.axis_z);
    return ans;
}
Vec3d operator -(const Vec3d a, const Vec3d b) {
    Vec3d ans(a.axis_x - b.axis_x, a.axis_y - b.axis_y, a.axis_z - b.axis_z);
    return ans;
}
Vec3d operator -(const Vec3d a){
    Vec3d ans(0 - a.axis_x, 0 - a.axis_y, 0 - a.axis_z);
    return ans;
}
ostream& operator <<(ostream& out,const Vec3d& a){
    out << "(" << a.axis_x << ", " << a.axis_y << ", " << a.axis_z << ")";
    return out;
}

double  dot(const Vec3d a, const Vec3d b) {
    double ans(Vec3d::dot(a,b));
    return ans;
}

int main() {
    // use friend operators
    const Vec3d a(1.0,2.5,3.5); // double precision!
    const Vec3d b(2.0);         //(2,0,0)
    const Vec3d c(2.0,3.5);     //(2,3.5,0)
    const Vec3d e;              //(0,0,0)

    const Vec3d f = a + e;
    const Vec3d g = b - e; // d is not an object, pick a different one
    double x = dot(f, g); // regular function  f.x*g.x + f.y*g.y + f.z*g.z
    //	double y = Vec3d::dot(f,g); // static function
    double z = f.dot(g); // method
    const Vec3d h = -b;

    double dist = f.mag(); // square root of sum of square
    double dist2 = f.magSq(); // sum of square
    double dist3 = f.dist(g); // sqrt or sum of square of diff
    //dx = f.x-g.x  dy = f.y - g.y      dx*dx + dy*dy...
    cout << a << '\n';
    cout << b << '\n';
    cout << c << '\n';
    cout << e << '\n';
    cout << f << '\n';
    cout << g << '\n';
    cout << h << '\n';
    cout << dist << '\n';
    cout << dist2 << '\n';
    cout << dist2 << '\n';
}