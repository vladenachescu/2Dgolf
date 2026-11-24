// Main ships no test framework on purpose: plain assert / static_assert only.
// Full framework examples live on tests/gtest and tests/Boost-ext-ut branches.

// assert() disappears when NDEBUG is defined (Release, RelWithDebInfo): the
// binary would exit 0 having checked nothing, and CI would call that a pass.
// Keep the checks on in every build type.
#undef NDEBUG
#include <cassert>
#include  "Vector2D.h"
#include "Ball.h"
#include "Water.h"
#include "Hole.h" // the library under test; include/ comes from oop

// checked through the public interface only: the helper behind the invariant is

void testWater() {
    Water apa(4.0f, 6.0f, -2.0f, 2.0f);
    Ball minge(Vector2D(0.0f, 0.0f));
    minge.loveste(100.0f, 0.0f);
    minge.actualizeazaPozitia(0.1f);
    apa.interact(minge, Vector2D(0.0f, 0.0f), 0.1f);
    assert(minge.getPoz().dist(Vector2D(0.0f, 0.0f)) < 1e-3f);
}

void testHole() {
    Ball minge(Vector2D(0.0f, 0.0f));
    Hole gaura(Vector2D(10.0f, 0.0f ),1.0f);
    minge.loveste(100.0f, 0.0f);
    assert(!gaura.contine(minge.getPoz()));
    minge.actualizeazaPozitia(0.1f);
    assert(gaura.contine(minge.getPoz()));
}
int main() {
    testWater();
    testHole();
    return 0;


}
