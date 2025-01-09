#ifndef BACKGROUND_MOVER_TESTS_HPP
#define BACKGROUND_MOVER_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "BackgroundMover.hpp"
#include "BackgroundElement.hpp"

class BackgroundMoverTests : public ::testing::Test {
protected:
    sf::RenderWindow window;
    std::vector<BackGroundElement> elements;
    BackGroundMover* mover;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        elements.push_back(BackGroundElement(window));
        elements.push_back(BackGroundElement(window));
        mover = new BackGroundMover(window, elements);
    }

    void TearDown() override {
        delete mover;
        window.close();
    }
};

TEST_F(BackgroundMoverTests, ElementsMove) {
    sf::Vector2f initialPosition1 = elements.at(0).getShape().getPosition();
    sf::Vector2f initialPosition2 = elements.at(1).getShape().getPosition();

    mover->moveElements();

    EXPECT_EQ(elements.at(0).getShape().getPosition().x, initialPosition1.x + BackGroundMoverValues::MOVE_SPEED);
    EXPECT_EQ(elements.at(1).getShape().getPosition().x, initialPosition2.x + BackGroundMoverValues::MOVE_SPEED);
}

TEST_F(BackgroundMoverTests, ElementsMoveMultipleTimes) {
    sf::Vector2f initialPosition1 = elements.at(0).getShape().getPosition();
    sf::Vector2f initialPosition2 = elements.at(1).getShape().getPosition();

    for (int i = 0; i < 10; ++i) {
        mover->moveElements();
    }

    EXPECT_EQ(elements.at(0).getShape().getPosition().x, initialPosition1.x + 10 * BackGroundMoverValues::MOVE_SPEED);
    EXPECT_EQ(elements.at(1).getShape().getPosition().x, initialPosition2.x + 10 * BackGroundMoverValues::MOVE_SPEED);
}

#endif  // BACKGROUND_MOVER_TESTS_HPP