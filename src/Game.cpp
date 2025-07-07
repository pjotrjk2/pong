#include <raylib.h>
#include <raymath.h>
#include "Ball.h"
#include "Racket.h"
#include "CpuRacket.h"
#include "Game.h"
#include "Collision.h"
#include "Collider.h"
#include "CollisionResult.h"

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
    ball->ResetBall(false);

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

    CheckCollisions();
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

void Game::IncreasePlayerLeftScore()
{
    playerLeftScore++;
}

void Game::IncreasePlayerRightScre()
{
    playerRightScore++;
}

void Game::CheckCollisions()
{
    // check collision between ball and left racket
    CollisionResult collisionResult = Collision::TestCollision(ball->GetHitbox(), playerRight->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 ballSpeed = ball->GetSpeed();
        Vector2 reflected = Vector2Reflect(ballSpeed, collisionResult.normal);
        ball->SetSpeed(reflected);
    }

    // check collision between ball and left racket
    collisionResult = Collision::TestCollision(ball->GetHitbox(), playerLeft->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 ballSpeed = ball->GetSpeed();
        Vector2 reflected = Vector2Reflect(ballSpeed, collisionResult.normal);
        ball->SetSpeed(reflected);
    }
}
