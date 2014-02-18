#ifndef MATHS_H
#define MATHS_H

#include <cmath>

constexpr double pi = 3.1415926535897932384626433832795028842;


struct Vec2 {
    double x, y;

    Vec2() {}
    Vec2(double x, double y) : x{x}, y{y} {}

    Vec2 operator -() {
        return Vec2(-x, -y);
    }

    void operator += (Vec2 const& vec) {
        x += vec.x;
        y += vec.y;
    }

    void operator -= (Vec2 const& vec) {
        x -= vec.x;
        y -= vec.y;
    }

    void operator *= (double c) {
        x *= c;
        y *= c;
    }

    double mag() {
        return sqrt(x*x + y*y);
    }
}


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

    Mat22 transpose() const {

    }

}

#endif
