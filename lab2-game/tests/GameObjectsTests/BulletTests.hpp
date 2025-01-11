#ifndef BULLET_TESTS_HPP
#define BULLET_TESTS_HPP

#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include "Bullet.hpp"

TEST(BulletTests, DefaultConstructor) {
    Bullet bullet(0.0f, 0.0f);
    EXPECT_EQ(bullet.getType(), BulletValues::BULLET_TYPE_DEFAULT);
}

TEST(BulletTests, PositionConstructor) {
    sf::Vector2f position(10.0f, 20.0f);
    Bullet bullet(position);
    EXPECT_EQ(bullet.getPosition().x, position.x + bullet.getScatter());
    EXPECT_EQ(bullet.getPosition().y, position.y);
}

TEST(BulletTests, Move) {
    Bullet bullet(0.0f, 0.0f);
    bullet.move(10.0f);
    EXPECT_EQ(bullet.getPosition().y, 10.0f);
}

TEST(BulletTests, SetPosition) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setPosition(15.0f, 25.0f);
    EXPECT_EQ(bullet.getPosition().x, 15.0f);
    EXPECT_EQ(bullet.getPosition().y, 25.0f);
}

TEST(BulletTests, SetTexture) {
    Bullet bullet(0.0f, 0.0f);
    sf::Texture texture;
    bullet.setTexture(texture);
    EXPECT_EQ(bullet.getShape().getTexture(), &texture);
}

TEST(BulletTests, SetScatter) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setScatter(5);
    EXPECT_EQ(bullet.getScatter(), 5);
    EXPECT_EQ(bullet.getPosition().x, 5.0f);
}

TEST(BulletTests, SetType) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setType(3);
    EXPECT_EQ(bullet.getType(), 3);
}

TEST(BulletTests, SetRandomType) {
    Bullet bullet(0.0f, 0.0f);
    bullet.setRandomType(5);
    EXPECT_GE(bullet.getType(), 1);
    EXPECT_LE(bullet.getType(), 5);
}

#endif  // BULLET_TESTS_HPP
