#include "SDL3/SDL.h"
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

void Sprite::move(int deltaX, int deltaY) {
    position.x += deltaX;
    position.y += deltaY;
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
