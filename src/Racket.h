#ifndef RACKET_H
#define RACKET_H

#include <raylib.h>
#include "ICollidable.h"
#include "IMovable.h"
#include "Ball.h"

class Racket : public ICollidable, IMovable
{
public:
    float x, y;
    float width, height;
    int speedOld;
    Ball *ball;

    Racket(float x, float y, float width, float height, int speed);
    void Draw();
    virtual void Update();
    void ShowBall(Ball *ball);

    // IMovable
    Vector2 GetSpeed() override;
    void SetSpeed(Vector2 speed) override;

    // IColidable
    Collider GetHitbox() override;
    float GetMass() override;

protected:
    void LimitMovement();

private:
    Vector2 speed;
    float mass;
    Collider hitbox;
};

#endif
