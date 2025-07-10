#include "SDL3/SDL.h"
#include "window.hpp"
#include "tilemap.hpp"
#include "game.hpp"

Game::Game(GameWindow* wptr, TileMap* mtm) {
    window = wptr;
    mainTileMap = mtm;
}

void Game::gameLoop() {
    SDL_Event e;
    while (true) {
        while(SDL_PollEvent(&e)) {
            // Handle SDL quit
            if (e.type == SDL_EVENT_QUIT) return;

            // Handle mouse click
            if (e.type == SDL_EVENT_MOUSE_BUTTON_UP) {
                // Get mouse coordinates
                float mouseX, mouseY;
                window->getRelativeMousePosition(&mouseX, &mouseY);
                // Get corresponding tile
                SDL_Point tilePos = mainTileMap->getClickedTile(mouseX, mouseY);
                // Make tile white
                mainTileMap->setTileValue(tilePos.y, tilePos.x, WHITE_REPR);
            }
        }

        // Rendering
        window->resetRenderer();
        mainTileMap->render(window);
        // baka
        window->presentRenderer();
    }
}