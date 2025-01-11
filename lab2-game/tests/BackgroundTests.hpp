#ifndef BACKGROUND_TESTS_HPP
#define BACKGROUND_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Background.hpp"

class BackgroundTests : public ::testing::Test {
protected:
    sf::RenderWindow window;
    Background* background;

    BackgroundTests() : window(sf::VideoMode({800, 600}), "Test Window") {
        background = Background::getInstance(window);
    }

    void SetUp() override {
        background->restart();
    }

    void TearDown() override {
        background->restart();
    }
};

TEST_F(BackgroundTests, SingletonInstance) {
    Background* instance1 = Background::getInstance(window);
    Background* instance2 = Background::getInstance(window);
    ASSERT_EQ(instance1, instance2);
}

TEST_F(BackgroundTests, SetAndGetElements) {
    std::vector<BackgroundElement> elements;
    BackgroundElement element(window);
    elements.emplace_back(element);
    background->setElements(elements);
    ASSERT_EQ(background->getElements().size(), 1);
}

TEST_F(BackgroundTests, RestartBackground) {
    std::vector<BackgroundElement> elements;
    BackgroundElement element(window);
    elements.emplace_back(element);
    background->setElements(elements);
    background->restart();
    ASSERT_TRUE(background->getElements().empty());
}

#endif  // BACKGROUND_TESTS_HPP
