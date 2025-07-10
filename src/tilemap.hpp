#pragma once

#include "SDL3/SDL.h"
#include "color.hpp"
#include "window.hpp"

#define TILE_SIZE 10

// COLORS
#define BLACK_REPR 0
#define WHITE_REPR 1

class TileMap {
    // The tilemap color data
    Sint8* tileData;
    int tileDataLength;
    int rows;
    int columns;

    // position
    SDL_FPoint position;

    public:
    // Initializer ------------

    /*
        Initializes the TileMap
        Params:
            float x: The x coordinate of the tilemap's position,
            float y: The y coordinate of the tilemap's position,
            int r: The number of rows the tilemap will have,
            int c: The number of columns the tilemap will have
    */
    TileMap(float x, float y, int r, int c);
    // Destructor
    ~TileMap();
    // ----------------

    // METHODS ---------------------

    /*
        Renders the entire tilemap to the given SDL Window 
    */
    void render(GameWindow* window);

    /*
        Returns the row and column of the tile that was clicked based off the given coordinates
        Params:
            float mouseX: The x coordinate of the mouse relative to the window
            float mouseY: The y coordinate of the mouse relative to the window
    */
    SDL_Point getClickedTile(float mouseX, float mouseY);


    // METHODS END -------------------

    // GETTER/SETTER -------------------
    /*
        Returns the value of a tile
        Params:
            int row
            int column
    */
    Sint8 getTileValue(int row, int column);

    /*
        Sets the value of a tile
        Params:
            int row
            int column
            Sint8 value
    */
    void setTileValue(int row, int column, Sint8 value);
    // GETTER/SETTER ENDS -----------------------
};