#include <gtest/gtest.h>
#include "Ship.hpp"

TEST(ShipTests, DefaultConstructor) {
    Ship ship;
    EXPECT_EQ(ship.getPosition().x, 400);
    EXPECT_EQ(ship.getPosition().y, 500);
    EXPECT_EQ(ship.getType() == 1 || ship.getType() == 2, true);
}

TEST(ShipTests, ParameterizedConstructor) {
    Ship ship(100, 200, 2);
    EXPECT_EQ(ship.getPosition().x, 100);
    EXPECT_EQ(ship.getPosition().y, 200);
    EXPECT_EQ(ship.getType(), 2);
}

TEST(ShipTests, Move) {
    Ship ship;
    ship.move(50);
    EXPECT_EQ(ship.getPosition().x, 450);
    EXPECT_EQ(ship.getPosition().y, 500);
}

TEST(ShipTests, SetPosition) {
    Ship ship;
    ship.setPosition(300, 400);
    EXPECT_EQ(ship.getPosition().x, 300);
    EXPECT_EQ(ship.getPosition().y, 400);
}

TEST(ShipTests, SetType) {
    Ship ship;
    ship.setType(3);
    EXPECT_EQ(ship.getType(), 3);
}

TEST(ShipTests, SetRandomType) {
    Ship ship;
    ship.setRandomType();
    size_t type = ship.getType();
    EXPECT_TRUE(type == 1 || type == 2);
}

TEST(ShipTests, SetTexture) {
    Ship ship;
    sf::Texture texture({10, 10});
    ship.setTexture(texture);
    EXPECT_EQ(ship.getShape().getTexture(), &texture);
}
