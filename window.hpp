#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Raw.hpp"
#include "piotrq.h"

class Window final {
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    bool isDestroyed;

public:

    Window(const std::string& Caption, int sizeW, int sizeH);

    ~Window();

    void render(int posX, int posY, SDL_Texture* texture);

    void render(int posX, int posY, int sizeW, int sizeH, SDL_Texture* texture, int srcShiftX = 0, int srcShiftY = 0);

    void render(std::shared_ptr<RawObject>& objectToRender);

    SDL_Texture* loadTextureFromFile(const std::string& Path);

    void destroy() ;

    void clear() ;

    void draw() ;

    SDL_Renderer* getRenderer();
    SDL_Window* getWindow() const;
};