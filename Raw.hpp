#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

// TO DO: Move functions to cpp file
class RawObject {
protected:
    std::string objectName_;
    SDL_Rect objectRect_;
public:
    virtual SDL_Rect& getObjectRect() { return objectRect_; };

    
    RawObject(const std::string& objectName, int posX, int posY, int sizeW, int sizeH)
        : objectName_{objectName}, objectRect_{posX, posY, sizeW, sizeH}  {};
};

class SimpleRectObject: public RawObject
{
    public:
SimpleRectObject(const std::string& objectName, int posX, int posY, int sizeW, int sizeH)
        : RawObject{objectName, posX, posY, sizeW, sizeH} {};
};


class TexturedObject : public RawObject {
private:
    SDL_Texture* objectTexture_;
    int sourceTextOffsetX_;
    int sourceTextOffsetY_;

public:
    // c-tors
    TexturedObject(const std::string& objectName, int posX, int posY, int sizeW, int sizeH, SDL_Texture* texture, int sourceTextureOffsetX = 0, int sourceTextureOffsetY = 0)
        : RawObject{objectName, posX, posY, sizeW, sizeH}, objectTexture_{texture}, sourceTextOffsetX_{sourceTextureOffsetX}, sourceTextOffsetY_{sourceTextureOffsetY} {};

    //Setters
    void setTextureOffsetX(int sourceTextureOffsetX) {
        sourceTextOffsetX_ = sourceTextureOffsetX;
    }

    void setTextureOffsetY(int sourceTextureOffsetY) {
        sourceTextOffsetY_ = sourceTextureOffsetY;
    }

    //Getters
    SDL_Texture* getObjectTexture() { return objectTexture_; };
    int getTextureOffsetX() { return sourceTextOffsetX_; };
    int getTextureOffsetY() { return sourceTextOffsetY_; };

    
};