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
    int boardWidth;
    int boardHeight;
    Snake snake;

    //food    
    snk::Vec2I foodPos;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distributionX;
    std::uniform_int_distribution<int> distributionY;


public:
    Game();

    int getSpeed() const;
    void setSpeed(int speed);

    void generateFood();

    void update();

    void draw(const snk::VideoOptions &video);
};

} // namespace snk

#endif // GAME_HPP