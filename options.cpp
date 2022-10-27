#include <allegro5/allegro.h>

#include "options.hpp"


// VIDEO OPTIONS

snk::VideoOptions::VideoOptions(ALLEGRO_DISPLAY *display) : 
    display(display),
    width(kDefaultSize.x),
    height(kDefaultSize.y),
    fullscreen(false){}


bool snk::VideoOptions::isFullscreen() const { 
    return fullscreen; 
}

void snk::VideoOptions::setFullscreen(bool fullscreen){
    this->fullscreen = fullscreen; 
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
