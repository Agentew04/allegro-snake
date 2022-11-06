#include "math.hpp"

// vector x vector
snk::Vec2I snk::Vec2I::operator+(const Vec2I &other) const{
    return Vec2I(x + other.x, y + other.y);
}

snk::Vec2I snk::Vec2I::operator-(const Vec2I &other) const{
    return Vec2I(x - other.x, y - other.y);
}

// scalar x vector
snk::Vec2I snk::Vec2I::operator*(const int &other) const{
    return Vec2I(x * other, y * other);
}
snk::Vec2I snk::Vec2I::operator/(const int &other) const{
    return Vec2I(x / other, y / other);
}

// comparators
bool snk::Vec2I::operator==(const Vec2I &other) const{
    return x == other.x && y == other.y;
}
bool snk::Vec2I::operator!=(const Vec2I &other) const{
    return !(x == other.x && y == other.y);
}

float snk::Vec2I::distance(const snk::Vec2I &other) const{
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
float snk::Vec2I::magnitude() const{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}
snk::Vec2I snk::Vec2I::normalize() const{
    return *this / magnitude();
}
int snk::Vec2I::dot(const snk::Vec2I &other) const{
    return x * other.x + y * other.y;
}
// snk::Vec2I cross(const snk::Vec2I &a, const snk::Vec2I &b){
//     return snk::Vec2I(a.y * b.x, a.x * b.y);
// }
float snk::Vec2I::angle(const Vec2I &other) const{
    float dotProduct = dot(other);
    float magProduct = magnitude() * other.magnitude();
    float res = std::acos(dotProduct / magProduct);
    if (res != res) return 0;
    return res;
}

snk::Vec2I snk::Vec2I::zero(){
    return Vec2I(0,0);
}
snk::Vec2I snk::Vec2I::left(){
    return Vec2I(-1,0);
}
snk::Vec2I snk::Vec2I::right(){
    return Vec2I(1,0);
}
snk::Vec2I snk::Vec2I::up(){
    return Vec2I(0,-1);
}
snk::Vec2I snk::Vec2I::down(){
    return Vec2I(0,1);
}