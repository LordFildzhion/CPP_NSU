#ifndef TEXT_HPP
#define TEXT_HPP

#include <string>

#include <SFML/Graphics.hpp>

class Text {
 public:
    Text();

    Text(const std::string &message, const sf::Vector2f &position, const sf::Color &fillColor, const sf::Font &font, const float size);

    void draw(sf::RenderWindow &window);

    void setMessage(const std::string &message);

    void setPosition(const sf::Vector2f &position);

    void setFillColor(const sf::Color &fillColor);

    void setFont(const sf::Font &font);

    void setSize(const float size);

    std::string getMessage() const;

    sf::Vector2f getPosition() const;

    sf::Color getFillColor() const;

    sf::Font getFont() const;

    float getSize() const;

    sf::FloatRect getGlobalBounds() const;

    sf::Text getText() const;

 private:
    std::string message;
    sf::Vector2f position;
    sf::Color fillColor;
    sf::Font font;
    float size;
};

Text::Text() : message(""), position(sf::Vector2f(0, 0)), fillColor(sf::Color::White), font(), size(0) {}

Text::Text(const std::string &message, const sf::Vector2f &position, const sf::Color &fillColor, const sf::Font &font, const float size) :
    message(message), position(position), fillColor(fillColor), font(font), size(size) {}

void Text::draw(sf::RenderWindow &window) {
    sf::Text text(font, message, size);
    text.setPosition(position);
    text.setFillColor(fillColor);

    window.draw(text);
}

void Text::setMessage(const std::string &message) {
    this->message = message;
}

void Text::setPosition(const sf::Vector2f &position) {
    this->position = position;
}

void Text::setFillColor(const sf::Color &fillColor) {
    this->fillColor = fillColor;
}

void Text::setFont(const sf::Font &font) {
    this->font = font;
}

void Text::setSize(const float size) {
    this->size = size;
}

std::string Text::getMessage() const {
    return message;
}

sf::Vector2f Text::getPosition() const {
    return position;
}

sf::Color Text::getFillColor() const {
    return fillColor;
}

sf::Font Text::getFont() const {
    return font;
}

float Text::getSize() const {
    return size;
}

sf::FloatRect Text::getGlobalBounds() const {
    sf::Text text(font, message, size);
    text.setPosition(position);
    text.setFillColor(fillColor);

    return text.getGlobalBounds();
}

sf::Text Text::getText() const {
    sf::Text text(font, message, size);
    text.setPosition(position);
    text.setFillColor(fillColor);

    return text;
}

#endif  // TEXT_HPP
