#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class RenderWindow final {
private:
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Texture* background_;
    SDL_Rect backg_rect_;
    bool isDestroyed;

public:
    RenderWindow(const std::string& windowCaption, int posX, int posY, int sizeW, int sizeH, Uint32 flags = SDL_WINDOW_SHOWN)
        : backg_rect_{0, 0, sizeW, sizeH}, isDestroyed(false) {
        window_ = SDL_CreateWindow(windowCaption.c_str(), posX, posY, sizeW, sizeH, flags);
        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);

        SDL_Surface* surface =IMG_Load("textures/bg.jpeg");
        background_ = SDL_CreateTextureFromSurface(renderer_, surface);
        SDL_FreeSurface(surface);
        SDL_QueryTexture(background_, NULL, NULL, &backg_rect_.w, &backg_rect_.h);
    };

    ~RenderWindow() {
        if (!isDestroyed) {
            Destroy();
        };
    }

    void Destroy() {
        SDL_DestroyTexture(background_);
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
        isDestroyed = true;
    }

    void getSize(int* tmpX, int* tmpY) {
        SDL_GetWindowSize(window_, tmpX, tmpY);
    }

    int getSizeX() {
        int tmpX, tmpY;
        SDL_GetWindowSize(window_, &tmpX, &tmpY);
        return tmpX;
    }

    int getSizeY() {
        int tmpX, tmpY;
        SDL_GetWindowSize(window_, &tmpX, &tmpY);
        return tmpY;
    }

    SDL_Renderer* getRenderer() { return renderer_; };
    SDL_Window* getWindow() const { return window_; };
    SDL_Texture* getBackgroundTexture() const { return background_; };
    SDL_Rect* getBackgroundRect() { return &backg_rect_; };
};