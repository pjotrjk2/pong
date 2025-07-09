#ifndef GOALPOST_H
#define GOALPOST_H

#include "GameMechanics/ICollidable.h"

class Goalpost : ICollidable
{
public:
    Goalpost(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};
    void Draw();
    virtual void Update();

    // IColidable
    Collider GetHitbox() override;
    float GetMass() override;

private:
    float x, y;
    float width, height;
    float mass;
};

#endif
