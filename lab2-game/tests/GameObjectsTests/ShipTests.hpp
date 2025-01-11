#ifndef SHIP_TESTS_HPP
#define SHIP_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Ship.hpp"

TEST(ShipTests, DefaultConstructor) {
    Ship ship;
    EXPECT_EQ(ship.getPosition(), sf::Vector2f(400, 500));
    EXPECT_EQ(ship.getType(), 1);
}

TEST(ShipTests, ParameterizedConstructor) {
    Ship ship(100, 200, 2);
    EXPECT_EQ(ship.getPosition(), sf::Vector2f(100, 200));
    EXPECT_EQ(ship.getType(), 2);
}

TEST(ShipTests, Move) {
    Ship ship;
    ship.move(50);
    EXPECT_EQ(ship.getPosition(), sf::Vector2f(450, 500));
}

TEST(ShipTests, SetPosition) {
    Ship ship;
    ship.setPosition(300, 400);
    EXPECT_EQ(ship.getPosition(), sf::Vector2f(300, 400));
}

TEST(ShipTests, SetType) {
    Ship ship;
    ship.setType(3);
    EXPECT_EQ(ship.getType(), 3);
}

TEST(ShipTests, SetRandomType) {
    Ship ship;
    ship.setRandomType(5);
    EXPECT_GE(ship.getType(), 1);
    EXPECT_LE(ship.getType(), 5);
}

TEST(ShipTests, SetTexture) {
    Ship ship;
    sf::Texture texture(sf::Vector2u(100, 100));
    ship.setTexture(texture);
    EXPECT_EQ(ship.getShape().getTexture(), &texture);
}

#endif  // SHIP_TESTS_HPP