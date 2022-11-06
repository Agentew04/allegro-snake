#ifndef MATH_HPP
#define MATH_HPP

#include <cmath>

namespace snk{

struct Vec2I{
public:
    int x {};
    int y {};

    Vec2I(int x, int y): x(x), y(y) {};
    Vec2I() = default;

    static Vec2I zero();
    static Vec2I left();
    static Vec2I right();
    static Vec2I up();
    static Vec2I down();


    // vector x vector
    Vec2I operator+(const Vec2I &other) const;
    Vec2I operator-(const Vec2I &other) const;

    // scalar x vector
    Vec2I operator*(const int &other) const;
    Vec2I operator/(const int &other) const;

    // comparators
    bool operator==(const Vec2I &other) const;
    bool operator!=(const Vec2I &other) const;

    float distance(const Vec2I &other) const;
    float magnitude() const;
    Vec2I normalize() const;
    int dot(const Vec2I &other) const;
    float angle(const Vec2I &other) const;

    //Vec2I cross(const Vec2I &other) const;

};

struct Vec2F{
public:
    float x {};
    float y {};

    Vec2F(float x, float y): x(x), y(y) {};
    Vec2F() = default;

    static Vec2F zero();
    static Vec2F left();
    static Vec2F right();
    static Vec2F up();
    static Vec2F down();

    // vector x vector
    Vec2F operator+(const Vec2F &other) const;
    Vec2F operator-(const Vec2F &other) const;

    // scalar x vector
    Vec2F operator*(const float &other) const;
    Vec2F operator/(const float &other) const;

    // comparators
    bool operator==(const Vec2F &other) const;
    bool operator!=(const Vec2F &other) const;

    float distance(const Vec2F &other) const;
    float magnitude() const;
    Vec2F normalize() const;
    float dot(const Vec2F &other) const;
    //Vec2F cross(const Vec2F &other) const;
    float angle(const Vec2F &other) const;
};

struct Rectangle{
public:
    Vec2F pos;
    Vec2F size;

    Rectangle(Vec2F pos, Vec2F size): pos(pos), size(size) {};
    Rectangle() = default;

    bool contains(Vec2F point) const;
    bool intersects(Rectangle other) const;
};

struct Circle{
    Vec2F pos;
    float radius;

    Circle(Vec2F pos, float radius): pos(pos), radius(radius) {};
    Circle() = default;

    bool contains(Vec2F point) const;
    bool intersects(Circle other) const;
};

float degToRad(float deg);
float radToDeg(float rad);

} // snk

#endif // MATH_HPP