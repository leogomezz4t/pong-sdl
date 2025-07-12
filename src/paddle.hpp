#pragma once
#include "sprite.hpp"

class Paddle : public Sprite {
    public:
    void update() override {
        // get keyboard
        int kbLength;
        const bool* kbState = SDL_GetKeyboardState(nullptr);

        // Get up
        if (kbState[SDL_SCANCODE_UP]) {
            move(0, -1);
        }
        if (kbState[SDL_SCANCODE_DOWN]) {   
            move(0,1);
        }
    };

    void init() override {
        // Add tiles
        for (int i = 0; i < 5; i++) {
            addTile(0, i);
        }
    }
};