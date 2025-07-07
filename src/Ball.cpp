#include "Ball.h"
#include "Game.h"
#include <raylib.h>

void Ball::Draw()
{
    DrawCircleV(center, radius, WHITE);
}

void Ball::ResetBall(bool playerServe)
{
    center = Vector2{
        (float)GetScreenWidth() / 2,
        (float)GetScreenHeight() / 2};

    int direction = 1;
    if (!playerServe)
        direction = -1;

    speed = Vector2{direction * 7.0f, direction * 7.0f};
}

void Ball::Update()
{
    center.x += speed.x;
    center.y += speed.y;

    if (center.y + radius >= GetScreenHeight() || center.y - radius <= 0)
    {
        speed.y *= -1;
    }

    if (center.x + radius >= GetScreenWidth())
    {
        game->IncreasePlayerLeftScore();
        ResetBall(true);
    }

    if (center.x - radius <= 0)
    {
        game->IncreasePlayerRightScre();
        ResetBall(false);
    }
}

Vector2 Ball::GetSpeed()
{
    return speed;
}

void Ball::SetSpeed(Vector2 speed)
{
    this->speed = speed;
}

Collider Ball::GetHitbox()
{
    return Collider(center, radius);
}

float Ball::GetMass()
{
    return mass;
}
