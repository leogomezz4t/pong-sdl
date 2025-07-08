#include "SDL3/SDL.h"
#include <iostream>

#include "window.hpp"

// Game definitions
#define GAME_TITLE "BitBoarder"

int main(int argc, char** argv) {
    GameWindow window;
    if (!window.initWindow(GAME_TITLE, 800, 500)) {
        std::cout << "Could not open window" << std::endl;
        return -1;
    }

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
    }

    window.closeWindow();
}