#include <iostream>
#include "CardsActionManager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

CardsActionManager CAM;

int main() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    SDL_Window* window = SDL_CreateWindow("FGame", 0, 0, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);



    SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);

    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_Quit();

    return 0;
}