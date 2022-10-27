#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <allegro5/allegro.h>

#include "math.hpp"

namespace snk{

struct VideoOptions{
private:
    Vec2I kDefaultSize = Vec2I(1280, 720);

    int width;
    int height;

    bool fullscreen;

    // allegro stuff
    ALLEGRO_DISPLAY *display;

public:
    VideoOptions(ALLEGRO_DISPLAY *display);

    bool isFullscreen() const;
    void setFullscreen(bool fullscreen);

    int getWidth() const;
    void setWidth(int width);

    int getHeight() const;
    void setHeight(int height);
};

} // namespace snk

#endif // OPTIONS_HPP