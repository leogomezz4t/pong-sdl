#include <iostream>

#include "window.hpp"
#include "game.hpp"

// Game definitions
#define GAME_TITLE "Pong"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 500

int main(int argc, char** argv) {
    GameWindow window;
    if (!window.initWindow(GAME_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT)) {
        std::cout << "Could not open window" << std::endl;
        return -1;
    }

    TileMap map(0, 0, 100, 160);

    Game game(&window, &map);
    // setup game
    game.setup();
    // Start loop
    game.gameLoop();


    window.closeWindow();
}