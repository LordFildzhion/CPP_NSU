#ifndef TEST_BUTTON_HPP
#define TEST_BUTTON_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

TEST(ButtonTests, DefaultConstructor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test");
    sf::Font font;
    Button button(window, "", font);
    EXPECT_EQ(button.getPosition(), sf::Vector2f(0, 0));
    EXPECT_EQ(button.getSFMLText().getString(), "");
}

TEST(ButtonTests, ParameterizedConstructor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test");
    sf::Font font;
    Button button(window, "Click Me", font, {100, 200}, sf::Color::Red, 30);
    EXPECT_EQ(button.getPosition(), sf::Vector2f(100, 200));
    EXPECT_EQ(button.getSFMLText().getString(), "Click Me");
}

TEST(ButtonTests, SetPosition) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test");
    sf::Font font;
    Button button(window, "", font);
    button.setPosition(sf::Vector2f(300, 400));
    EXPECT_EQ(button.getPosition(), sf::Vector2f(300, 400));
}

TEST(ButtonTests, SetLabel) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test");
    sf::Font font;
    Button button(window, "", font);
    button.setMessage("Submit");
    EXPECT_EQ(button.getSFMLText().getString(), "Submit");
}

#endif  // TEST_BUTTON_HPP
