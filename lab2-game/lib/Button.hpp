#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(sf::RenderWindow &window, const std::string &message) : window(window), font("D:\\Progs\\CC++\\CPP_NSU\\lab2-game\\rec\\arialmt.ttf"), text(font, message) {
        size = 30;
        text.setFont(font);
        text.setCharacterSize(size);
        text.setFillColor(sf::Color::White);
    }

    void setMessage(const std::string &message) {
        text.setString(message);
    }

    void setFont(const std::string &fontPath) {
        if (!font.openFromFile(fontPath)) {
            throw std::runtime_error("Can't load font from file");
        }
        text.setFont(font);
    }

    void setPosition(float x, float y) {
        text.setPosition({x, y});
    }

    void draw() {
        window.draw(text);
    }

    bool isPressed() {
        return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isHovered();
    }

    bool isHovered() {
        return text.getGlobalBounds().contains({(float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y});
    }

    void setFillColor(const sf::Color &color) {
        text.setFillColor(color);
    }

    void setOutlineColor(const sf::Color &color) {
        text.setOutlineColor(color);
    }

    void setOutlineThickness(float thickness) {
        text.setOutlineThickness(thickness);
    }

    void setSize(const float size) {
        text.setCharacterSize(size);
    }

    sf::Vector2f getPosition() {
        return text.getPosition();
    }

    sf::Vector2f getSize() {
        return {text.getGlobalBounds().size.x, text.getGlobalBounds().size.y};
    }

    sf::Text getText() {
        return text;
    }

private:
    sf::RenderWindow &window;
    sf::Font font;
    sf::Text text;
    float size;
};

#endif
