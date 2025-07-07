#ifndef COLLISION_RESULT_H
#define COLLISION_RESULT_H

#include <raylib.h>

struct CollisionResult
{
    bool collided = false;
    Vector2 normal = {0, 0};
    Vector2 contactPoint = {0, 0};
};

#endif
