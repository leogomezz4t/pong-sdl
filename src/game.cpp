#include "SDL3/SDL.h"
#include "window.hpp"
#include "game.hpp"

Game::Game(GameWindow* wptr) {
    window = wptr;
}

void Game::gameLoop() {
    SDL_Event e;
    while (true) {
        while(SDL_PollEvent(&e)) {
            // Handle SDL quit
            if (e.type == SDL_EVENT_QUIT) return;


        }
    }
}