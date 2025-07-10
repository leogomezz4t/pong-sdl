#pragma once

#include "window.hpp"

class Game {
    // class references ---------------------

    //Reference to the GameWindow struct containing SDL window functionality
    GameWindow* window;

    public:

    /*
        Game initializer
        Args:
            wptr: GameWindow* | Reference to the GameWindow struct containing SDL window functionality
    */
    Game(GameWindow* wptr);

    /*
        Starts SDL and game event loop
    */
    void gameLoop();
};