#ifndef ASTEROID_TESTS_HPP
#define ASTEROID_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Asteroid.hpp"

TEST(AsteroidTests, ConstructorWithCoordinates) {
    Asteroid asteroid(100.0f, 200.0f);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 100.0f);
    EXPECT_FLOAT_EQ(position.y, 200.0f);
}

TEST(AsteroidTests, ConstructorWithPosition) {
    sf::Vector2f position(150.0f, 250.0f);
    Asteroid asteroid(position);
    sf::Vector2f asteroidPosition = asteroid.getPosition();
    EXPECT_FLOAT_EQ(asteroidPosition.x, 150.0f);
    EXPECT_FLOAT_EQ(asteroidPosition.y, 250.0f);
}

TEST(AsteroidTests, Move) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.move(50.0f);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 100.0f);
    EXPECT_FLOAT_EQ(position.y, 250.0f);
}

TEST(AsteroidTests, SetPositionWithCoordinates) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setPosition(300.0f, 400.0f);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 300.0f);
    EXPECT_FLOAT_EQ(position.y, 400.0f);
}

TEST(AsteroidTests, SetPositionWithVector) {
    Asteroid asteroid(100.0f, 200.0f);
    sf::Vector2f newPosition(300.0f, 400.0f);
    asteroid.setPosition(newPosition);
    sf::Vector2f position = asteroid.getPosition();
    EXPECT_FLOAT_EQ(position.x, 300.0f);
    EXPECT_FLOAT_EQ(position.y, 400.0f);
}

TEST(AsteroidTests, SetRadius) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRadius(15.0f);
    EXPECT_FLOAT_EQ(asteroid.getRadius(), 15.0f);
}

TEST(AsteroidTests, SetRandomRadius) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRandomRadius();
    EXPECT_GE(asteroid.getRadius(), AsteroidValues::MIN_RADIUS);
    EXPECT_LE(asteroid.getRadius(), AsteroidValues::MAX_RADIUS);
}

TEST(AsteroidTests, SetType) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setType(3);
    EXPECT_EQ(asteroid.getType(), 3);
}

TEST(AsteroidTests, SetRandomType) {
    Asteroid asteroid(100.0f, 200.0f);
    asteroid.setRandomType(5);
    int8_t type = asteroid.getType();
    EXPECT_GE(type, 1);
    EXPECT_LE(type, 5);
}

TEST(AsteroidTests, SetTexture) {
    Asteroid asteroid(100.0f, 200.0f);
    sf::Texture texture(sf::Vector2u(100, 100));
    asteroid.setTexture(texture);
    EXPECT_EQ(asteroid.getShape().getTexture(), &texture);
}

#endif  // ASTEROID_TESTS_HPP
