
#include "Maths.hpp"

Vec2 Vec2::operator -() {
    return Vec2(-x, -y);
}

void Vec2::operator += (Vec2 const& vec) {
    x += vec.x;
    y += vec.y;
}

void Vec2::operator -= (Vec2 const& vec) {
    x -= vec.x;
    y -= vec.y;
}

void Vec2::operator *= (double c) {
    x *= c;
    y *= c;
}

double Vec2::mag() {
    return sqrt(x*x + y*y);
}


double dot(Vec2 const& a, Vec2 const& b) {
    return a.x * b.x + a.y * b.y;
}

double cross(Vec2 const& a, Vec2 const& b) {
    return a.x * b.y - a.y * b.x;
}

Vec2 operator *  (double c, Vec2 const& v) {
    return Vec2(c * v.x, c * v.y);
}

Vec2 operator + (Vec2 const& u, Vec2 const& v) {
    return Vec2(u.x + v.x, u.y + v.y);
}


Mat22 Mat22::transpose() const {
    return Mat22(Vec2(row1.x, row2.x), Vec2(row1.y, row2.y));
}

Mat22 Mat22::invert() const {
    double det = row1.x * row2.y - row1.y * row2.x; // 1/(ad - bc)

    if (det == 0.0)
        throw std::overflow_error("Divide by zero exception");

    auto new_row1 = Vec2(row2.y, -row1.y);
    auto new_row2 = Vec2(-row2.x, row1.x);
    new_row1 *= 1.0 / det;
    new_row2 *= 1.0 / det;

    return Mat22(new_row1, new_row2);
}
