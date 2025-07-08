#include "CpuRacket.h"
#include "Racket.h"
#include "Ball.h"
#include "raymath.h"

void CpuRacket::Update()
{
    Vector2 direction = {0, 0};
    if (y + height / 2 < ball->GetHitbox().center.y)
    {
        direction = {0, 1};
    }
    if (y + height / 2 > ball->GetHitbox().center.y)
    {
        direction = {0, -1};
    }

    Racket::SetSpeed(Vector2Multiply(maxSpeed, direction));
    Racket::Update();
}
