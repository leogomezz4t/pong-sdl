#include "ball.hpp"
#include <cmath>
#include <stdio.h>

void Ball::reset() {
    position.x = 78;
    position.y = 48;
    // randomize angle
    angle = (float)rand() / RAND_MAX;
    angle *= 2 * M_PI;
}

void Ball::init() {
    for (int i = 0;i < diameter; i++)
    {
        for (int j = 0; j < diameter; j++)
        {
            addTile(i, j);
        }
    }

    reset();
};

void Ball::update() {
    if (leftPaddle == NULL || rightPaddle == NULL)
    {
        printf("what the baka\n");
        return;
    }

    // check collision with both
    if (isColliding(leftPaddle))
    {
        flipAngleX();
        deltaXRemaining++;
    }

    if (isColliding(rightPaddle))
    {
        flipAngleX();
        deltaXRemaining--;
    }
    // check collision with walls
    if (position.y <= 0) {
        flipAngleY();
        deltaYRemaining++;
    }
    if (position.y + diameter >= 100) {
        flipAngleY();
        deltaYRemaining--;
    }

    // movement
    deltaXRemaining += speed * cosf(angle);
    deltaYRemaining += speed * sinf(angle);
    Sprite::update();
};
void Ball::flipAngleX()
{
    angle = M_PI - angle;
}

void Ball::flipAngleY() {
    angle = 2*M_PI - angle;
}