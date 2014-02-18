#ifndef BODY_H
#define BODY_H

#include <vector>
#include "Maths.hpp"

struct Body;

struct World {
    std::vector<Body*> bodies;
    Vec2 gravity;
    int iterations;

    World(Vec2 grav, int iterations) : gravity{grav}, iterations{iterations} {}

    void step(double dt);
    void add(Body* body);
    void clear();
};

#endif
