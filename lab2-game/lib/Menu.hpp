#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Button.hpp"

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
    const float LABLE_SIZE = 100.0f;
    const float START_BUTTON_SIZE = 75.0f;
    const float EXIT_BUTTON_SIZE = 75.0f;
}

class Menu {
 public:
    Menu(sf::RenderWindow &window, const std::string &fontPath);

    void draw();

    bool isStartButtonPressed();

    bool isExitButtonPressed();

 protected:
    void createButton(Button &button, const std::string &message, sf::Vector2f buttonPosition, const sf::Color &fillColor, const float size);

    void createLabel(const std::string &message, float x, float y, const sf::Color &fillColor, sf::Font font, const float size);

    sf::RenderWindow &window;
    sf::Font font;
    sf::Text lable;

    float lableSize;
    float startButtonSize;
    float exitButtonSize;

    Button startButton;
    Button exitButton;
};

Menu::Menu(sf::RenderWindow &window, const std::string &fontPath = "..\\rec\\fonts\\arialmt.ttf") :
window(window), font(fontPath), lable(font),
startButton(window, "Start"), exitButton(window, "Exit") {
    if (!font.openFromFile(fontPath)) {
        throw MenuException("ERROR!!!\nMENU::MENU:: Can't open font file\n");
    }

    lableSize = MenuValues::LABLE_SIZE;
    startButtonSize = MenuValues::START_BUTTON_SIZE;
    exitButtonSize = MenuValues::EXIT_BUTTON_SIZE;

    createLabel("Astro Shooter", window.getSize().x / 2, window.getSize().y / 2, sf::Color::Red, font, lableSize);

    sf::Vector2f lablePosition, startButtonPosition, exitButtonPosition;

    lablePosition.x = window.getSize().x / 2 - lable.getGlobalBounds().size.x / 2;
    lablePosition.y = lableSize;

    startButtonPosition.x = lablePosition.x + lable.getGlobalBounds().size.x / 3;
    startButtonPosition.y = lablePosition.y + window.getSize().y / 3;

    exitButtonPosition.x = startButtonPosition.x;
    exitButtonPosition.y = startButtonPosition.y + window.getSize().y / 7;

    lable.setPosition(lablePosition);

    createButton(startButton, "Start", startButtonPosition, sf::Color::Green, startButtonSize);

    createButton(exitButton, "Exit", exitButtonPosition, sf::Color::Blue, exitButtonSize);
}

void Menu::draw() {
    window.draw(lable);
    startButton.draw();
    exitButton.draw();
}

bool Menu::isStartButtonPressed() {
    return startButton.isPressed();
}

bool Menu::isExitButtonPressed() {
    return exitButton.isPressed();
}

void Menu::createButton(Button &button, const std::string &message, sf::Vector2f buttonPosition, const sf::Color &fillColor, const float size) {
    button.setMessage(message);
    button.setPosition(buttonPosition);
    button.setFillColor(fillColor);
    button.setSize(size);
}

void Menu::createLabel(const std::string &message, float x, float y, const sf::Color &fillColor, sf::Font font, const float size) {
    lable.setString(message);
    lable.setPosition({x, y});
    lable.setFillColor(fillColor);
    lable.setCharacterSize(size);
}

#endif  // MENU_HPP
