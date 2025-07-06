#include "ball.h"
#include "game.h"
#include <raylib.h>

Ball::Ball(float x, float y, Game *game, int speedX, int speedY, int radius) : x(x), y(y), game(game), speedX(speedX), speedY(speedY), radius(radius)
{
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

void Ball::ResetBall(bool playerServe)
{
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;

    int direction = 1;
    if (!playerServe)
        direction = -1;
    speedX = direction * 7;
    speedY = direction * 7;
}

void Ball::Update()
{
    x += speedX;
    y += speedY;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speedY *= -1;
    }

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
    {
        speedX *= -1;
    }

    if (x + radius >= GetScreenWidth())
    {
        game->increasePlayerLeftScore();
        ResetBall(true);
    }

    if (x - radius <= 0)
    {
        game->increasePlayerRightScre();
        ResetBall(false);
    }
}
