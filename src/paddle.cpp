#include "paddle.hpp"

void Paddle::update() {
    // get keyboard
    int kbLength;
    const bool *kbState = SDL_GetKeyboardState(nullptr);

    // Get up
    if (kbState[UP_KEY])
    {
        deltaYRemaining -= speed;
    }
    if (kbState[DOWN_KEY])
    {
        deltaYRemaining += speed;
    }

    Sprite::update();
};

void Paddle::init() {
    // Add tiles
    for (int i = 0; i < length; i++)
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