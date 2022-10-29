#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>
#include "options.hpp"
#include "math.hpp"

namespace snk{

struct Snake{
public:
    Vec2I head;
    Vec2I direction;
    std::vector<Vec2I> body;

    Snake();

    void move(int x, int y);

    void grow(int x, int y);

    void draw(const VideoOptions &video);

    bool contains(Vec2I point);
};

} // namespace snk

#endif // SNAKE_HPP