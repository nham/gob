#include "Body.hpp"

Body::Body() {
    pos = Vec2();
    vel = Vec2();
    force = Vec2();
    rotation = angVel = torque = 0.0;

    width = Vec2(1.0, 1.0);
    friction = 0.1;
    mass = std::numeric_limits<double>::max();
    invMass = 0.0;
    I = std::numeric_limits<double>::max();
    invI = 0.0;
}

Body::Body(Vec2 const& w, double m) {
    pos = Vec2();
    vel = Vec2();
    force = Vec2();
    rotation = angVel = torque = 0.0;

    friction = 0.1;
    width = w;
    mass = m;

    // stolen from Box2D Lite. TODO: understand
    if (mass < std::numeric_limits<double>::max()) {
        invMass = 1.0 / mass;
        I = mass * (width.x * width.x + width.y * width.y) / 12.0;
        invI = 1.0 / I;
    } else {
        invMass = 0.0;
        I = std::numeric_limits<double>::max();
        invI = 0.0;
    }
}
