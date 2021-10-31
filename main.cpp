#include <memory>
#include <vector>
#include <iostream>
#include "CardsActionManager.hpp"
#include "window.hpp"
#include "TextureManager.hpp"
#include "Raw.hpp"




CardsActionManager CAM;

int main() {
std::vector<std::shared_ptr<RawObject>> Objects;
// Load main window
Window mainWindow{"New game", 800, 600};

// Init texture manager and load textures
TextureManager TextureMgr;
TextureMgr.addTexture("first",mainWindow.loadTextureFromFile("textures/jeden.jpg"));

// Create textured objects
Objects.push_back(std::make_shared<TexturedObject>(TexturedObject{"texturowy 1",32,32,128,128,TextureMgr["first"]}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"texturowy 2",200,200,128,128}));


// Render section
mainWindow.clear();

for (auto& ob : Objects)
{mainWindow.render(ob);};
mainWindow.draw();

SDL_Delay(3000);

// Cleaning
mainWindow.destroy();
    return 0;
}