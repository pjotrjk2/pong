#ifndef CPU_RACKET_H
#define CPU_RACKET_H

#include "Racket.h"

class Racket;

class CpuRacket : public Racket
{
public:
    CpuRacket(float x, float y, float width, float height, int speed);
    void Update() override;
};

#endif
