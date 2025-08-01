#include "SDL3/SDL.h"
#include <iostream>
#include <vector>
#include "sprite.hpp"

void Sprite::addTile(int x, int y) {
    refTiles.push_back({x, y});
};

void Sprite::removeTile(int x, int y) {
    for (int i = 0; i < refTiles.size(); i++)
    {
        TileData t = refTiles[i];
        if (t.x == x && t.y == y)
        {
            refTiles.erase(refTiles.begin() + i);
        }
    }
};

void Sprite::clearTiles() {
    refTiles.clear();
}

void Sprite::move(int deltaX, int deltaY) {
    deltaXRemaining += deltaX;
    deltaYRemaining += deltaY;
}

bool Sprite::isColliding(Sprite *s) {
    for (TileData sTile : s->refTiles)
    {
        TileData sTransTile = {sTile.x + s->position.x, sTile.y + s->position.y};
        for (TileData myTile : refTiles)
        {
            TileData myTransTile = {myTile.x + position.x, myTile.y + position.y};

            // Collision detection
            if (sTransTile.x == myTransTile.x && sTransTile.y == myTransTile.y)
            {
                return true;
            }
        }
    }

    return false;
};

void Sprite::update() {
    // movement
    if (deltaXRemaining >= 1) {
        position.x++;
        deltaXRemaining--;
    }
    if (deltaXRemaining <= -1) {
        position.x--;
        deltaXRemaining++;
    }
    if (deltaYRemaining >= 1) {
        position.y++;
        deltaYRemaining--;
    }
    if(deltaYRemaining <= -1) {
        position.y--;
        deltaYRemaining++;
    }
};
void Sprite::init() {};