#ifndef RACKET_H
#define RACKET_H

class Ball;

class Racket
{
public:
    float x, y;
    float width, height;
    int speed;
    Ball *ball;

    Racket(float x, float y, float width, float height, int speed);
    void Draw();
    virtual void Update();
    void ShowBall(Ball *ball);

protected:
    void LimitMovement();
};

#endif
