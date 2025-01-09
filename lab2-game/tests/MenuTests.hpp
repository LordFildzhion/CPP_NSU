#ifndef MENU_TESTS_HPP
#define MENU_TESTS_HPP

#include <string>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "Menu.hpp"
#include "Button.hpp"

class TestMenu : private Menu {
 public:
    explicit TestMenu(sf::RenderWindow &window) : Menu(window) {}

    Button getStartButton() {
        return startButton;
    }

    Button getExitButton() {
        return exitButton;
    }

    void draw() {
        Menu::draw();
    }

    void createButton(Button &button, const std::string &message, float x, float y, const sf::Color &fillColor, const float size) {
        Menu::createButton(button, message, {x, y}, fillColor, size);
    }

    void createLabel(const std::string &message, float x, float y, const sf::Color &fillColor, sf::Font font, const float size) {
        Menu::createLabel(message, x, y, fillColor, font, size);
    }
};


class MenuTest : public ::testing::Test {
 protected:
    sf::RenderWindow window;
    TestMenu* menu;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        menu = new TestMenu(window);
    }

    void TearDown() override {
        delete menu;
        window.close();
    }
};

TEST_F(MenuTest, MenuInitialization) {
    EXPECT_NO_THROW(Menu menu(window));
}

TEST_F(MenuTest, DrawMenu) {
    EXPECT_NO_THROW(menu->draw());
}

TEST_F(MenuTest, CreateButton) {
    Button testButton(window, "Test");
    EXPECT_NO_THROW(menu->createButton(testButton, "Test", 100, 100, sf::Color::White, 50));
}

TEST_F(MenuTest, CreateLabel) {
    sf::Font font;
    EXPECT_NO_THROW(menu->createLabel("Test", 100, 100, sf::Color::White, font, 50));
}

#endif  // MENU_TESTS_HPP
