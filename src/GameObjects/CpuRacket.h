#ifndef CPU_RACKET_H
#define CPU_RACKET_H

#include "Racket.h"

class Racket;

class CpuRacket : public Racket
{
public:
    CpuRacket(float x, float y, float width, float height, float speed, float maxSpeed) : Racket(x, y, width, height, speed), maxSpeed(Vector2{0, maxSpeed}) {};
    void Update() override;

private:
    Vector2 maxSpeed;
};

#endif
