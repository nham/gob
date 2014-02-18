#ifndef BODY_H
#define BODY_H

#include "Maths.hpp"

struct Body {
    Vec2 pos;
    double rotation;

    Vec2 vel;
    double angVel;

    Vec2 force;
    double torque;

    Vec2 width;

    double friction;
    double mass;
    double invMass;
    float I;
    float invI;

    Body();
    Body(Vec2 const&, double m);
};

#endif
