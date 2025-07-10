#include <iostream>

#include "window.hpp"
#include "game.hpp"

// Game definitions
#define GAME_TITLE "Pong"

int main(int argc, char** argv) {
    GameWindow window;
    if (!window.initWindow(GAME_TITLE, 800, 500)) {
        std::cout << "Could not open window" << std::endl;
        return -1;
    }

    TileMap map(0, 0, 50, 80);

    Game game(&window, &map);
    // Start loop
    game.gameLoop();


    window.closeWindow();
}