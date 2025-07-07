#ifndef I_COLLIDABLE_H
#define I_COLLIDABLE_H

#include <raylib.h>
#include "Collider.h"

class ICollidable
{
public:
    virtual Collider GetHitbox() = 0;
    virtual float GetMass() = 0;
    virtual ~ICollidable() {};
};

#endif
