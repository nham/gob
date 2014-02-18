#include "World.hpp"

using std::vector;

void World::add(Body* body) {
    this->bodies.push_back(body);
}

void World::clear() {
    this->bodies.clear();
}
