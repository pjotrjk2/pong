#ifndef COLLIDER_H
#define COLLIDER_H

#include <raylib.h>

enum class ColliderType
{
    Circle,
    Rectangle,
};

struct CircleCollider
{
    Vector2 center;
    float radius;
};

struct RectCollider
{
    Rectangle rect;
};

class Collider
{
public:
    ColliderType type;

    Vector2 center;
    CircleCollider circleCollider;
    RectCollider rectCollider;

    Collider() : type(ColliderType::Circle), center{0, 0}, circleCollider{center, 1} {}

    Collider(const Vector2 &center, float radius) : type(ColliderType::Circle), center(center), circleCollider{center, radius} {}

    Collider(const Rectangle &rect) : type(ColliderType::Rectangle), center(Vector2{(rect.x + rect.width) / 2, (rect.y + rect.height) / 2}), rectCollider{rect} {}

    Vector2 GetCenter();
};

#endif
