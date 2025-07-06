#include <raylib.h>
#include "racket.h"
#include "ball.h"

Racket::Racket(float x, float y, float width, float height, int speed)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->speed = speed;
}

void Racket::Draw()
{
    DrawRectangle(x, y, width, height, WHITE);
}

void Racket::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y -= speed;
    }

    if (IsKeyDown(KEY_DOWN))
    {
        y += speed;
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
