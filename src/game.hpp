#pragma once

#include "window.hpp"
#include "tilemap.hpp"

class Game {
    // class references ---------------------

    //Reference to the GameWindow struct containing SDL window functionality
    GameWindow* window;
    
    // Reference to the main tilemap
    TileMap* mainTileMap; 

    public:

    /*
        Game initializer
        Args:
            wptr: GameWindow* | Reference to the GameWindow struct containing SDL window functionality,
            mtm: TileMap* | Reference to the main tile map of the game
    */
    Game(GameWindow* wptr, TileMap* mtm);

    /*
        Starts SDL and game event loop
    */
    void gameLoop();
};