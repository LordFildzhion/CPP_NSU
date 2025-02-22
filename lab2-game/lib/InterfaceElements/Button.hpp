#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "Text.hpp"

namespace ButtonValues {
    static const sf::Color DEFAULT_COLOR       = sf::Color::White;
    static const float DEFAULT_SIZE            = 30.0f;
    static const sf::Vector2f DEFAULT_POSITION = {0, 0};
}

class Button {
 public:
    Button(sf::RenderWindow &window, const std::string &message, sf::Font font);

    Button(sf::RenderWindow &window, const std::string &message, sf::Font font, sf::Vector2f position, sf::Color fillColor, float size);

    Button(const Button &button) = default;

    Button &operator=(const Button &button) = default;

    void setMessage(const std::string &message);

    void setPosition(sf::Vector2f position);

    void draw();

    bool isPressed();

    bool isHovered();

    void setFillColor(const sf::Color &color);

    void setSize(const float size);

    sf::Vector2f getPosition();

    sf::Vector2f getSize();

    sf::Text getSFMLText() const;


 private:
    sf::RenderWindow &window;
    Text text;
};

Button::Button(sf::RenderWindow &window, const std::string &message, sf::Font font) : window(window) {
    text = Text(message, ButtonValues::DEFAULT_POSITION, ButtonValues::DEFAULT_COLOR, font, ButtonValues::DEFAULT_SIZE);
}

Button::Button(sf::RenderWindow &window, const std::string &message, sf::Font font, sf::Vector2f position, sf::Color fillColor, float size) : window(window) {
    text = Text(message, position, fillColor, font, size);
}

void Button::setMessage(const std::string &message) {
    text.setMessage(message);
}

void Button::setPosition(sf::Vector2f position) {
    text.setPosition(position);
}

void Button::draw() {
    text.draw(window);
}

bool Button::isPressed() {
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isHovered();
}

bool Button::isHovered() {
    return text.getGlobalBounds().contains({static_cast<float>(sf::Mouse::getPosition(window).x), static_cast<float>(sf::Mouse::getPosition(window).y)});
}

void Button::setFillColor(const sf::Color &color) {
    text.setFillColor(color);
}

void Button::setSize(const float size) {
    text.setSize(size);
}

sf::Vector2f Button::getPosition() {
    return text.getPosition();
}

sf::Vector2f Button::getSize() {
    return {text.getGlobalBounds().size.x, text.getGlobalBounds().size.y};
}

sf::Text Button::getSFMLText() const {
    return text.getText();
}

#endif  // BUTTON_HPP
