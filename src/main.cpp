#include <vector>
#include <raylib.h>

class Ball {
public:

    float x;
    float y;
    int speedX, speedY;
    int radius;

    Ball(float x, float y, int speedX = 0, int speedY = 0, int radius = 20) {
        this->x = x;
        this->y = y;
        this->speedX = speedX;
        this->speedY = speedY;
        this->radius = radius;
    }

    void Draw() {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update() {
        x += speedX;
        y += speedY;

        if (y + radius >= GetScreenHeight() || y - radius <= 0) {
            speedY *= -1;
        }

        if (x + radius >= GetScreenWidth() || x - radius <= 0) {
            speedX *= -1;
        }
    }
};

class Racket {
public:
    float x, y;
    float width, height;
    int speed;

    Racket(float x, float y, float width, float height, int speed) {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->speed = speed;
    }

    void Draw() {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update() {
        if (IsKeyDown(KEY_UP)) {
            y -= speed;
        }

        if (IsKeyDown(KEY_DOWN)) {
            y += speed;
        }

        LimitMovement();
    }

protected:
    void LimitMovement() {
        if (y <= 0) {
            y = 0;
        }

        if (y + height >= GetScreenHeight()) {
            y = GetScreenHeight() - height;
        }
    }
};

class CpuRacket: public Racket {
public:

    CpuRacket(float x, float y, float width, float height, int speed) : Racket(x, y, width, height, speed) {
    }

    void Update(float ballY) {
        if (y + height / 2 > ballY) {
            y -= speed;
        }

        if (y + height / 2 < ballY) {
            y += speed;
        }

        LimitMovement();
    }
};

int main() {    
    const int screenWidth = 1280;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Perica's pong game");
    SetTargetFPS(60);
    
    // Initialize objects
    Ball ball(screenWidth / 2, screenHeight / 2, 7, 7, 20);

    int racketWidth = 25;
    int racketHeigh = 125;
    Racket player(
        10, 
        screenHeight / 2 - racketHeigh / 2, 
        racketWidth, 
        racketHeigh, 
        6
    );

    CpuRacket cpu(
        screenWidth - racketWidth - 10,
        screenHeight / 2 - racketHeigh / 2,
        racketWidth,
        racketHeigh,
        6
    );

    while (!WindowShouldClose())
    {        
        BeginDrawing();

        // UPDATE
        ball.Update();
        player.Update();
        cpu.Update(ball.y);


        ClearBackground(BLACK);

        // Draw line at half court
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        
        // Draw ball
        ball.Draw();

        // Draw rackets
        player.Draw();
        cpu.Draw();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
