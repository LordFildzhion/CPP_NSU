#include <gtest/gtest.h>

#include "Pixel/Pixel.hpp"

TEST(PixelTest, DefaultConstructor) {
    Pixel p;
    EXPECT_EQ(p.getX(), 0);
    EXPECT_EQ(p.getY(), 0);
    EXPECT_EQ(p.getColor(), color::NOT_COLOR);
}

TEST(PixelTest, ParameterizedConstructor) {
    Pixel p(10, 20, color::RED);
    EXPECT_EQ(p.getX(), 10);
    EXPECT_EQ(p.getY(), 20);
    EXPECT_EQ(p.getColor(), color::RED);
}

TEST(PixelTest, SetX) {
    Pixel p;
    p.setX(15);
    EXPECT_EQ(p.getX(), 15);
}

TEST(PixelTest, SetY) {
    Pixel p;
    p.setY(25);
    EXPECT_EQ(p.getY(), 25);
}

TEST(PixelTest, SetColor) {
    Pixel p;
    p.setColor(color::GREEN);
    EXPECT_EQ(p.getColor(), color::GREEN);
}

TEST(PixelTest, EqualityOperator) {
    Pixel p1(10, 20, color::BLUE);
    Pixel p2(10, 20, color::BLUE);
    EXPECT_TRUE(p1 == p2);
}

TEST(PixelTest, InequalityOperator) {
    Pixel p1(10, 20, color::BLUE);
    Pixel p2(10, 20, color::RED);
    EXPECT_TRUE(p1 != p2);
}