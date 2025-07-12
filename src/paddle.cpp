#include "paddle.hpp"

void Paddle::update() {
    // get keyboard
    int kbLength;
    const bool *kbState = SDL_GetKeyboardState(nullptr);

    // Get up
    if (kbState[UP_KEY])
    {
        move(0, -1);
    }
    if (kbState[DOWN_KEY])
    {
        move(0, 1);
    }
};

void Paddle::init() {
    // Add tiles
    for (int i = 0; i < 6; i++)
    {
        addTile(0, i);
    }
}

void Paddle::setUpKey(SDL_Scancode k)
{
    UP_KEY = k;
}

void Paddle::setDownKey(SDL_Scancode k)
{
    DOWN_KEY = k;
}