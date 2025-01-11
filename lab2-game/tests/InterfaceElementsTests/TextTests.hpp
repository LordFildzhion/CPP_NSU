#ifndef TEXT_TESTS_HPP
#define TEXT_TESTS_HPP

#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include "Text.hpp"
#include "Fonts.hpp"

TEST(TextTests, DefaultConstructor) {
    Text text;
    EXPECT_EQ(text.getMessage(), "");
    EXPECT_EQ(text.getPosition(), sf::Vector2f(0, 0));
    EXPECT_EQ(text.getFillColor(), sf::Color::White);
    EXPECT_EQ(text.getSize(), 0);
}

TEST(TextTests, ParameterizedConstructor) {
    Fonts *fonts = Fonts::getInstance();
    fonts->loadFonts();
    sf::Font font = fonts->getFonts().front();
    Text text("Hello", sf::Vector2f(100, 100), sf::Color::Red, font, 30);
    EXPECT_EQ(text.getMessage(), "Hello");
    EXPECT_EQ(text.getPosition(), sf::Vector2f(100, 100));
    EXPECT_EQ(text.getFillColor(), sf::Color::Red);
    EXPECT_EQ(text.getFont().getInfo().family, font.getInfo().family);
    EXPECT_EQ(text.getSize(), 30);
}

TEST(TextTests, SetMessage) {
    Text text;
    text.setMessage("New Message");
    EXPECT_EQ(text.getMessage(), "New Message");
}

TEST(TextTests, SetPosition) {
    Text text;
    text.setPosition(sf::Vector2f(50, 50));
    EXPECT_EQ(text.getPosition(), sf::Vector2f(50, 50));
}

TEST(TextTests, SetFillColor) {
    Text text;
    text.setFillColor(sf::Color::Blue);
    EXPECT_EQ(text.getFillColor(), sf::Color::Blue);
}

TEST(TextTests, SetFont) {
    Fonts *fonts = Fonts::getInstance();
    fonts->loadFonts();
    sf::Font font = fonts->getFonts().front();
    Text text;
    text.setFont(font);
    EXPECT_EQ(text.getFont().getInfo().family, font.getInfo().family);
}

TEST(TextTests, SetSize) {
    Text text;
    text.setSize(25);
    EXPECT_EQ(text.getSize(), 25);
}

TEST(TextTests, GetGlobalBounds) {
    Fonts *fonts = Fonts::getInstance();
    fonts->loadFonts();
    sf::Font font = fonts->getFonts().front();
    Text text("Bounds Test", sf::Vector2f(0, 0), sf::Color::White, font, 20);
    sf::FloatRect bounds = text.getGlobalBounds();
    EXPECT_GT(bounds.position.x, 0);
    EXPECT_GT(bounds.position.y, 0);
}

#endif  // TEXT_TESTS_HPP