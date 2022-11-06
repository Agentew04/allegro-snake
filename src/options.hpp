#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "math.hpp"

namespace snk{

struct VideoOptions{
private:
    Vec2I kDefaultSize = Vec2I(1280, 720);

    int width;
    int height;
    bool fullscreen;

    int margin = 15;
    float boardSize;
    Vec2F boardPos;

    // allegro stuff
    ALLEGRO_DISPLAY *display;
    ALLEGRO_FONT *font;
public:
    VideoOptions(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font);

    bool isFullscreen() const;
    void setFullscreen(bool fullscreen);

    int getWidth() const;
    void setWidth(int width);

    int getHeight() const;
    void setHeight(int height);

    Vec2F calculateBoardPos() const;
    float calculateBoardSize() const;
    float calculateCellSize(Vec2I boardCells) const;
    Vec2F calculateBarSize() const;

    ALLEGRO_DISPLAY* getDisplay() const;
    ALLEGRO_FONT* getFont() const;
};

} // namespace snk

#endif // OPTIONS_HPP