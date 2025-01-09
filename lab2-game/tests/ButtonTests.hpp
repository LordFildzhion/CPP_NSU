#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Button.hpp"

TEST(ButtonTests, SetMessage) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Initial Message");
    button.setMessage("New Message");
    EXPECT_EQ(button.getText().getString(), "New Message");
}

TEST(ButtonTests, SetPosition) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    button.setPosition(100, 150);
    EXPECT_EQ(button.getPosition(), sf::Vector2f(100, 150));
}

TEST(ButtonTests, SetFillColor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    button.setFillColor(sf::Color::Red);
    EXPECT_EQ(button.getText().getFillColor(), sf::Color::Red);
}

TEST(ButtonTests, SetOutlineColor) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    button.setOutlineColor(sf::Color::Green);
    EXPECT_EQ(button.getText().getOutlineColor(), sf::Color::Green);
}

TEST(ButtonTests, SetOutlineThickness) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    button.setOutlineThickness(5.0f);
    EXPECT_EQ(button.getText().getOutlineThickness(), 5.0f);
}

TEST(ButtonTests, SetSize) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    button.setSize(50.0f);
    EXPECT_EQ(button.getText().getCharacterSize(), 50.0f);
}

TEST(ButtonTests, IsPressed) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    // Simulate mouse press
    sf::Mouse::setPosition(sf::Vector2i(100, 150), window);
    button.setPosition(100, 150);
    EXPECT_FALSE(button.isPressed());
}

TEST(ButtonTests, IsHovered) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Button button(window, "Test Message");
    button.setSize(50.0f);
    button.setPosition(100, 150);
    sf::Mouse::setPosition(sf::Vector2i(150, 175), window);
    EXPECT_TRUE(button.isHovered());
}
