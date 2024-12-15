#include <gtest/gtest.h>

#include "pixel.hpp"

TEST(PixelTest, DefaultConstructor) {
    pixel p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
    EXPECT_EQ(p.getColor(), color::NOT_COLOR);
}

TEST(PixelTest, ParameterizedConstructor) {
    pixel p(10, 20, color::RED);
    EXPECT_EQ(p.getX(), 10);
    EXPECT_EQ(p.getY(), 20);
    EXPECT_EQ(p.getColor(), color::RED);
}

TEST(PixelTest, SetX) {
    pixel p;
    p.setX(15);
    EXPECT_EQ(p.getX(), 15);
}

TEST(PixelTest, SetY) {
    pixel p;
    p.setY(25);
    EXPECT_EQ(p.getY(), 25);
}

TEST(PixelTest, SetColor) {
    pixel p;
    p.setColor(color::GREEN);
    EXPECT_EQ(p.getColor(), color::GREEN);
}

TEST(PixelTest, EqualityOperator) {
    pixel p1(10, 20, color::BLUE);
    pixel p2(10, 20, color::BLUE);
    EXPECT_TRUE(p1 == p2);
}

TEST(PixelTest, InequalityOperator) {
    pixel p1(10, 20, color::BLUE);
    pixel p2(10, 20, color::RED);
    EXPECT_TRUE(p1 != p2);
}