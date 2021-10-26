#pragma once

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

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

    void destroy() {
        SDL_DestroyWindow(window_);
        isDestroyed = true;
    }

    void clear() {
        SDL_RenderClear(renderer_);
    }

    SDL_Renderer* getRenderer() { return renderer_; };
    SDL_Window* getWindow() const { return window_; };
};