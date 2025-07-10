#include "window.hpp"

#define DEBUG false

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

// METHODS ------------------------
void GameWindow::drawRect(SDL_FRect *rect, Color *c) {
    SDL_SetRenderDrawColor(renderer, c->r, c->g, c->b, c->a);
    SDL_RenderFillRect(renderer, rect);
    if (DEBUG) {
        Color* g = &Color::GRAY;
        SDL_SetRenderDrawColor(renderer, g->r, g->g, g->b, g->a);
        SDL_RenderRect(renderer, rect);
    }
};

void GameWindow::getRelativeMousePosition(float* mouseX, float* mouseY) {
    // Getting mouse position
    float mx, my;
    SDL_MouseButtonFlags state = SDL_GetGlobalMouseState(&mx, &my);
    // Getting window position 
    int windowX, windowY;
    SDL_GetWindowPosition(getSDLWindow(), &windowX, &windowY);
    // Calculate and return relative value
    *mouseX = mx - windowX;
    *mouseY = my - windowY;
}

void GameWindow::resetRenderer() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

void GameWindow::presentRenderer() {
    SDL_RenderPresent(renderer);
}
// METHODS ENDS -----------------------

// GETTER/SETTER -----------------------------------------


SDL_Window* GameWindow::getSDLWindow() {
    return sdlWindow;
}

SDL_Renderer* GameWindow::getSDLRenderer() {
    return renderer;
}

// GETTER/SETTER ENDS ---------------------------------------