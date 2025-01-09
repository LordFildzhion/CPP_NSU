#include <gtest/gtest.h>
#include "Bullet.hpp"
#include "Textures.hpp"

TEST(BulletTest, DefaultConstructor) {
    Bullet bullet(0.0f, 0.0f);
    EXPECT_EQ(bullet.getPositionWithoutScatter().x, 0.0f);
    EXPECT_EQ(bullet.getPositionWithoutScatter().y, 0.0f);
    EXPECT_EQ(bullet.getScatter(), bullet.getScatter());
    EXPECT_EQ(bullet.getType(), 1);
}

TEST(BulletTest, Move) {
    Bullet bullet(0.0f, 0.0f);
    bullet.move(10.0f);
    EXPECT_EQ(bullet.getPosition().y, 10.0f);
}

TEST(BulletTest, SetPosition) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setPosition(5.0f, 5.0f);
    EXPECT_EQ(bullet.getPosition().x, 5.0f);
    EXPECT_EQ(bullet.getPosition().y, 5.0f);
}

TEST(BulletTest, SetTexture) {
    Bullet bullet(0.0f, 0.0f);
    sf::Texture texture;
    bullet.setTexture(texture);
    EXPECT_NE(bullet.getShape().getTexture(), nullptr);
}

TEST(BulletTest, SetScatter) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setScatter(5);
    EXPECT_EQ(bullet.getScatter(), 5);
}

TEST(BulletTest, SetType) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setType(3);
    EXPECT_EQ(bullet.getType(), 3);
}

TEST(BulletTest, SetRandomType) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setRandomType(5);
    EXPECT_GE(bullet.getType(), 1);
    EXPECT_LE(bullet.getType(), 5);
}
