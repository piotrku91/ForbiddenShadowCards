#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "Object.hpp"
// TO DO: Move functions to cpp file
class Window final {
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    bool isDestroyed;

public:
    Window(const std::string& Caption, int sizeW, int sizeH)
        : isDestroyed(false) {
        window_ = SDL_CreateWindow(Caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeW, sizeH, SDL_WINDOW_SHOWN);
        if (window_ == NULL) {
            std::cout << "Window Error: " << SDL_GetError() << std::endl;
            throw;
        }
        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
    };

    ~Window() {
        if (!isDestroyed) {
            destroy();
        };
    }

    void render(int posX, int posY, SDL_Texture* texture) {
        SDL_Rect source_rect;
        source_rect.x = 0;
        source_rect.y = 0;
        SDL_QueryTexture(texture, NULL, NULL, &source_rect.w, &source_rect.h);
        SDL_Rect dest_rect{posX, posY, source_rect.w, source_rect.h};
        SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
    }

    void render(int posX, int posY, int sizeW, int sizeH, SDL_Texture* texture, int srcShiftX = 0, int srcShiftY = 0) {
        SDL_Rect source_rect{srcShiftX, srcShiftY, sizeW, sizeH};
        SDL_Rect dest_rect{posX, posY, source_rect.w, source_rect.h};
        SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
    }


    void render(Object& objectToRender) {
        SDL_Rect source_rect{objectToRender.getTextureOffsetX(), objectToRender.getTextureOffsetY(), objectToRender.getObjectRect().w, objectToRender.getObjectRect().h};
        objectToRender.getObjectRect().w = source_rect.w;
        objectToRender.getObjectRect().h = source_rect.h;
        SDL_RenderCopy(renderer_, objectToRender.getObjectTexture(), &source_rect, &objectToRender.getObjectRect());  
    }


    SDL_Texture* loadTextureFromFile(const std::string& Path) {
        SDL_Texture* texture{nullptr};
        texture = IMG_LoadTexture(renderer_, Path.c_str());
        if (!texture) {
            std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
        };
        return texture;
    }

    void destroy() {
        SDL_DestroyWindow(window_);
        isDestroyed = true;
    }

    void clear() {
        SDL_RenderClear(renderer_);
    }

    void draw() {
        SDL_RenderPresent(renderer_);
    }

    SDL_Renderer* getRenderer() { return renderer_; };
    SDL_Window* getWindow() const { return window_; };
};