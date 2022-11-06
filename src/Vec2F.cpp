#include "math.hpp"

// vector x vector
snk::Vec2F snk::Vec2F::operator+(const Vec2F &other) const{
    return Vec2F(x + other.x, y + other.y);
}
snk::Vec2F snk::Vec2F::operator-(const Vec2F &other) const{
    return Vec2F(x - other.x, y - other.y);
}

// scalar x vector
snk::Vec2F snk::Vec2F::operator*(const float &other) const{
    return Vec2F(x * other, y * other);
}
snk::Vec2F snk::Vec2F::operator/(const float &other) const{
    return Vec2F(x / other, y / other);
}

// comparators
bool snk::Vec2F::operator==(const Vec2F &other) const{
    float Xdif = std::abs(x - other.x);
    float Ydif = std::abs(y - other.y);
    return Xdif < 0.0001 && Ydif < 0.0001;
}
bool snk::Vec2F::operator!=(const Vec2F &other) const{
    return !(x == other.x && y == other.y);
}

float snk::Vec2F::distance(const snk::Vec2F &other) const{
    return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
}
float snk::Vec2F::magnitude() const{
    return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
}
snk::Vec2F snk::Vec2F::normalize() const{
    return *this / magnitude();
}
float snk::Vec2F::dot(const snk::Vec2F &other) const{
    return x * other.x + y * other.y;
}
// snk::Vec2F cross(const snk::Vec2F &a, const snk::Vec2F &b){
//     return snk::Vec2F(a.x * b.y, a.y * b.x);
// }
float snk::Vec2F::angle(const Vec2F &other) const{
    float dotProduct = dot(other);
    float magProduct = magnitude() * other.magnitude();
    return std::acos(dotProduct / magProduct);
}

snk::Vec2F snk::Vec2F::zero(){
    return Vec2F(0,0);
}
snk::Vec2F snk::Vec2F::left(){
    return Vec2F(-1,0);
}
snk::Vec2F snk::Vec2F::right(){
    return Vec2F(1,0);
}
snk::Vec2F snk::Vec2F::up(){
    return Vec2F(0,-1);
}
snk::Vec2F snk::Vec2F::down(){
    return Vec2F(0,1);
}