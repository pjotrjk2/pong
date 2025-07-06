#ifndef BALL_H
#define BALL_H

#include <raylib.h>

class Game;

class Ball
{
public:
    Ball(float x, float y, Game *game, int speedX = 0, int speedY = 0, int radius = 20);

    void Draw();
    void ResetBall(bool playerServe);
    void Update();

    float x;
    float y;
    Game *game;
    int speedX, speedY;
    int radius;
};

#endif
