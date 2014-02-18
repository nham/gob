#ifndef MATHS_H
#define MATHS_H

#include <cmath>
#include <stdexcept>

constexpr double pi = 3.1415926535897932384626433832795028842;


struct Vec2 {
    double x, y;

    Vec2() {}
    Vec2(double x, double y) : x{x}, y{y} {}

    Vec2 operator -() {
        return Vec2(-x, -y);
    }

    Vec2 operator * (double c) {
        return Vec2(
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
        return Mat22(Vec2(row1.x, row2.x), Vec2(row1.y, row2.y));
    }

    Mat22 invert() const {
        double det = row1.x * row2.y - row1.y * row2.x; // 1/(ad - bc)

        if (det == 0.0)
            throw std::overflow_error("Divide by zero exception");

        auto new_row1 = Vec2(row2.y, -row1.y);
        auto new_row2 = Vec2(-row2.x, row1.x);
        new_row1 *= 1.0 / det;
        new_row2 *= 1.0 / det;

        return Mat22(new_row1, new_row2);
    }

}

#endif
