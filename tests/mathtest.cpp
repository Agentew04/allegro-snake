#include <gtest/gtest.h>
#include "../math.hpp"

TEST(Vec2I, VectorAdd) {
    snk::Vec2I a(1, 2);
    snk::Vec2I b(3, 4);

    snk::Vec2I res(4, 6);
    EXPECT_EQ(res, a + b);
}

TEST(Vec2I, VectorSub) {
    snk::Vec2I a(1, 2);
    snk::Vec2I b(3, 4);

    snk::Vec2I res(-2, -2);
    EXPECT_EQ(res, a - b);
}

TEST(Vec2I, ScalarMult) {
    snk::Vec2I a(1, 2);
    int b = 3;

    snk::Vec2I res(3, 6);
    EXPECT_EQ(res, a * b);
}

TEST(Vec2I, ScalarDiv) {
    snk::Vec2I a(1, 2);
    int b = 3;

    snk::Vec2I res(0, 0);
    EXPECT_EQ(res, a / b);

    snk::Vec2I c(3, 6);
    EXPECT_EQ(a, c / b);
}

TEST(Vec2I, VectorEq) {
    snk::Vec2I a(1, 2);
    snk::Vec2I b(1, 2);

    EXPECT_EQ(a, b);
}

TEST(Vec2I, VectorNeq) {
    snk::Vec2I a(1, 2);
    snk::Vec2I b(3, 4);

    EXPECT_NE(a, b);
}

TEST(Vec2I, Distance) {
    snk::Vec2I a1(0,0);
    snk::Vec2I a2(3, 0);
    snk::Vec2I b1(0,0);
    snk::Vec2I b2(3, 4);
    snk::Vec2I c1(1,1);
    snk::Vec2I c2(-1,-1);

    float c1c2Res = 2.83;
    EXPECT_EQ(3, a1.distance(a2));
    EXPECT_EQ(5, b1.distance(b2));
    EXPECT_EQ(c1c2Res, std::round(c1.distance(c2)*100)/100);
}

TEST(Vec2I, Magnitude) {
    snk::Vec2I a(3, 4);
    snk::Vec2I b(-2, 0);
    snk::Vec2I c(-1, -1);

    float cRes = 1.41;
    EXPECT_EQ(5, a.magnitude());
    EXPECT_EQ(2, b.magnitude());
    EXPECT_EQ(cRes, std::round(c.magnitude()*100)/100);
}

TEST(Vec2I, Normalize) {
    snk::Vec2I a(3, 0);
    snk::Vec2I b(0, 3);
    //snk::Vec2I c(-3, -3);

    snk::Vec2I resA(1, 0);
    snk::Vec2I resB(0, 1);
    //snk::Vec2I resC(-1, -1);
    EXPECT_EQ(resA, a.normalize());
    EXPECT_EQ(resB, b.normalize());
    //EXPECT_EQ(resC, c.normalize());
}

TEST(Vec2I, Dot) {
    snk::Vec2I a(1, 0);
    snk::Vec2I b(0, 1);
    snk::Vec2I c(1, 1);
    snk::Vec2I o(0,0);

    EXPECT_EQ(0, a.dot(b));
    EXPECT_EQ(0, b.dot(a));

    EXPECT_EQ(1, a.dot(a));
    EXPECT_EQ(1, b.dot(b));
    EXPECT_EQ(2, c.dot(c));

    EXPECT_EQ(1, c.dot(a));
    EXPECT_EQ(1, c.dot(b));

    EXPECT_EQ(0, o.dot(a));
    EXPECT_EQ(0, o.dot(b));
    EXPECT_EQ(0, o.dot(c));
}

TEST(Vec2I, Angle) {
    snk::Vec2I a(1, 0);
    snk::Vec2I b(0, 1);
    snk::Vec2I c(1, 1);

    EXPECT_EQ(0, a.angle(a));
    EXPECT_EQ(0, b.angle(b));
    EXPECT_EQ(0, c.angle(c));

    EXPECT_EQ(90, snk::radToDeg(a.angle(b)));
    EXPECT_EQ(90, snk::radToDeg(b.angle(a)));

    EXPECT_EQ(45, snk::radToDeg(c.angle(a)));
    EXPECT_EQ(45, snk::radToDeg(c.angle(b)));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}