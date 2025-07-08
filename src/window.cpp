#include "window.hpp"

bool GameWindow::initWindow(std::string name, int width, int height) {
    // Set instance values
    windowWidth = width;
    windowHeight = height;
    // Init SDL
    SDL_InitFlags sdlflags = SDL_INIT_VIDEO;
    if (!SDL_Init(sdlflags)) {
        SDL_Log("Error initializing SDL, %s\n", SDL_GetError());
        return false;
    }

    // Init window
    SDL_WindowFlags windowFlags = SDL_WINDOW_MAXIMIZED;
    if (!SDL_CreateWindowAndRenderer(name.c_str(), width, height, windowFlags, &sdlWindow, &renderer)) {
        SDL_Log("Error initializing window, %s\n", SDL_GetError());
        return false;
    }

    return true;
}

void GameWindow::closeWindow() {
    if (renderer != NULL) {
        SDL_DestroyRenderer(renderer);
        renderer = NULL;
    }
    if (sdlWindow != NULL) {
        SDL_DestroyWindow(sdlWindow);
        sdlWindow = NULL;
    }

    SDL_Quit();
}

// GETTER/SETTER -----------------------------------------


SDL_Window* GameWindow::getSDLWindow() {
    return sdlWindow;
}

SDL_Renderer* GameWindow::getSDLRenderer() {
    return renderer;
}

// GETTER/SETTER ENDS ---------------------------------------