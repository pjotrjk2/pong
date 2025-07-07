#include "CpuRacket.h"
#include "Racket.h"
#include "Ball.h"

CpuRacket::CpuRacket(float x, float y, float width, float height, int speed) : Racket(x, y, width, height, speed)
{
}

void CpuRacket::Update()
{
    if (y + height / 2 > ball->GetHitbox().center.y)
    {
        y -= speed.y;
    }

    if (y + height / 2 < ball->GetHitbox().center.y)
    {
        y += speed.y;
    }

    LimitMovement();
}
