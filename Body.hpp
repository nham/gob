#ifndef BODY_H
#define BODY_H

struct Body {
    Vec2 pos;
    double rotation;

    Vec2 vel;
    double angVel;

    Vec2 force;
    double torque;

    Vec2 width;

    double friction;
    double m;
    double invMass;
    float I;
    float invI;
}

#endif
