#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "game.hpp"
#include "math.hpp"
#include "snake.hpp"

snk::Game::Game() : speed(kDefaultSpeed), 
    boardWidth(kDefaultBoardSize.x), 
    boardHeight(kDefaultBoardSize.y), 
    kDefaultBoardSize(snk::Vec2I(20,20)),
    distributionX(0, kDefaultBoardSize.x-1), 
    distributionY(0, kDefaultBoardSize.y-1){}

int snk::Game::getSpeed() const { 
    return speed; 
}

void snk::Game::setSpeed(int speed) { 
    this->speed = speed; 
}

void snk::Game::generateFood() {
    int x;
    int y;
    do{
        x = distributionX(generator);
        y = distributionY(generator);
    }while(this->snake.contains(snk::Vec2I(x, y)));

    foodPos = {x, y};
}

void snk::Game::update(){

}

void snk::Game::draw(const snk::VideoOptions &video){
    // draw board
    // find max board size
    int margin = 15;
    int maxBoardSize = std::min(video.getWidth() - margin, video.getHeight() - margin);
    int cellSize = maxBoardSize / std::max(boardWidth, boardHeight);

    for(int i = 0; i < boardWidth; i++){
        for(int j = 0; j < boardHeight; j++){
            // draw cell

        }
    }

    snake.draw(video);
}