#ifndef MATHS_H
#define MATHS_H

#include <cmath>
#include <stdexcept>
#include <limits>

constexpr double pi = 3.1415926535897932384626433832795028842;


struct Vec2 {
    double x, y;

    Vec2() {}
    Vec2(double x, double y) : x{x}, y{y} {}

    Vec2 operator -();
    void operator += (Vec2 const& vec);
    void operator -= (Vec2 const& vec);
    void operator *= (double c);
    double mag();
};


struct Mat22 {
    Vec2 row1, row2;

    Mat22() {}

    // construct a rotation matrix
    Mat22(double ang) {
        double c = cos(ang);
        double s = sin(ang);
        row1 = Vec2(c, -s);
        row2 = Vec2(s, c);
    }

    Mat22(Vec2 const& r1, Vec2 const& r2) : row1{r1}, row2{r2} {}

    Mat22 transpose() const;
    Mat22 invert() const;
};

double dot(Vec2 const& a, Vec2 const& b);
double cross(Vec2 const& a, Vec2 const& b);
Vec2 operator *  (double c, Vec2 const& v);
Vec2 operator + (Vec2 const& u, Vec2 const& v);

#endif
