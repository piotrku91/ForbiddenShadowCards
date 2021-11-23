#include <memory>
#include <vector>
#include <iostream>

// Graphics layer libs
#include "window.hpp"
#include "TextureManager.hpp"
#include "Raw.hpp"
#include "Color.hpp"
#include "CardsActionManager.hpp"

CardsActionManager CAM;
constexpr auto MAX_X=800;
constexpr auto MAX_Y=600; 
constexpr auto PLAYERS_AREA_W=500; 
constexpr auto PLAYERS_AREA_H=150; 
constexpr auto BIGCARD_AREA_W=220; 
constexpr auto BIGCARD_AREA_H=270; 


int main() {
std::vector<std::shared_ptr<RawObject>> Objects;
// Load main window
Window mainWindow{"New game", MAX_X, MAX_Y};

 //Init texture manager and load textures
TextureManager TextureMgr;
TextureMgr.addTexture("first",mainWindow.loadTextureFromFile("textures/jeden.jpg"));

 //Create textured objects
//Objects.push_back(std::make_shared<TexturedObject>(TexturedObject{"texturowy 1",32,32,128,128,TextureMgr["first"]}));//

// Players area
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"Player 2 area", MAX_X - PLAYERS_AREA_W, 0, PLAYERS_AREA_W, PLAYERS_AREA_H, Color{0,0,100,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"Player 1 area", 0, MAX_Y - PLAYERS_AREA_H, PLAYERS_AREA_W, PLAYERS_AREA_H, Color{0,0,100,255}}));
// Big card preview area
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"Card 2 ar", 0, 0, BIGCARD_AREA_W, BIGCARD_AREA_H, Color{255,0,100,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"Card 1 ar", MAX_X-BIGCARD_AREA_W, MAX_Y - BIGCARD_AREA_H, BIGCARD_AREA_W, BIGCARD_AREA_H, Color{255,0,100,255}}));
// Stats area
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"stats 2 ar", MAX_X - 100, PLAYERS_AREA_H + 20, 100, 100, Color{255,255,100,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"stats 1 ar", 0, MAX_Y - PLAYERS_AREA_H - 120, 100, 100, Color{255,255,100,255}}));

// Battle characters area
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X/2, (MAX_Y/2 -120), 70, 100, Color{255,255,255,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X/2 - 80, MAX_Y/2 -120, 70, 100, Color{255,255,255,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X/2 + 80, MAX_Y/2 -120, 70, 100, Color{255,255,255,255}}));


Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X/2, MAX_Y/2, 70, 100, Color{255,255,255,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X/2 - 80, MAX_Y/2, 70, 100, Color{255,255,255,255}}));
Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X/2 + 80, MAX_Y/2, 70, 100, Color{255,255,255,255}}));
//Objects.push_back(std::make_shared<SimpleRectObject>(SimpleRectObject{"battle 1 ar", MAX_X -100, MAX_Y- BIGCARD_AREA_H - 120, 100, 100, Color{255,255,100,255}}));

// Render section
mainWindow.clear();

pq::timeTest TT;
TT.start();
for (auto& ob : Objects)
{mainWindow.render(ob);};
mainWindow.draw();
std::cout << TT.stop() <<"\n";

SDL_Delay(9000);

// Cleaning
mainWindow.destroy();
    return 0;
}