#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Button.hpp"
#include "ResoursesLoader.hpp"
#include "Text.hpp"
#include "Fonts.hpp"

class MenuException : public std::exception {
 public:
    explicit MenuException(const std::string &message) : message(message) {}

    const char *what() const noexcept override;

 private:
    std::string message;
};

const char* MenuException::what() const noexcept {
    return message.c_str();
}

namespace MenuValues {
    const float LABLE_SIZE                          = 100.0f;
    const float START_BUTTON_SIZE                   = 75.0f;
    const float EXIT_BUTTON_SIZE                    = 75.0f;
    const sf::Color DEFAULT_LABLE_COLOR             = sf::Color::Red;
    const sf::Vector2f DEFAULT_LABLE_POSITION       = {0, 0};
    const sf::Color DEFAULT_BUTTON_COLOR            = sf::Color::White;
    const sf::Vector2f DEFAULT_BUTTON_POSITION      = {0, 0};
    const std::string DEFAULT_LABLE_MESSAGE         = "Astro Shooter";
    const std::string DEFAULT_START_BUTTON_MESSAGE  = "Start";
    const std::string DEFAULT_EXIT_BUTTON_MESSAGE   = "Exit";
    const size_t DEFAULT_BUTTONS_GAP                = 50;
    const size_t DEFAULT_BUTTONS_AND_LABLE_GAP      = 50;
}

class Menu {
 public:
    Menu(sf::RenderWindow &window, sf::Font &font);

    void draw();

    Button getButton(const std::string &buttonMessage);

    std::vector<Button> getButtons() const;

    bool isButtonPressed(const std::string &buttonMessage);

 protected:
    void createButton(const std::string &message, sf::Vector2f buttonPosition, const sf::Color &fillColor, const float size);

    void createLabel(const std::string &message, float x, float y, const sf::Color &fillColor, sf::Font font, const float size);

    sf::RenderWindow &window;
    sf::Font font;
    Text lable;

    std::unordered_map<std::string, size_t> buttonsID;

    std::vector<Button> buttons;

 private:
    sf::Vector2f calculateLablePosition(Text &lable);

    sf::Vector2f calculateButtonPosition(std::string buttonMessage);

    void createStartButton();

    void createExitButton();
};

Menu::Menu(sf::RenderWindow &window, sf::Font &font): window(window), font(font) {
    createLabel(MenuValues::DEFAULT_LABLE_MESSAGE, window.getSize().x / 2, window.getSize().y / 2, MenuValues::DEFAULT_LABLE_COLOR, font, MenuValues::LABLE_SIZE);

    lable.setPosition(calculateLablePosition(lable));

    createStartButton();

    createExitButton();

    if (buttons.empty()) {
        throw MenuException("ERROR!!!\nMENU::CALCULATEBUTTONPOSITION:Buttons vector is empty\n");
    }

    if (buttons.size() == 1) {
        throw MenuException("ERROR!!!\nMENU::CALCULATEBUTTONPOSITION:Buttons vector has only one button\n");
    }
}

void Menu::createStartButton() {
    createButton(MenuValues::DEFAULT_START_BUTTON_MESSAGE, MenuValues::DEFAULT_BUTTON_POSITION, sf::Color::Green, MenuValues::START_BUTTON_SIZE);

    buttons.back().setPosition(calculateButtonPosition(MenuValues::DEFAULT_START_BUTTON_MESSAGE));
}

void Menu::createExitButton() {
    createButton(MenuValues::DEFAULT_EXIT_BUTTON_MESSAGE, MenuValues::DEFAULT_BUTTON_POSITION, sf::Color::Blue, MenuValues::EXIT_BUTTON_SIZE);

    buttons.back().setPosition(calculateButtonPosition(MenuValues::DEFAULT_EXIT_BUTTON_MESSAGE));
}

void Menu::draw() {
    lable.draw(window);   
    for (auto &button : buttons) {
        button.draw();
    }
}

Button Menu::getButton(const std::string &buttonMessage) {
    return buttons.at(buttonsID.at(buttonMessage) - 1);
}

std::vector<Button> Menu::getButtons() const {
    return buttons;
}

bool Menu::isButtonPressed(const std::string &buttonMessage) {
    return getButton(buttonMessage).isPressed();
}

void Menu::createButton(const std::string &message, sf::Vector2f buttonPosition, const sf::Color &fillColor, const float size) {
    Button button(window, message, font, buttonPosition, fillColor, size);

    buttonsID[message] = buttons.size() + 1;

    buttons.push_back(button);
}

void Menu::createLabel(const std::string &message, float x, float y, const sf::Color &fillColor, sf::Font font, const float size) {
    lable = Text(message, {x, y}, fillColor, font, size);
}

sf::Vector2f Menu::calculateLablePosition(Text &lable) {
    sf::Vector2f lablePosition;

    lablePosition.x = window.getSize().x / 2 - lable.getGlobalBounds().size.x / 2;
    lablePosition.y = window.getSize().y / 4;

    return lablePosition;
}

sf::Vector2f Menu::calculateButtonPosition(std::string buttonMessage) {
    if (buttonMessage == "Start") {
        return sf::Vector2f(lable.getPosition().x + lable.getGlobalBounds().size.x / 3, lable.getPosition().y + MenuValues::DEFAULT_BUTTONS_AND_LABLE_GAP + lable.getGlobalBounds().size.y);
    }

    return sf::Vector2f(lable.getPosition().x + lable.getGlobalBounds().size.x / 3,  buttons.at(buttonsID.at(buttonMessage) - 2).getPosition().y + MenuValues::DEFAULT_BUTTONS_GAP + buttons.at(buttonsID.at(buttonMessage) - 2).getSize().y);
}

#endif  // MENU_HPP
