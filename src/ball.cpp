#include "ball.hpp"
#include <cmath>
#include <stdio.h>


void Ball::init() {
    int diameter = 2;
    for (int i = 0;i < diameter; i++)
    {
        for (int j = 0; j < diameter; j++)
        {
            addTile(i, j);
        }
    }

    // randomize angle
    angle = (float)rand() / RAND_MAX;
    angle *= 2 * M_PI;
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
    if (position.y + 2 >= 100) {
        flipAngleY();
        deltaYRemaining--;
    }
    /*
    if (position.x + 2 >= 160) {
        flipAngleX();
    }
    if (position.x <= 0) {
        flipAngleX();
    }
        */

    // movement
    deltaXRemaining += speed * cosf(angle);
    deltaYRemaining += speed * sinf(angle);
    printf("%F %d %d\n", angle, position.x, position.y);

    if (deltaXRemaining >= 1) {
        position.x++;
        deltaXRemaining--;
    }
    if (deltaXRemaining <= -1) {
        position.x--;
        deltaXRemaining++;
    }
    if (deltaYRemaining >= 1) {
        position.y++;
        deltaYRemaining--;
    }
    if(deltaYRemaining <= -1) {
        position.y--;
        deltaYRemaining++;
    }
};
void Ball::flipAngleX()
{
    angle = M_PI - angle;
}

void Ball::flipAngleY() {
    angle = 2*M_PI - angle;
}