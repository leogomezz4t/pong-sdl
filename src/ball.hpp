#pragma once
#include "sprite.hpp"
#define M_PI           3.14159265358979323846  /* pi */

class Ball : public Sprite {
    public:
    Sprite* leftPaddle = NULL;
    Sprite* rightPaddle = NULL;    

    // movement
    float speed = 0.1;
    float angle;
    float deltaXRemaining = 0;
    float deltaYRemaining = 0;
    
    void init() override;

    void update() override;

    void flipAngleX();

    void flipAngleY();
};
