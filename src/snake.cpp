#include "snake.hpp"

snk::Snake::Snake() {
    body.push_back(snk::Vec2I(0, 0));
}

void snk::Snake::move(int x, int y) {
    body.insert(body.begin(), snk::Vec2I(x, y));
    body.pop_back();
}

void snk::Snake::grow(int x, int y) {
    body.insert(body.begin(), snk::Vec2I(x, y));
}

bool snk::Snake::contains(snk::Vec2I point) {
    for (auto &i : body) {
        if (i == point) {
            return true;
        }
    }
    return false;
}

void snk::Snake::draw(const snk::VideoOptions &options) {
    // todo
}