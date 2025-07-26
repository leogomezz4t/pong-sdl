#pragma once
#include "sprite.hpp"
#define M_PI           3.14159265358979323846  /* pi */

class Ball : public Sprite {
    public:
    int diameter = 2;
    Sprite* leftPaddle = NULL;
    Sprite* rightPaddle = NULL;    

    // movement
    float speed = 0.2;
    float angle;

    void reset();
    
    void init();

    void update();

    void flipAngleX();

    void flipAngleY();
};
