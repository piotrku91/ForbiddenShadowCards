#include <iostream>
#include "CardsActionManager.hpp"
#include "simplerect.hpp"
#include "window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

CardsActionManager CAM;

int main() {
    // SDL Initialization
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    // Main window object creation
    RenderWindow mainWindow{"Battle Card Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1366, 768};

    std::vector<std::shared_ptr<simplerect>> battleTable;
    battleTable.push_back(std::make_shared<simplerect>(simplerect{mainWindow.getSizeX() - 400 - 20, 20, 400, 100, 0, 0, 50, 255, mainWindow.getRenderer()}));
    battleTable.push_back(std::make_shared<simplerect>(simplerect{20, mainWindow.getSizeY() - 150 - 20, 400, 100, 0, 0, 50, 255, mainWindow.getRenderer()}));
    battleTable.push_back(std::make_shared<simplerect>(spriterect{20, 0, 20, 20, mainWindow.getRenderer()}));

    //Event section
    bool close = false;
    while (!close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                // handling of close button
                close = true;
                break;
            };
        };

        //Render section
        SDL_RenderClear(mainWindow.getRenderer());
        SDL_RenderCopy(mainWindow.getRenderer(), mainWindow.getBackgroundTexture(), NULL, mainWindow.getBackgroundRect());

        // Render rect
        for (auto& rect : battleTable) {
            rect->renderAndDraw();
        };

        SDL_RenderPresent(mainWindow.getRenderer());
        SDL_Delay(1000 / 60);
    };

    // Clean section
    mainWindow.Destroy();
    SDL_Quit();

    return 0;
}