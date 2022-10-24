#include "options.hpp"

VideoOptions::VideoOptions() : width(kDefaultWidth), height(kDefaultHeight) {}

bool VideoOptions::isFullscreen() const { 
    return fullscreen; 
}

void VideoOptions::setFullscreen(bool fullscreen){
    this->fullscreen = fullscreen; 
}

int VideoOptions::getWidth() const {
    return width; 
}
void VideoOptions::setWidth(int width) { 
    this->width = width; 
}

int VideoOptions::getHeight() const { 
    return height; 
}
void VideoOptions::setHeight(int height) { 
    this->height = height; 
}
