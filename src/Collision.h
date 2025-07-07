#ifndef COLLISION_H
#define COLLISION_H

#include "Collider.h"
#include "CollisionResult.h"

namespace Collision
{
    CollisionResult CircleVsCircle(const CircleCollider &a, const CircleCollider &b);
    CollisionResult CircleVsRect(const CircleCollider &a, const RectCollider &b);
    CollisionResult RectVsRect(const RectCollider &a, const RectCollider &b);

    CollisionResult TestCollision(const Collider &a, const Collider &b);
}

#endif
