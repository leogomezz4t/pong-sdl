#pragma once
#include "sprite.hpp"

class Paddle : public Sprite {
    SDL_Scancode UP_KEY;
    SDL_Scancode DOWN_KEY;
    public:
    void update() override;

    void init() override;

    void setUpKey(SDL_Scancode k);
    void setDownKey(SDL_Scancode k);
};