#include "World.hpp"
#include "Body.hpp"

int main() {
    double dt = 0.01;
    int iters = 10;
    auto g = Vec2(0.0, -9.8);

    World world {g, iters};

    auto b1 = Body(Vec2(60.0, 30.0), std::numeric_limits<double>::max());
    b1.pos = Vec2(-2.0, 10.0);

    auto b2 = Body(Vec2(4.0, 4.0), 100.0);
    b2.pos = Vec2(5.0, 5.0);

    world.add(b1);
    world.add(b2);

    world.step();
}
