#include <iostream>
#include <cmath>
#include <cassert>

class Vec2;
class PVec2;


class Vec2 {
private:
    double x;
    double y;

public:
    Vec2(double x, double y);
    static Vec2 from_polar(PVec2 p);
    
    double get_x();
    double get_y();

    double get_r();
    double get_phi();
};

class PVec2 {
private:
    double r;
    double phi;

public:
    PVec2(double r, double phi);
    static PVec2 from_cartesian(Vec2 p);

    double get_x();
    double get_y();

    double get_r();
    double get_phi();
};


Vec2::Vec2(double x, double y) {
    this->x = x;
    this->y = y;
}
Vec2 Vec2::from_polar(PVec2 p) {
    return Vec2(p.get_x(), p.get_y());
}

double Vec2::get_x() {
    return this->x;
}
double Vec2::get_y() {
    return this->y;
}

double Vec2::get_r() {
    return sqrt(x*x + y*y);
}
double Vec2::get_phi() {
    return atan2(y, x);
}

PVec2::PVec2(double r, double phi) {
    this->r = r;
    this->phi = phi;
}

PVec2 PVec2::from_cartesian(Vec2 p) {
    return PVec2(p.get_r(), p.get_phi());
}

double PVec2::get_x() {
    return r*cos(phi);
}
double PVec2::get_y() {
    return r*sin(phi);
}

double PVec2::get_r() {
    return r;
}
double PVec2::get_phi() {
    return phi;
}

bool fcmp(double a, double b, double eps=1e-8) {
    return fabs(a - b) < eps;
}

int main() {
    double x = 3.0, y = 4.0;
    PVec2 pv = PVec2::from_cartesian(Vec2(x, y));
    assert(fcmp(x, pv.get_x()));
    assert(fcmp(y, pv.get_y()));

    double r = 1.0, phi = M_PI/3.0;
    Vec2 v = Vec2::from_polar(PVec2(r, phi));
    assert(fcmp(r, v.get_r()));
    assert(fcmp(phi, v.get_phi()));

    std::cout << "Complete!" << std::endl;
    return 0;
}
