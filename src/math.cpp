#include "math.hpp"

bool snk::Rectangle::contains(Vec2F point) const{
    return point.x >= pos.x && point.x <= pos.x + size.x &&
           point.y >= pos.y && point.y <= pos.y + size.y;
}
bool snk::Rectangle::intersects(Rectangle other) const{
    return contains(other.pos) || contains(other.pos + other.size) ||
           other.contains(pos) || other.contains(pos + size);
}

bool snk::Circle::contains(Vec2F point) const{
    return sqrt(pow(point.x - pos.x, 2) + pow(point.y - pos.y, 2)) <= radius;
}
bool snk::Circle::intersects(Circle other) const{
    float centerDistance = other.pos.distance(pos);
    return centerDistance <= radius + other.radius;
}

// SOLITARY FUNCTIONS

float snk::degToRad(float deg){
    return deg * M_PI / 180;
}
float snk::radToDeg(float rad){
    return rad * 180 / M_PI;
}