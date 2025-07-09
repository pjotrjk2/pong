#include <raylib.h>
#include <random>
#include <ctime>
#include "Ball.h"
#include "Game.h"

void Ball::Draw()
{
    DrawCircleV(center, radius, WHITE);
}

void Ball::ResetBall(bool playerServe)
{
    center = resetPoint;

    float directionX = 1.0f;
    if (!playerServe)
        directionX = -1.0f;

    const float maxSpeed = 6 * sqrt(2); // 6 by x, 6 by y, thats 6 squared times twice for total intensity

    // TODO loook mama, random float!
    std::random_device rd;
    std::mt19937 e2(rd());
    // std::uniform_real_distribution<> dist(0.1, maxSpeed); // 0 is bullshit, but but 0.1 would be really funny lol
    std::uniform_real_distribution<> dist(4, maxSpeed); // 0.1 was also bullshit when i i tried it :(
    float x = dist(e2);
    float y = sqrt(maxSpeed * maxSpeed - x * x);

    // random up or down
    std::srand(std::time(0));
    float directionY = (rand() % 2) ? -1.0f : 1.0f;

    speed = Vector2{directionX * x, directionY * y};
}

void Ball::Update()
{
    center.x += speed.x;
    center.y += speed.y;
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
