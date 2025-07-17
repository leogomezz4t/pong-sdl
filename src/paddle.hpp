#pragma once
#include "sprite.hpp"

class Paddle : public Sprite {
    SDL_Scancode UP_KEY;
    SDL_Scancode DOWN_KEY;
    public:
    int length = 10;
    float speed = 0.5f;

    void update();

    void init();

    void setUpKey(SDL_Scancode k);
    void setDownKey(SDL_Scancode k);
};