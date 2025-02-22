#ifndef MENU_TESTS_HPP
#define MENU_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Menu.hpp"

class MenuTests : public ::testing::Test {
 protected:
    sf::RenderWindow window;
    sf::Font font;
    Menu* menu;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        if (!font.openFromFile("../res/fonts/arialmt.ttf")) {
            throw std::runtime_error("Failed to load font");
        }
        menu = new Menu(window, font);
    }

    void TearDown() override {
        delete menu;
        window.close();
    }
};

TEST_F(MenuTests, MenuInitialization) {
    EXPECT_NO_THROW(Menu menu(window, font));
}

TEST_F(MenuTests, DrawMenu) {
    EXPECT_NO_THROW(menu->draw());
}

TEST_F(MenuTests, GetButton) {
    Button startButton = menu->getButton(MenuValues::DEFAULT_START_BUTTON_MESSAGE);
    EXPECT_EQ(startButton.getSFMLText().getString(), MenuValues::DEFAULT_START_BUTTON_MESSAGE);

    Button exitButton = menu->getButton(MenuValues::DEFAULT_EXIT_BUTTON_MESSAGE);
    EXPECT_EQ(exitButton.getSFMLText().getString(), MenuValues::DEFAULT_EXIT_BUTTON_MESSAGE);
}

TEST_F(MenuTests, IsButtonPressed) {
    EXPECT_FALSE(menu->isButtonPressed(MenuValues::DEFAULT_START_BUTTON_MESSAGE));
    EXPECT_FALSE(menu->isButtonPressed(MenuValues::DEFAULT_EXIT_BUTTON_MESSAGE));
}

TEST_F(MenuTests, ButtonsCount) {
    std::vector<Button> buttons = menu->getButtons();
    EXPECT_EQ(buttons.size(), 2);
}

#endif  // MENU_TESTS_HPP