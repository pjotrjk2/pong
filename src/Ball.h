#ifndef BALL_H
#define BALL_H

#include <raylib.h>
#include "IMovable.h"
#include "ICollidable.h"

class Game;

class Ball : public IMovable, ICollidable
{
public:
    Ball(float x, float y, Game *game, int speedX = 0, int speedY = 0, int radius = 20) : center{x, y}, game(game), speed{speedX, speedY}, radius(radius) {}

    void Draw();
    void ResetBall(bool playerServe);
    void Update();

    // IMovable
    Vector2 GetSpeed() override;
    void SetSpeed(Vector2 speed) override;

    // IColidable
    Collider GetHitbox() override;
    float GetMass() override;

private:
    Vector2 center;
    Game *game;
    Vector2 speed;
    float mass;
    int radius;
};

#endif
