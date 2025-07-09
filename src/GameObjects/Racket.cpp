#include "raylib.h"
#include "Racket.h"
#include "Ball.h"

void Racket::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Racket::Update()
{
    y += speed.y;
}

void Racket::ShowBall(Ball *ball)
{
    this->ball = ball;
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
