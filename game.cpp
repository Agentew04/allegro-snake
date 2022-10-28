#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>

#include "game.hpp"
#include "math.hpp"
#include "snake.hpp"

snk::Game::Game() : speed(kDefaultSpeed),
    boardWidth(kDefaultBoardSize.x),
    boardHeight(kDefaultBoardSize.y),
    kDefaultBoardSize(snk::Vec2I(20,20)){
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

    int margin = 15;
    float maxBoardSize = std::min(video.getWidth() - margin, video.getHeight() - margin);
    //video.realBoardSize = maxBoardSize;
    float cellSize = maxBoardSize / std::max(boardWidth, boardHeight);
    float sideWidth = (video.getWidth() - maxBoardSize - 2 * margin) / 2;
    float upHeight = (video.getHeight() - maxBoardSize - 2 * margin) / 2;
    float borderX1 = sideWidth + margin;
    float borderY1 = upHeight + margin;
    float borderX2 = borderX1 + maxBoardSize;
    float borderY2 = borderY1 + maxBoardSize;

    // draw cells
    for(int i = 0; i < boardWidth; i++){
        for(int j = 0; j < boardHeight; j++){
            al_draw_rectangle(borderX1+i*cellSize+1,
                            borderY1+j*cellSize+1,
                            borderX1+(i+1)*cellSize+1,
                            borderY1+(j+1)*cellSize+1,
                            lightGray, 1);
        }
    }

    // draw border
    al_draw_rectangle(borderX1, borderY1, borderX2, borderY2, white, 3);


    drawFood(video);
    snake.draw(video);
}