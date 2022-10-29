#ifndef GAME_HPP
#define GAME_HPP

#include "snake.hpp"
#include <random>
#include "math.hpp"

namespace snk{

struct Game{
private:
    static const int kDefaultSpeed = 10;
    const snk::Vec2I kDefaultBoardSize = snk::Vec2I(20,20);

    int speed;
    Snake snake;

    //food
    snk::Vec2I foodPos;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> distributionX;
    std::uniform_int_distribution<int> distributionY;

    void drawFood(const snk::VideoOptions &video);
public:
    int boardWidth;
    int boardHeight;
    Game();

    int getSpeed() const;
    void setSpeed(int speed);

    void generateFood();

    void update(float delta);

    void draw(const snk::VideoOptions &video);
};

} // namespace snk

#endif // GAME_HPP