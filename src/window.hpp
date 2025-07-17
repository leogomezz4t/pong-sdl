#pragma once

#include "SDL3/SDL.h"
#include "color.hpp"
#include <string>

/*
    Data structure that manages SDL operations with the window
*/
class GameWindow {
    SDL_Window* sdlWindow = NULL;
    SDL_Renderer* renderer = NULL;
    
    int windowWidth;
    int windowHeight;
    public:

    // Get/Set ---------------------------------

    /*
        Returns the SDL window context
    */
    SDL_Window* getSDLWindow();

    /*
        Returns the SDL Renderer context
    */
    SDL_Renderer* getSDLRenderer();

    // Get/Set ENDS ------------------------------

    /*
        Creates window and instantiates SDL contexts
    */
    bool initWindow(std::string name, int width, int height);

    /*
        Closes window and cleans up SDL contexts
    */
    void closeWindow();

    // METHODS ----------------

    /*
        A wrapper for SDL draw rect
    */
    void drawRect(SDL_FRect* rect, Color* c);

    /*
        Converts absolute mouse coordinates to window relative coordinates
        Params:
            float* mouseX: A pointer to an initialized float where the x coordinate will be written to
            float* mouseY: A pointer to an initialized float where the y coordinate will be written to
    */
    void getRelativeMousePosition(float* mouseX, float* mouseY);

    /*
        Clears the renderer before each frame
    */
    void resetRenderer();

    /*
        Writes renderer data to window
    */
    void presentRenderer();

    // METHODS ENDS -------------
    // GETTER
    int getWidth();

    int getHeight();
    // ENDS
};