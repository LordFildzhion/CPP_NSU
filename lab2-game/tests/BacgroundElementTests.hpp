#ifndef BACKGROUND_ELEMENT_TESTS_HPP
#define BACKGROUND_ELEMENT_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "BackgroundElement.hpp"

TEST(BackgroundElementTest, DefaultConstructor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackgroundElement element(window);

    EXPECT_EQ(element.getShape().getFillColor(), BackgroundElementValues::DEFAULT_COLOR);
    EXPECT_GE(element.getShape().getRadius(), BackgroundElementValues::MIN_RADIUS);
    EXPECT_LE(element.getShape().getRadius(), BackgroundElementValues::MAX_RADIUS);
    EXPECT_GE(element.getShape().getPointCount(), BackgroundElementValues::MIN_ANGLE_COUNT);
    EXPECT_LE(element.getShape().getPointCount(), BackgroundElementValues::MAX_ANGLE_COUNT);
}

TEST(BackgroundElementTest, Move) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackgroundElement element(window);
    sf::Vector2f initialPosition = element.getShape().getPosition();

    element.move(5.0f);
    EXPECT_EQ(element.getShape().getPosition().x, initialPosition.x + 5.0f);
    EXPECT_EQ(element.getShape().getPosition().y, initialPosition.y);
}

TEST(BackgroundElementTest, SetFillColor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackgroundElement element(window);
    sf::Color newColor = sf::Color::Red;

    element.setFillColor(newColor);
    EXPECT_EQ(element.getShape().getFillColor(), newColor);
}

TEST(BackgroundElementTest, SetRadius) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackgroundElement element(window);
    float newRadius = 5.0f;

    element.setRadius(newRadius);
    EXPECT_EQ(element.getShape().getRadius(), newRadius);
}

TEST(BackgroundElementTest, SetPointCount) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackgroundElement element(window);
    size_t newPointCount = 8;

    element.setPointCount(newPointCount);
    EXPECT_EQ(element.getShape().getPointCount(), newPointCount);
}

TEST(BackgroundElementTest, SetPosition) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    BackgroundElement element(window);
    sf::Vector2f newPosition(100.0f, 100.0f);

    element.setPosition(newPosition);
    EXPECT_EQ(element.getShape().getPosition(), newPosition);
}

#endif  // BACKGROUND_ELEMENT_TESTS_HPP