#include "raylib.h"
#include "raymath.h"
#include "GameObjects/Ball.h"
#include "GameObjects/Racket.h"
#include "GameObjects/CpuRacket.h"
#include "Game.h"
#include "GameMechanics/Collision.h"
#include "GameMechanics/Collider.h"
#include "GameMechanics/CollisionResult.h"

Game::Game(bool singlePlayer)
{
    frameTop = new Frame(0, 5, SCREEN_WIDTH, 15);
    frameBottom = new Frame(0, SCREEN_HEIGHT - 20, SCREEN_WIDTH, 15);

    goalLeft = new Goalpost(0, 0, 10, SCREEN_HEIGHT);
    goalRight = new Goalpost(SCREEN_WIDTH - 10, 0, 10, SCREEN_HEIGHT);

    playerLeft = new Racket(10,
                            SCREEN_HEIGHT / 2 - RACKET_HEIGHT / 2,
                            RACKET_WIDTH,
                            RACKET_HEIGHT,
                            0);

    if (!singlePlayer)
    {

        playerRight = new Racket(SCREEN_WIDTH - RACKET_WIDTH - 10,
                                 SCREEN_HEIGHT / 2 - RACKET_HEIGHT / 2,
                                 RACKET_WIDTH,
                                 RACKET_HEIGHT,
                                 0);
    }
    else
    {

        playerRight = new CpuRacket(SCREEN_WIDTH - RACKET_WIDTH - 10,
                                    SCREEN_HEIGHT / 2 - RACKET_HEIGHT / 2,
                                    RACKET_WIDTH,
                                    RACKET_HEIGHT,
                                    0,
                                    RACKET_SPEED);
    }

    ball = new Ball(this, Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f});
    ball->ResetBall(false);

    playerLeft->ShowBall(ball);
    playerRight->ShowBall(ball);
}

void Game::StartGame()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Perica's pong game");
    SetTargetFPS(FPS);
}

void Game::Update()
{
    CheckCollisions();

    DispatchEvents();

    ball->Update();
    playerLeft->Update();
    playerRight->Update();
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
    frameBottom->Draw();
    frameTop->Draw();

    goalLeft->Draw();
    goalRight->Draw();

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

void Game::IncreasePlayerRightScore()
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

    // check ball and edges collision
    collisionResult = Collision::TestCollision(ball->GetHitbox(), frameBottom->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 ballSpeed = ball->GetSpeed();
        Vector2 reflected = Vector2Reflect(ballSpeed, collisionResult.normal);
        ball->SetSpeed(reflected);
    }

    collisionResult = Collision::TestCollision(ball->GetHitbox(), frameTop->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 ballSpeed = ball->GetSpeed();
        Vector2 reflected = Vector2Reflect(ballSpeed, collisionResult.normal);
        ball->SetSpeed(reflected);
    }

    // check rackets and edges collision
    collisionResult = Collision::TestCollision(playerLeft->GetHitbox(), frameBottom->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 reflected = Vector2Reflect(playerLeft->GetSpeed(), collisionResult.normal);
        playerLeft->SetSpeed(reflected);
    }

    collisionResult = Collision::TestCollision(playerLeft->GetHitbox(), frameTop->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 reflected = Vector2Reflect(playerLeft->GetSpeed(), collisionResult.normal);
        playerLeft->SetSpeed(reflected);
    }

    collisionResult = Collision::TestCollision(playerRight->GetHitbox(), frameBottom->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 reflected = Vector2Reflect(playerRight->GetSpeed(), collisionResult.normal);
        playerRight->SetSpeed(reflected);
    }

    collisionResult = Collision::TestCollision(playerRight->GetHitbox(), frameTop->GetHitbox());
    if (collisionResult.collided)
    {
        Vector2 reflected = Vector2Reflect(playerRight->GetSpeed(), collisionResult.normal);
        playerRight->SetSpeed(reflected);
    }

    // check ball and goalpost collisions
    collisionResult = Collision::TestCollision(ball->GetHitbox(), goalLeft->GetHitbox());
    if (collisionResult.collided)
    {
        this->IncreasePlayerRightScore();
        ball->ResetBall(false);
    }

    collisionResult = Collision::TestCollision(ball->GetHitbox(), goalRight->GetHitbox());
    if (collisionResult.collided)
    {
        this->IncreasePlayerLeftScore();
        ball->ResetBall(true);
    }

}

void Game::DispatchEvents()
{
    if (IsKeyPressed(KEY_UP))
    {
        playerLeft->SetSpeed(Vector2{0, -RACKET_SPEED});
    }
    
    if (IsKeyReleased(KEY_UP))
    {

        playerLeft->SetSpeed(Vector2{0, 0});
    }

    if (IsKeyPressed(KEY_DOWN))
    {
        playerLeft->SetSpeed(Vector2{0, RACKET_SPEED});
    }

    if (IsKeyReleased(KEY_DOWN))
    {
        playerLeft->SetSpeed(Vector2{0, 0});
    }
}
