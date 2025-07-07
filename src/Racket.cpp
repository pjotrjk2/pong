#include <raylib.h>
#include "Racket.h"
#include "Ball.h"

Racket::Racket(float x, float y, float width, float height, int speedOld)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speedOld = speedOld;
}

void Racket::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Racket::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y -= speedOld;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y += speedOld;
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
