#ifndef I_MOVABLE_H
#define I_MOVABLE_H

class IMovable
{
public:
    virtual Vector2 GetSpeed() = 0;
    virtual void SetSpeed(Vector2 speed) = 0;
    virtual ~IMovable() {};
};

#endif
