#pragma once
#include "SDL3/SDL.h"
#include <vector>

typedef SDL_Point TileData;

class Sprite {
    public:
    float deltaXRemaining = 0;
    float deltaYRemaining = 0;
    /*
        Collections of tiles that make up the sprite relative to a point defined by the sprite body
    */
    std::vector<TileData> refTiles;

    SDL_Point position;

    /*
        Adds a reference tile to the sprite
        Params:
            int x
            int y
    */
    void addTile(int x, int y);

    /*
        Removes a reference tile from the sprite
    */
    void removeTile(int x, int y);

    /*
        Move sprite and it's tiles
    */
    void move(int deltaX, int deltaY);

    /*
        Collision detection between two sprites
        Params:
            Sprite s: Other sprite to check against
        Returns:
            true if there is a collision
            false if there is no colission
    */
    bool isColliding(Sprite *s);

    /*
        Is called every frame
    */
   virtual void update();

   /*
        Is called on game start
   */
    virtual void init();
};