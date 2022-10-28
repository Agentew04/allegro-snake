#include <allegro5/allegro.h>

#include "options.hpp"


// VIDEO OPTIONS

snk::VideoOptions::VideoOptions(ALLEGRO_DISPLAY *display){
    this->display = display;
    this->height = al_get_display_height(display);
    this->width = al_get_display_width(display);
    this->fullscreen = false;
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