#ifndef BACKGROUND_ELEMENT_TESTS_HPP
#define BACKGROUND_ELEMENT_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "BackgroundElement.hpp"

TEST(BackgroundElementTests, DefaultConstructor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackGroundElement element(window);

    EXPECT_EQ(element.getShape().getFillColor(), BackGroundElementValues::DEFAULT_COLOR);
    EXPECT_GE(element.getShape().getRadius(), BackGroundElementValues::MIN_RADIUS);
    EXPECT_LE(element.getShape().getRadius(), BackGroundElementValues::MAX_RADIUS);
    EXPECT_GE(element.getShape().getPointCount(), BackGroundElementValues::MIN_ANGLE_COUNT);
    EXPECT_LE(element.getShape().getPointCount(), BackGroundElementValues::MAX_ANGLE_COUNT);
}

TEST(BackgroundElementTests, Move) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackGroundElement element(window);
    sf::Vector2f initialPosition = element.getShape().getPosition();

    element.move(5.0f);
    EXPECT_EQ(element.getShape().getPosition().x, initialPosition.x + 5.0f);
    EXPECT_EQ(element.getShape().getPosition().y, initialPosition.y);
}

TEST(BackgroundElementTests, SetFillColor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackGroundElement element(window);
    sf::Color newColor = sf::Color::Red;

    element.setFillColor(newColor);
    EXPECT_EQ(element.getShape().getFillColor(), newColor);
}

TEST(BackgroundElementTests, SetRadius) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackGroundElement element(window);
    float newRadius = 5.0f;

    element.setRadius(newRadius);
    EXPECT_EQ(element.getShape().getRadius(), newRadius);
}

TEST(BackgroundElementTests, SetPointCount) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackGroundElement element(window);
    size_t newPointCount = 8;

    element.setPointCount(newPointCount);
    EXPECT_EQ(element.getShape().getPointCount(), newPointCount);
}

TEST(BackgroundElementTests, SetPosition) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackGroundElement element(window);
    sf::Vector2f newPosition(100.0f, 100.0f);

    element.setPosition(newPosition);
    EXPECT_EQ(element.getShape().getPosition(), newPosition);
}

#endif  // BACKGROUND_ELEMENT_TESTS_HPP
