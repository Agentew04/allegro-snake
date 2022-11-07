#include <algorithm>
#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "options.hpp"
#include "game.hpp"


// VIDEO OPTIONS

snk::VideoOptions::VideoOptions(ALLEGRO_DISPLAY *display){
    this->display = display;
    this->height = al_get_display_height(display);
    this->width = al_get_display_width(display);
    this->fullscreen = false;

    this->fontRegular = al_load_font("./assets/fonts/Rajdhani-Regular.ttf", 25, 0);
    std::cout << "regular: " << fontRegular << std::endl;
    this->fontLarge = al_load_font("./assets/fonts/Rajdhani-Regular.ttf", 30, 0);
    this->fontTitle = al_load_font("./assets/fonts/Rajdhani-Regular.ttf", 35, 0);
}

snk::VideoOptions::~VideoOptions(){
    al_destroy_font(fontRegular);
    al_destroy_font(fontLarge);
    al_destroy_font(fontTitle);
}


bool snk::VideoOptions::isFullscreen() const {
    return fullscreen;
}

void snk::VideoOptions::setFullscreen(bool fullscreen){
    this->fullscreen = fullscreen;
    al_toggle_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, fullscreen);
}

int snk::VideoOptions::getWidth() const {
    return width;
}
void snk::VideoOptions::setWidth(int width) {
    this->width = width;
}

int snk::VideoOptions::getHeight() const {
    return height;
}
void snk::VideoOptions::setHeight(int height) {
    this->height = height;
}

ALLEGRO_DISPLAY* snk::VideoOptions::getDisplay() const {
    return display;
}

ALLEGRO_FONT* snk::VideoOptions::getFont(snk::FontSize font) const {
    switch (font)
    {
    case FontSize::Regular:
        return fontRegular;
    case FontSize::Large:
        return fontLarge;
    case FontSize::Title:
        return fontTitle;
    default:
        return fontRegular;
    }
}

snk::Vec2F snk::VideoOptions::calculateBoardPos() const {
    float maxBoardSize = calculateBoardSize();
    float sideWidth = (width - maxBoardSize - 2 * margin) / 2;
    float upHeight = (height - maxBoardSize - 2 * margin) / 2;
    float borderX1 = sideWidth + margin;
    float borderY1 = upHeight + margin;
    return Vec2F(borderX1, borderY1);
}

float snk::VideoOptions::calculateBoardSize() const {
    float maxBoardSize = std::min(width - margin, height - margin);
    return maxBoardSize;
}

float snk::VideoOptions::calculateCellSize(snk::Vec2I boardCells) const {
    float maxBoardSize = calculateBoardSize();
    float cellSize = maxBoardSize / std::max(boardCells.x, boardCells.y);
    return cellSize;
}

snk::Vec2F snk::VideoOptions::calculateBarSize() const {
    float maxBoardSize = calculateBoardSize();
    float barWidth = ((width - maxBoardSize) - 2 * margin) / 2;
    return Vec2F(barWidth, height);
}