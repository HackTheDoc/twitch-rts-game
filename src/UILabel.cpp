#include "include/UI/UILabel.h"

#include "include/Window.h"

UILabel::UILabel() {
    rect = {0,0,0,0};
    texture = nullptr;  
}

UILabel::UILabel(const std::string& text, const std::string& font, const SDL_Color& color, const int mlength, const bool centered) {
    rect = {0,0,0,0};
    texture = nullptr; 
    
    setText(text, font, color, mlength, centered);
} 

UILabel::~UILabel() {}

void UILabel::draw() {
    Manager::Draw(texture, nullptr, &rect);
} 

void UILabel::destroy() {
    if (!texture) return;

    SDL_DestroyTexture(texture);
    texture = nullptr;
} 

void UILabel::setText(const std::string& text, const std::string& font, const SDL_Color& color, const int mlength, const bool centered) {
    destroy();

    int length = mlength;
    if (mlength == -1)
        length = Window::screen.w;
    
    texture = Manager::GenerateText(text, font, color, length, centered);

    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
} 
