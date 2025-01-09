#ifndef BACKGROUND_TESTS_HPP
#define BACKGROUND_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "Background.hpp"

class TestsBackground : public :: BackGround {
 public:
    explicit TestsBackground(sf::RenderWindow &window) : BackGround(window) {}

    using BackGround::spawnElements;
    using BackGround::moveElements;
    using BackGround::printElements;
    using BackGround::checkOutOfBounds;
};

TEST(BackgroundTests, SpawnElements) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    TestsBackground background(window);
    background.spawnElements();
    ASSERT_EQ(background.getElements().size(), 1);
}

TEST(BackgroundTests, MoveElements) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    TestsBackground background(window);
    background.spawnElements();
    float firstPosition = background.getElements().back().getShape().getPosition().x;
    background.moveElements();
    ASSERT_EQ(background.getElements().back().getShape().getPosition().x, firstPosition - 1);
}

TEST(BackgroundTests, PrintElements) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    TestsBackground background(window);
    background.spawnElements();
    background.printElements();
    ASSERT_EQ(background.getElements().back().getShape().getFillColor(), sf::Color::White);
}

TEST(BackgroundTests, CheckOutOfBounds) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    TestsBackground background(window);
    background.spawnElements(1);
    background.getElements().back().getShape().setPosition({-static_cast<float>(BackGroundSpawnerValues::SPAWN_BORDER) - 1, 0});
    std::cout << background.getElements().back().getShape().getPosition().x << std::endl;
    background.checkOutOfBounds();
    ASSERT_EQ(background.getElements().size(), 0);
}

#endif  // BACKGROUND_TESTS_HPP
