#include <memory>
#include <vector>
#include <iostream>
#include "CardsActionManager.hpp"
#include "window.hpp"
#include "TextureManager.hpp"
#include "Raw.hpp"
#include "Color.hpp"

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
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"Player 2 area", 350, 20, 430, 150, Color{0,0,100,100}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"Player 1 area", 20, 430, 430, 150, Color{0,0,100,100}}));
// Render section
mainWindow.clear();

pq::timeTest TT;
TT.start();
for (auto& ob : Objects)
{mainWindow.render(ob);};
mainWindow.draw();
std::cout << TT.stop() <<"\n";

SDL_Delay(3000);

// Cleaning
mainWindow.destroy();
    return 0;
}