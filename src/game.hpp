#pragma once

#include "window.hpp"
#include "tilemap.hpp"
#include "sprite.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include <vector>

class Game {
    // class references ---------------------

    //Reference to the GameWindow struct containing SDL window functionality
    GameWindow* window;
    
    // Reference to the main tilemap
    TileMap* mainTileMap; 

    // List of all sprite references
    std::vector<Sprite*> sprites;
    
    Paddle leftPaddle; 
    Paddle rightPaddle;
    Ball ball;

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

    void setup();

    // METHODS
    /*
        Paints sprite onto a tilemap
    */
    void paintSprite(Sprite* s);

};