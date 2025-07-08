#include "SDL3/SDL.h"
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
};