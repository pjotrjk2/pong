#include "cpu_racket.h"
#include "racket.h"
#include "ball.h"

CpuRacket::CpuRacket(float x, float y, float width, float height, int speed) : Racket(x, y, width, height, speed)
{
}

void CpuRacket::Update()
{
    if (y + height / 2 > ball->y)
    {
        y -= speed;
    }

    if (y + height / 2 < ball->y)
    {
        y += speed;
    }

    LimitMovement();
}
