#include <raylib.h>
#include "Racket.h"
#include "Ball.h"

void Racket::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Racket::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y -= speed.y;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y += speed.y;
    }

    LimitMovement();
}

void Racket::ShowBall(Ball *ball)
{
    this->ball = ball;
}

void Racket::LimitMovement()
{
    if (y <= 0)
    {
        y = 0;
    }

    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height;
    }
}

Vector2 Racket::GetSpeed()
{
    return speed;
}

void Racket::SetSpeed(Vector2 speed)
{
    this->speed = speed;
}

Collider Racket::GetHitbox()
{
    return Collider(Rectangle{x, y, width, height});
}

float Racket::GetMass()
{
    return mass;
}
