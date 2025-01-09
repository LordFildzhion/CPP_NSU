#include <gtest/gtest.h>
#include "Asteroid.hpp"

TEST(AsteroidTest, InitialPosition) {
    Asteroid asteroid(100.0f, 200.0f);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 100.0f);
    EXPECT_FLOAT_EQ(position.y, 200.0f);
}

TEST(AsteroidTest, Move) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.move(50.0f);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 100.0f);
    EXPECT_FLOAT_EQ(position.y, 250.0f);
}

TEST(AsteroidTest, SetPosition) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setPosition(300.0f, 400.0f);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 300.0f);
    EXPECT_FLOAT_EQ(position.y, 400.0f);
}

TEST(AsteroidTest, SetRadius) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRadius(30.0f);
    EXPECT_FLOAT_EQ(asteroid.getRadius(), 30.0f);
}

TEST(AsteroidTest, SetRandomRadius) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRandomRadius();
    float radius = asteroid.getRadius();
    EXPECT_GE(radius, 10.0f);
    EXPECT_LE(radius, 30.0f);
}

TEST(AsteroidTest, SetType) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setType(2);
    EXPECT_EQ(asteroid.getType(), 2);
}

TEST(AsteroidTest, SetRandomType) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRandomType();
    size_t type = asteroid.getType();
    EXPECT_GE(type, 1);
    EXPECT_LE(type, 3);
}

TEST(AsteroidTest, SetTexture) {
    Asteroid asteroid(100.0f, 200.0f);
    sf::Texture texture({100, 100});
    asteroid.setTexture(texture);
    EXPECT_EQ(asteroid.getShape().getTexture(), &texture);
}

TEST(AsteroidTest, SetRandomAsteroid) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRandomAsteroid();
    float radius = asteroid.getRadius();
    size_t type = asteroid.getType();
    EXPECT_GE(radius, 10.0f);
    EXPECT_LE(radius, 30.0f);
    EXPECT_GE(type, 1);
    EXPECT_LE(type, 3);
}
