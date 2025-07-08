#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Racket.h"
#include "Frame.h"

class Game
{
public:
    Game(bool SinglePlayer);
    void StartGame();
    void Update();
    void Draw();
    void End();
    void IncreasePlayerLeftScore();
    void IncreasePlayerRightScre();

protected:
    void CheckCollisions();
    void DispatchEvents();

private:
    // Default configurations
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 800;
    const int FPS = 60;

    // Objects default configurations
    const int RACKET_WIDTH = 25;
    const int RACKET_HEIGHT = 125;
    const int BALL_RADIUS = 20;

    const float RACKET_SPEED = 6.0f;
    const float BALL_SPEED = 7.0f;

    // Game objects
    Racket *playerLeft;
    Racket *playerRight;
    Ball *ball;

    Frame *frameTop, *frameBottom;

    int playerLeftScore = 0;
    int playerRightScore = 0;
};

#endif
