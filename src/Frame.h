#ifndef FRAME_H
#define FRAME_H

#include "ICollidable.h"

class Frame : public ICollidable
{
public:
    Frame(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {};
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
