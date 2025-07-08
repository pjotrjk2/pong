#include "Collision.h"
#include <cmath>
#include <algorithm>
#include <raymath.h>

CollisionResult Collision::TestCollision(const Collider &a, const Collider &b)
{
    if (a.type == ColliderType::Circle && b.type == ColliderType::Circle)
        return CircleVsCircle(a.circleCollider, b.circleCollider);
    if (a.type == ColliderType::Circle && b.type == ColliderType::Rectangle)
        return CircleVsRect(a.circleCollider, b.rectCollider);
    if (a.type == ColliderType::Rectangle && b.type == ColliderType::Circle)
        return CircleVsRect(b.circleCollider, a.rectCollider); // reverse order
    if (a.type == ColliderType::Rectangle && b.type == ColliderType::Rectangle)
        return RectVsRect(a.rectCollider, b.rectCollider);

    return CollisionResult();
}

CollisionResult Collision::CircleVsCircle(const CircleCollider &a, const CircleCollider &b)
{
    // TODO add implementation
    return CollisionResult();
}

CollisionResult Collision::CircleVsRect(const CircleCollider &circle, const RectCollider &rect)
{
    // Step 1: Find closest point on rectangle to circle center
    Vector2 closestPoint;
    closestPoint.x = Clamp(circle.center.x, rect.rect.x, rect.rect.x + rect.rect.width);
    closestPoint.y = Clamp(circle.center.y, rect.rect.y, rect.rect.y + rect.rect.height);

    // Step 2: Vector from closest point to circle center
    Vector2 delta = Vector2Subtract(circle.center, closestPoint);
    float distanceSq = Vector2LengthSqr(delta);

    CollisionResult collisionResult;
    // Step 3: Check if it's within radius
    if (distanceSq <= circle.radius * circle.radius)
    {
        collisionResult.collided = true;
        collisionResult.contactPoint = closestPoint;

        // If delta is (0,0), it means circle is overlapping edge or corner — fake normal outward
        // if (distanceSq <= 1e-6f)
        if (distanceSq == 0)
        {
            // Pick the shortest direction out
            float left = fabsf(circle.center.x - rect.rect.x);
            float right = fabsf(circle.center.x - (rect.rect.x + rect.rect.width));
            float top = fabsf(circle.center.y - rect.rect.y);
            float bottom = fabsf(circle.center.y - (rect.rect.y + rect.rect.height));

            float minDist = std::min({left, right, top, bottom});

            if (minDist == left)
                collisionResult.normal = {-1, 0};
            else if (minDist == right)
                collisionResult.normal = {1, 0};
            else if (minDist == top)
                collisionResult.normal = {0, -1};
            else if (minDist == bottom)
                collisionResult.normal = {0, 1};
        }
        else
        {
            collisionResult.normal = Vector2Normalize(delta);
        }

        return collisionResult;
    }

    collisionResult.collided = false;
    return collisionResult;
}

CollisionResult Collision::RectVsRect(const RectCollider &a, const RectCollider &b)
{
    Vector2 closestPoint;
    closestPoint.x = (std::max(a.rect.x, b.rect.x) + std::min(a.rect.x + a.rect.width, b.rect.x + b.rect.width)) / 2;
    closestPoint.y = (std::max(a.rect.y, b.rect.y) + std::min(a.rect.y + a.rect.height, b.rect.y + b.rect.height)) / 2;

    // From center to closest point
    Vector2 delta = Vector2Subtract(Vector2{a.rect.x + a.rect.width / 2, a.rect.y + a.rect.height / 2}, closestPoint);
    float distanceSq = Vector2LengthSqr(delta);

    CollisionResult collisionResult;
    // Is vector itensiti of distance less than vector representing diagonal?
    if (distanceSq <= a.rect.width * a.rect.width / 4 + a.rect.height * a.rect.height / 4)
    {
        collisionResult.collided = true;
        collisionResult.contactPoint = closestPoint;

        // Where the fuck is contact closest?
        float left = fabsf(closestPoint.x - a.rect.x);
        float right = fabsf(closestPoint.x - (a.rect.x + a.rect.width));
        float top = fabsf(closestPoint.y - a.rect.y);
        float bottom = fabsf(closestPoint.y - (a.rect.y + a.rect.height));

        float minDist = std::min({left, right, top, bottom});

        if (minDist == left)
            collisionResult.normal = {-1, 0};
        else if (minDist == right)
            collisionResult.normal = {1, 0};
        else if (minDist == top)
            collisionResult.normal = {0, -1};
        else if (minDist == bottom)
            collisionResult.normal = {0, 1};

        return collisionResult;
    }

    collisionResult.collided = false;
    return collisionResult;
}
