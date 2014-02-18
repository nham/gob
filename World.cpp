#include "World.hpp"
#include "Body.hpp"

using std::vector;

void World::add(Body* body) {
    this->bodies.push_back(body);
}

void World::clear() {
    this->bodies.clear();
}

void World::step(double dt) {
    // euler integration!
    for (auto b : bodies) {
        // objects with no mass experience infinite force, which is kinda weird,
        // so just bail 
        if (b->invMass == 0.0) continue;

        b->vel += dt * (this->gravity + b->invMass * b->force);
        b->angVel += dt * b->invI * b->torque;
    }

    // now euler integrate the velocities
    for (auto b: bodies) {
        b->pos += dt * b->vel;
        b->rotation += dt * b->angVel;
    }

}
