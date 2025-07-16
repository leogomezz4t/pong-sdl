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
    // setup left paddle
    leftPaddle.init();
    leftPaddle.position.x = 10;
    leftPaddle.position.y = 10;
    leftPaddle.setUpKey(SDL_SCANCODE_W);
    leftPaddle.setDownKey(SDL_SCANCODE_S);
    sprites.push_back((Sprite*) &leftPaddle);
    // setup right paddle
    rightPaddle.init();
    rightPaddle.position.x = 150;
    rightPaddle.position.y = 10;
    rightPaddle.setUpKey(SDL_SCANCODE_UP);
    rightPaddle.setDownKey(SDL_SCANCODE_DOWN);
    sprites.push_back((Sprite*) &rightPaddle);
    // setup ball
    ball.init();
    ball.leftPaddle = &leftPaddle;
    ball.rightPaddle = &rightPaddle;
    ball.position.x = 80;
    ball.position.y = 50;

    sprites.push_back((Sprite*) &ball);
}

void Game::paintSprite(Sprite *s) {
    for (TileData td : s->refTiles)
    {
        TileData transTd = {td.x + s->position.x, td.y + s->position.y};
        mainTileMap->setTileValue(transTd.y, transTd.x, WHITE_REPR);
    }
}