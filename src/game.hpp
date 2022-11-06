#ifndef GAME_HPP
#define GAME_HPP

#include "snake.hpp"
#include <random>
#include "math.hpp"

namespace snk{

struct Game{
private:
    const int kDefaultSpeed = 10;

    int speed;
    float inverseSpeed;
    double moveCounter;
    bool gameOver = false;
    int boardWidth;
    int boardHeight;

    Snake snake;

    //food
    snk::Vec2I foodPos;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> distributionX;
    std::uniform_int_distribution<int> distributionY;

    void drawFood(const snk::VideoOptions &video) const;

    void drawLeftMenu(const snk::VideoOptions &video) const;
public:
    Game(int boardWidth, int boardHeight);

    int getSpeed() const;
    void setSpeed(int speed);

    snk::Vec2I getBoardSize() const;

    void generateFood();

    void setDirection(snk::Vec2I direction);

    void update(double delta);

    void draw(const snk::VideoOptions &video) const;
};

} // namespace snk

#endif // GAME_HPP