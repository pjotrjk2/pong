#ifndef BALL_H
#define BALL_H

#include "raylib.h"
#include "GameMechanics/IMovable.h"
#include "GameMechanics/ICollidable.h"

class Game;

class Ball : public IMovable, ICollidable
{
public:
    Ball(Game *game, Vector2 resetPoint) : game(game), radius(20), resetPoint(resetPoint) {}

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
    Vector2 resetPoint;
};

#endif
