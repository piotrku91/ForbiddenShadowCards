
#include "window.hpp"

Window::Window(const std::string& Caption, int sizeW, int sizeH)
    : isDestroyed(false) {
    window_ = SDL_CreateWindow(Caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, sizeW, sizeH, SDL_WINDOW_SHOWN);
    if (window_ == NULL) {
        std::cout << "Window Error: " << SDL_GetError() << std::endl;
        throw;
    }
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
Window::~Window() {
    if (!isDestroyed) {
        destroy();
    };
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Window::render(int posX, int posY, SDL_Texture* texture) {
    SDL_Rect source_rect;
    source_rect.x = 0;
    source_rect.y = 0;
    SDL_QueryTexture(texture, NULL, NULL, &source_rect.w, &source_rect.h);
    SDL_Rect dest_rect{posX, posY, source_rect.w, source_rect.h};
    SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Window::render(int posX, int posY, int sizeW, int sizeH, SDL_Texture* texture, int srcShiftX, int srcShiftY) {
    SDL_Rect source_rect{srcShiftX, srcShiftY, sizeW, sizeH};
    SDL_Rect dest_rect{posX, posY, source_rect.w, source_rect.h};
    SDL_RenderCopy(renderer_, texture, &source_rect, &dest_rect);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Window::render(std::shared_ptr<RawObject>& objectToRender) {
    // Textured objects
    if (auto ObjectTest = pq::isTargetClassObject<RawObject, TexturedObject>(objectToRender)) {
        SDL_Rect source_rect{ObjectTest->getTextureOffsetX(), ObjectTest->getTextureOffsetY(), ObjectTest->getObjectRect().w, ObjectTest->getObjectRect().h};
        ObjectTest->getObjectRect().w = source_rect.w;
        ObjectTest->getObjectRect().h = source_rect.h;
        SDL_RenderCopy(renderer_, ObjectTest->getObjectTexture(), &source_rect, &ObjectTest->getObjectRect());
    };

    // Simple rectangle objects
    if (auto ObjectTest = pq::isTargetClassObject<RawObject, SimpleRectObject>(objectToRender)) {
        SDL_SetRenderDrawColor(renderer_, ObjectTest->getColor().getR(), ObjectTest->getColor().getG(), ObjectTest->getColor().getB(), ObjectTest->getColor().getA());
        SDL_RenderFillRect(renderer_, &ObjectTest->getObjectRect());
    }

    // Simple rectangle objects
    if (auto ObjectTest = pq::isTargetClassObject<RawObject, TextObject>(objectToRender)) {
        SDL_Rect source_rect{0, 0, ObjectTest->getObjectRect().w, ObjectTest->getObjectRect().h};
        SDL_Texture* message_t = SDL_CreateTextureFromSurface(renderer_, ObjectTest->getSurface());
        ObjectTest->getObjectRect().w = source_rect.w;
        ObjectTest->getObjectRect().h = source_rect.h;
        SDL_RenderCopy(renderer_, message_t, &source_rect, &ObjectTest->getObjectRect());
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Texture* Window::loadTextureFromFile(const std::string& Path) {
    SDL_Texture* texture{nullptr};
    texture = IMG_LoadTexture(renderer_, Path.c_str());
    if (!texture) {
        std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    };
    return texture;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Window::destroy() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    isDestroyed = true;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Window::clear() {
    SDL_RenderClear(renderer_);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
void Window::draw() {
    SDL_RenderPresent(renderer_);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Renderer* Window::getRenderer() {
    return renderer_;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
SDL_Window* Window::getWindow() const {
    return window_;
}
