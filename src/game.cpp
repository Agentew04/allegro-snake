#include <iostream>

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "game.hpp"
#include "math.hpp"
#include "snake.hpp"

snk::Game::Game(int boardWidth, int boardHeight) : speed(kDefaultSpeed),
        inverseSpeed(1.0f / speed), moveCounter(0.0), boardWidth(boardWidth),
        boardHeight(boardHeight), snake( snk::Vec2I(boardWidth, boardHeight)), gen(rd()) {
    distributionX = std::uniform_int_distribution<int>(0, boardWidth-1);
    distributionY = std::uniform_int_distribution<int>(0, boardHeight-1);
    generateFood();
}

int snk::Game::getSpeed() const {
    return speed;
}

void snk::Game::setSpeed(int speed) {
    this->speed = speed;
}

snk::Vec2I snk::Game::getBoardSize() const {
    return snk::Vec2I(boardWidth, boardHeight);
}

void snk::Game::generateFood() {
    int x;
    int y;
    do{
        x = distributionX(gen);
        y = distributionY(gen);
    }while(this->snake.isSnake(snk::Vec2I(x, y)));

    foodPos = {x, y};
}

void snk::Game::drawFood(const snk::VideoOptions &video) const{
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);

    Vec2F origin = video.calculateBoardPos();
    float cellSize = video.calculateCellSize(Vec2I(boardWidth, boardHeight));
    int x1 = origin.x + (foodPos.x * cellSize) + 1;
    int y1 = origin.y + (foodPos.y * cellSize) + 1;
    int x2 = origin.x + ((foodPos.x + 1) * cellSize) + 1;
    int y2 = origin.y + ((foodPos.y + 1) * cellSize) + 1;
    al_draw_filled_rectangle(x1, y1,
        x2, y2,
        red);
}

void snk::Game::update(double delta){
    if(gameOver){
        return;
    }
    if(moveCounter >= inverseSpeed){
        moveCounter = 0;
        bool grow = false;
        if(snake.body[0] == foodPos){
            grow = true;
            generateFood();
        }
        snake.move(snake.direction, grow);

        if(snake.selfCollision()){
            gameOver = true;
        }
    }else{
        moveCounter += delta;
    }
}

void snk::Game::setDirection(snk::Vec2I direction){
    if(snake.direction + direction != Vec2I::zero()){
        snake.direction = direction;
    }
}

void snk::Game::draw(const snk::VideoOptions &video) const {
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR lightGray = al_map_rgb(200, 200, 200);

    Vec2F p1 = video.calculateBoardPos();
    float borderSize = video.calculateBoardSize();
    float cellSize = video.calculateCellSize(Vec2I(boardWidth, boardHeight));
    Vec2F p2 = p1 + Vec2F(borderSize, borderSize);

    // draw cells
    std::cout << boardHeight << " " << boardWidth << std::endl;
    for(int i = 0; i < boardWidth; i++){
        for(int j = 0; j < boardHeight; j++){
            al_draw_rectangle(p1.x+i*cellSize+1,
                            p1.y+j*cellSize+1,
                            p1.x+(i+1)*cellSize+1,
                            p1.y+(j+1)*cellSize+1,
                            lightGray, 1);
        }
    }

    // draw border
    al_draw_rectangle(p1.x, p1.y, p2.x, p2.y, white, 3);


    drawFood(video);
    snake.draw(video, cellSize);


}