#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_ttf.h>
#include "Color.hpp"

// TO DO: Move functions to cpp file
///////////////////////////////////////////////////////////////////////////////////////////////////////
class RawObject {
protected:
    std::string objectName_;
    SDL_Rect objectRect_;

public:
    virtual SDL_Rect& getObjectRect() { return objectRect_; };
    virtual std::string getObjectName() { return objectName_; };

    RawObject(const std::string& objectName, int posX, int posY, int sizeW, int sizeH)
        : objectName_{objectName}, objectRect_{posX, posY, sizeW, sizeH} {};
};
///////////////////////////////////////////////////////////////////////////////////////////////////////
class SimpleRectObject : public RawObject {
protected:
    Color objectColor_;

public:
    const Color& getColor() { return objectColor_; };

    SimpleRectObject(const std::string& objectName, int posX, int posY, int sizeW, int sizeH, Color&& objectColor)
        : RawObject{objectName, posX, posY, sizeW, sizeH}, objectColor_{objectColor} {};
};

class TextObject : public RawObject {
protected:
    Color objectColor_;
    SDL_Surface* message_;

public:
    const Color& getColor() { return objectColor_; };
     SDL_Surface* getSurface() { return message_; };

    void changeText(const std::string text, TTF_Font* font, Color&& objectColor) {
        free();
         message_ = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{objectColor.getR(), objectColor.getG(), objectColor.getB(), objectColor.getA()});
    }

    TextObject(const std::string& objectName, int posX, int posY, int sizeW, int sizeH, const std::string text, TTF_Font* font, Color&& objectColor)
        : RawObject{objectName, posX, posY, sizeW, sizeH}, objectColor_{objectColor} {
        message_ = TTF_RenderText_Blended(font, text.c_str(), SDL_Color{objectColor_.getR(), objectColor_.getG(), objectColor_.getB(), objectColor_.getA()});
    };

    void free() {SDL_FreeSurface(message_);};
    ~TextObject() { free(); };
};

///////////////////////////////////////////////////////////////////////////////////////////////////////
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
///////////////////////////////////////////////////////////////////////////////////////////////////////