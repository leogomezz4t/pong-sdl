#include "SDL3/SDL.h"
#include "window.hpp"
#include "tilemap.hpp"
#include "game.hpp"
#include "sprite.hpp"

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
        }

        // Rendering
        window->resetRenderer();

        // Reset tilemap
        mainTileMap->mapFill(BLACK_REPR);
        // Paint sprites
        for (Sprite* sprite : sprites) {
            sprite->update();
            paintSprite(sprite);
        }

        // Finish render
        mainTileMap->render(window);
        window->presentRenderer();
    }
}
void Game::setup() {
    mainPaddle.init();
    mainPaddle.position.x = 10;
    mainPaddle.position.y = 10;
    sprites.push_back((Sprite*) &mainPaddle);
}

void Game::paintSprite(Sprite *s) {
    for (TileData td : s->refTiles)
    {
        TileData transTd = {td.x + s->position.x, td.y + s->position.y};
        mainTileMap->setTileValue(transTd.y, transTd.x, WHITE_REPR);
    }
}