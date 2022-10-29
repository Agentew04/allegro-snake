#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "game.hpp"
#include "math.hpp"
#include "snake.hpp"

snk::Game::Game() : speed(kDefaultSpeed),
    boardWidth(kDefaultBoardSize.x),
    boardHeight(kDefaultBoardSize.y){
        snake = Snake();
        generateFood();
        gen = std::mt19937(rd());
        distributionX = std::uniform_int_distribution<int>(0, kDefaultBoardSize.x-1);
        distributionY = std::uniform_int_distribution<int>(0, kDefaultBoardSize.y-1);
    }

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
        x = distributionX(gen);
        y = distributionY(gen);
    }while(this->snake.contains(snk::Vec2I(x, y)));

    foodPos = {x, y};
}

void snk::Game::drawFood(const snk::VideoOptions &video){
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);

    int x = foodPos.x * video.getWidth() / boardWidth;
    int y = foodPos.y * video.getHeight() / boardHeight;
    int w = video.getWidth() / boardWidth;
    int h = video.getHeight() / boardHeight;

    al_draw_filled_rectangle(x, y, x+w, y+h, red);
}

void snk::Game::update(float delta){
    if(snake.body[0] == foodPos){
        //snake.grow();
        generateFood();
    }
}

void snk::Game::draw(const snk::VideoOptions &video){
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR lightGray = al_map_rgb(200, 200, 200);

    Vec2F p1 = video.calculateBoardPos();
    float borderSize = video.calculateBoardSize();
    float cellSize = video.calculateCellSize(Vec2I(boardWidth, boardHeight));
    Vec2F p2 = p1 + Vec2F(borderSize, borderSize);

    // draw cells
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
    snake.draw(video);
}