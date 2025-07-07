#include "CpuRacket.h"
#include "Racket.h"
#include "Ball.h"
#include <iostream>

CpuRacket::CpuRacket(float x, float y, float width, float height, int speed) : Racket(x, y, width, height, speed)
{
}

void CpuRacket::Update()
{
    std::cout << "CPU detects: " << ball->GetHitbox().center.y;
    std::cout << " CPU at: " << y + height;
    if (y + height / 2 > ball->GetHitbox().center.y)
    {
        std::cout << " CPU moves up by: " << speedOld << "\n";
        y -= speedOld;
    }

    if (y + height / 2 < ball->GetHitbox().center.y)
    {
        std::cout << " CPU moves down by: " << speedOld << "\n";
        y += speedOld;
    }

    LimitMovement();
}
