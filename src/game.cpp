#include <raylib.h>
#include "ball.h"
#include "racket.h"
#include "cpu_racket.h"
#include "game.h"

Game::Game(bool singlePlayer)
{
    playerLeft = new Racket(10,
                            SCREEN_HEIGHT / 2 - RACKET_HEIGHT / 2,
                            RACKET_WIDTH,
                            RACKET_HEIGHT,
                            6);

    if (!singlePlayer)
    {

        playerRight = new Racket(SCREEN_WIDTH - RACKET_WIDTH - 10,
                                 SCREEN_HEIGHT / 2 - RACKET_HEIGHT / 2,
                                 RACKET_WIDTH,
                                 RACKET_HEIGHT,
                                 6);
    }
    else
    {

        playerRight = new CpuRacket(SCREEN_WIDTH - RACKET_WIDTH - 10,
                                    SCREEN_HEIGHT / 2 - RACKET_HEIGHT / 2,
                                    RACKET_WIDTH,
                                    RACKET_HEIGHT,
                                    6);
    }

    ball = new Ball(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, this, 7, 7, 20);

    playerLeft->ShowBall(ball);
    playerRight->ShowBall(ball);
}

void Game::StartGame()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Perica's pong game");
    SetTargetFPS(60);
}

void Game::Update()
{
    ball->Update();
    playerLeft->Update();
    playerRight->Update();

    // Checking for collisions?
    if (CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{playerLeft->x, playerLeft->y, playerLeft->width, playerLeft->height}))
    {
        ball->speedX *= -1;
    }

    if (CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius, Rectangle{playerRight->x, playerRight->y, playerRight->width, playerRight->height}))
    {
        ball->speedX *= -1;
    }
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw line at half court
    DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
    DrawText(TextFormat("%i", playerLeftScore), SCREEN_WIDTH / 4 - 20, 20, 80, GREEN);
    DrawText(TextFormat("%i", playerRightScore), SCREEN_WIDTH / 4 * 3 - 20, 20, 80, RED);

    // Draw game objects
    ball->Draw();
    playerLeft->Draw();
    playerRight->Draw();

    EndDrawing();
}

void Game::End()
{
    CloseWindow();
}

void Game::increasePlayerLeftScore()
{
    playerLeftScore++;
}

void Game::increasePlayerRightScre()
{
    playerRightScore++;
}
