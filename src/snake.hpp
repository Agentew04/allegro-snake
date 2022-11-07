#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include <iostream>

#include "options.hpp"
#include "math.hpp"

namespace snk{

struct Snake{
public:
    Vec2I startPos {10,10};
    Vec2I direction;
    Vec2I boardSize;
    std::vector<Vec2I> body;

    Snake() = default;
    Snake(Vec2I boardSize);

    void move(Vec2I direction, bool grow);

    bool selfCollision();

    void draw(const VideoOptions &video, float cellSize) const;

    bool isSnake(Vec2I point);

    void serialize(std::ostream &os) const;

    static Snake deserialize(std::istream &is);
};

} // namespace snk

#endif // SNAKE_HPP