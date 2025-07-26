#include "SDL3/SDL.h"
#include "color.hpp"
#include "tilemap.hpp"
#include <iostream>

TileMap::TileMap(float x, float y, int r, int c) {
    // assign instance values
    position.x = x;
    position.y = y;
    rows = r;
    columns = c;
    tileDataLength = rows * columns;
    // initialize tileData
    tileData = new Sint8[tileDataLength]; // 1d representation of a matrix
    // Populate data
    for (int i = 0; i < tileDataLength; i++)
    {
        tileData[i] = BLACK_REPR;
    }
};
TileMap::~TileMap() {
    delete tileData;
}

// METHODS -------------------

void TileMap::render(GameWindow *window)
{
    // Setup tile rect
    SDL_FRect tileRect;
    tileRect.w = TILE_SIZE;
    tileRect.h = TILE_SIZE;

    // Define iterative variables
    int row = 0;
    int column = 0;
    Color *currentColor;
    // iterate through tile data and render each one individually
    for (int i = 0; i < tileDataLength; i++)
    {
        // calculate positions
        tileRect.x = position.x + TILE_SIZE * column;
        tileRect.y = position.y + TILE_SIZE * row;
        // get color
        currentColor = (tileData[i]) ? &Color::WHITE : &Color::BLACK;
        // render to window
        window->drawRect(&tileRect, currentColor);

        // Update row and column values
        column++;
        if (column >= columns)
        {
            column = 0;
            row++;
        }
        if (row > rows)
        {
            std::cout << "column incrementer went above max columns" << std::endl;
        }
    }
};

SDL_Point TileMap::getClickedTile(float mouseX, float mouseY)
{
    int row = mouseY / TILE_SIZE;
    int column = mouseX / TILE_SIZE;

    return { column, row };
}

void TileMap::mapFill(uint8_t colorRepresentation) {
    for (int i = 0; i < tileDataLength; i++)
    {
        tileData[i] = colorRepresentation;
    }
}
// METHODS END -------------------------------

// GETTER/SETTER ----------------------
int TileMap::getHeight() {
    return rows;
}

int TileMap::getWidth() {
    return columns;
}

Sint8 TileMap::getTileValue(int row, int column) {
    if (row >= rows) {
        printf("Tried to get value of a row that exceeded bounds\n");
        return BLACK_REPR;
    }
    if (column >= columns) {
        printf("Tried to get value of a column that exceeded bounds\n");
        return BLACK_REPR;
    }
    return tileData[column + row * columns];
}

void TileMap::setTileValue(int row, int column, Sint8 value) {
    if (row < 0) return;
    if (column < 0) return;
    if (row >= rows) {
        //printf("Tried to set value of a row that exceeded bounds\n");
        return;
    }
    if (column >= columns) {
        //printf("Tried to set value of a column that exceeded bounds\n");
        return;
    }
    tileData[column + row * columns] = value;
}
// GETTER/SETTER END ------------------