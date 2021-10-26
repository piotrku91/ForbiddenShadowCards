#include <iostream>
#include "CardsActionManager.hpp"
#include "window.hpp"
#include "TextureManager.hpp"


CardsActionManager CAM;



int main() {
Window mainWindow{"New game", 800, 600};
TextureManager TextureMgr;
mainWindow.clear();

TextureMgr.addTexture("first",mainWindow.loadTextureFromFile("textures/jeden.jpg"));
mainWindow.render(0,0,128,128,TextureMgr["first"],0,0);

mainWindow.draw();
SDL_Delay(3000);
mainWindow.destroy();
    return 0;
}