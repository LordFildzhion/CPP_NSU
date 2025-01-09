#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(sf::RenderWindow &window, const std::string &message);

    void setMessage(const std::string &message);

    void setPosition(float x, float y);

    void draw();

    bool isPressed();

    bool isHovered();

    void setFillColor(const sf::Color &color);

    void setOutlineColor(const sf::Color &color);

    void setOutlineThickness(float thickness);

    void setSize(const float size);

    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    sf::Text getText();

private:
    sf::RenderWindow &window;
    sf::Font font;
    sf::Text text;
    float size;
};

Button::Button(sf::RenderWindow &window, const std::string &message) : window(window), font("..\\rec\\fonts\\arialmt.ttf"), text(font, message) {
    size = 30;
    text.setFont(font);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);
}

void Button::setMessage(const std::string &message) {
    text.setString(message);
}

void Button::setPosition(float x, float y) {
    text.setPosition({x, y});
}

void Button::draw() {
    window.draw(text);
}

bool Button::isPressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isHovered();
}

bool Button::isHovered() {
    return text.getGlobalBounds().contains({(float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y});
}

void Button::setFillColor(const sf::Color &color) {
    text.setFillColor(color);
}

void Button::setOutlineColor(const sf::Color &color) {
    text.setOutlineColor(color);
}

void Button::setOutlineThickness(float thickness) {
    text.setOutlineThickness(thickness);
}

void Button::setSize(const float size) {
    text.setCharacterSize(size);
}

sf::Vector2f Button::getPosition() {
    return text.getPosition();
}

sf::Vector2f Button::getSize() {
    return {text.getGlobalBounds().size.x, text.getGlobalBounds().size.y};
}

sf::Text Button::getText() {
    return text;
}

#endif
