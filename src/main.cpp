#include <vector>
#include <raylib.h>

class Ball
{
    public:
        float x;
        float y;
        int speedX, speedY;
        int radius;

        Ball(float x, float y, int speedX = 0, int speedY = 0, int radius = 20)
        {
            this->x = x;
            this->y = y;
            this->speedX = speedX;
            this->speedY = speedY;
            this->radius = radius;
        }

        void Draw() 
        {
            DrawCircle(x, y, radius, WHITE);
        }

        void Update()
        {
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

int main() 
{    
    const int screenWidth = 1280;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Perica's pong game");
    SetTargetFPS(60);
    
    // Initialize objects
    Ball ball(screenWidth / 2, screenHeight / 2, 7, 7, 20);

    while (!WindowShouldClose())
    {        
        BeginDrawing();

        // UPDATE
        ball.Update();


        ClearBackground(BLACK);

        // Draw line at half court
        DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
        
        // Draw ball
        ball.Draw();

        // Draw rackets
        DrawRectangle(10, screenHeight / 2 - 60, 25, 120, WHITE);
        DrawRectangle(screenWidth - 35, screenHeight / 2 - 60, 25, 120, WHITE);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}
