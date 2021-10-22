#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

class simplerect : public SDL_Rect {
private:
    Uint8 r_;
    Uint8 g_;
    Uint8 b_;
    Uint8 a_;

protected:
    SDL_Renderer* renderer_;

public:
    simplerect(int posX, int posY, int sizeW, int sizeH, Uint8 r, Uint8 g, Uint8 b, Uint8 a, SDL_Renderer* renderer)
        : SDL_Rect{posX,posY,sizeW,sizeH},r_{r}, g_{g}, b_{b}, a_{a}, renderer_(renderer) {
    };
    Uint8 getR() const { return r_; };
    Uint8 getG() const { return g_; };
    Uint8 getB() const { return b_; };
    Uint8 getA() const { return a_; };

    virtual void move(int X, int Y = 0) {
        x += X;
        y += Y;
    };
    virtual void renderAndDraw() {
        SDL_SetRenderDrawColor(renderer_, getR(), getG(), getB(), getA());
        SDL_RenderFillRect(renderer_, this);
    };
};

class spriterect : public simplerect {
private:
    SDL_Texture* texture_;

public:
    spriterect(int posX, int posY, int sizeW, int sizeH, SDL_Renderer* renderer)
        :simplerect(posX, posY, sizeW, sizeH, 0, 255, 0, 0, renderer) {

        SDL_Surface* surface = IMG_Load("textures/bg.jpeg");
        texture_ = SDL_CreateTextureFromSurface(renderer_, surface);
        SDL_FreeSurface(surface);
        
    };

    void renderAndDraw() override {
        SDL_QueryTexture(texture_, NULL, NULL, &w, &h);
        SDL_RenderCopy(renderer_, texture_, NULL, this);
    }
};