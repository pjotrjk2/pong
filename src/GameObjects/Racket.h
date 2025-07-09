#ifndef RACKET_H
#define RACKET_H

#include "raylib.h"
#include "GameMechanics/ICollidable.h"
#include "GameMechanics/IMovable.h"
#include "Ball.h"

class Racket : public ICollidable, IMovable
{
public:
    Racket(float x, float y, float width, float height, float speed) : x(x), y(y), width(width), height(height), speed{0, speed} {};
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
    float x, y;
    float width, height;
    Vector2 speed;
    float mass;
    Ball *ball;
};

#endif
