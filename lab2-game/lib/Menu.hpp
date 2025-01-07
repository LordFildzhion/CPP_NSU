#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Button.hpp"

class Menu {
public:
    Menu(sf::RenderWindow &window):
    window(window), font("D:\\Progs\\CC++\\CPP_NSU\\lab2-game\\rec\\arialmt.ttf"),
    lable(font), startButton(window, "Start"), exitButton(window, "Exit") {

        if (!font.openFromFile("D:\\Progs\\CC++\\CPP_NSU\\lab2-game\\rec\\arialmt.ttf")) {
            throw std::runtime_error("Can't load font from file");
        }

        lableSize = 100.0f;
        startButtonSize = 75.0f;
        exitButtonSize = 75.0f;

        createLabel("Astro Shooter", window.getSize().x / 2, window.getSize().y / 2, sf::Color::Red, font, lableSize);
        lable.setPosition({window.getSize().x / 2 - lable.getGlobalBounds().size.x / 2, 100.0f});

        createButton(startButton, "Start", lable.getPosition().x + lable.getGlobalBounds().size.x / 3, lable.getPosition().y + window.getSize().y / 3, sf::Color::Transparent, sf::Color::Green, 2, startButtonSize);

        createButton(exitButton, "Exit", startButton.getPosition().x, startButton.getPosition().y + window.getSize().y / 7, sf::Color::Transparent, sf::Color::Blue, 2, exitButtonSize);
    }

    void draw() {
        window.draw(lable);
        startButton.draw();
        exitButton.draw();
    }

    bool isStartButtonPressed() {
        return startButton.isPressed();
    }

    bool isExitButtonPressed() {
        return exitButton.isPressed();
    }

private:

    void createButton(Button &button, const std::string &message, float x, float y, const sf::Color &fillColor, const sf::Color &outlineColor, float outlineThickness, const float size) {
        button.setMessage(message);
        button.setPosition(x, y);
        button.setFillColor(fillColor);
        button.setOutlineColor(outlineColor);
        button.setOutlineThickness(outlineThickness);
        button.setSize(size);
    }

    void createLabel(const std::string &message, float x, float y, const sf::Color &fillColor, sf::Font font, const float size) {
        lable.setString(message);
        lable.setPosition({x, y});
        lable.setFillColor(fillColor);
        lable.setCharacterSize(size);
    }

    sf::RenderWindow &window;
    sf::Font font;
    sf::Text lable;

    float lableSize;
    float startButtonSize;
    float exitButtonSize;

    Button startButton;
    Button exitButton;
};

#endif
