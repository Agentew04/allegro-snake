#include "snake.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

snk::Snake::Snake(snk::Vec2I boardSize) {
    body.push_back(startPos);
    this->boardSize = boardSize;
}

void snk::Snake::move(Vec2I direction, bool grow) {
    auto head = body[0];
    snk::Vec2I newHead = head + direction;

    // check if new head is out of bounds
    if(newHead.x < 0 || newHead.x >= boardSize.x || newHead.y < 0 || newHead.y >= boardSize.y){
        // loop around
        newHead.x = (newHead.x + 20 ) % 20; // adds 20 to
        newHead.y = (newHead.y + 20 ) % 20; //prevent negative numbers
    }
    body.insert(body.begin(), newHead);

    if(!grow)
        body.pop_back();
}

bool snk::Snake::selfCollision(){
    auto head = body[0];
    for(int i = 1; i < body.size(); i++){
        if(body[i] == head)
            return true;
    }
    return false;
}

bool snk::Snake::isSnake(snk::Vec2I point) {
    for (auto &i : body) {
        if (i == point) {
            return true;
        }
    }
    return false;
}

void snk::Snake::draw(const snk::VideoOptions &options, float cellSize) const{
    Vec2F origin = options.calculateBoardPos();
    ALLEGRO_COLOR green = al_map_rgb(0, 200, 0);
    for(auto &i : body){
        al_draw_filled_rectangle(origin.x + (i.x * cellSize)+1,
            origin.y + (i.y * cellSize)+1,
            origin.x + ((i.x + 1) * cellSize)+1,
            origin.y + ((i.y + 1) * cellSize)+1,
            green);
    }
}