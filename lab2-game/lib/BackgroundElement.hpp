#ifndef BACK_GROUND_ELEMENT_HPP
#define BACK_GROUND_ELEMENT_HPP

#include <utility>

#include <SFML/Graphics.hpp>

namespace BackgroundElementValues {
    static const size_t MAX_ANGLE_COUNT    = 10;
    static const size_t MIN_ANGLE_COUNT    = 5;
    static const float MAX_RADIUS          = 7.0f;
    static const float MIN_RADIUS          = 3.0f;
    static const sf::Color DEFAULT_COLOR   = sf::Color::White;
    static const size_t SPAWN_BORDER       = 100;
}

class BackgroundElement {
 public:
    explicit BackgroundElement(sf::RenderWindow &window);

    void move(float speed);

    void setFillColor(const sf::Color &color);

    void setRadius(float radius);

    void setPointCount(size_t count);

    void setPosition(const sf::Vector2f &position);

    void setColor(const sf::Color &color);

    sf::CircleShape &getShape();

    const sf::CircleShape getShape() const;

 private:
    size_t getRandomAngleCount();

    float getRandomRadius();

    sf::Vector2f getRandomPosition(sf::RenderWindow &window);

    sf::CircleShape shape;
};

BackgroundElement::BackgroundElement(sf::RenderWindow &window) {
    shape.setFillColor(BackgroundElementValues::DEFAULT_COLOR);
    shape.setRadius(getRandomRadius());
    shape.setPointCount(getRandomAngleCount());
    shape.setPosition(getRandomPosition(window));
}

void BackgroundElement::move(float speed) {
    shape.move({speed, 0});
}

void BackgroundElement::setFillColor(const sf::Color &color) {
    shape.setFillColor(color);
}

void BackgroundElement::setRadius(float radius) {
    shape.setRadius(radius);
}

void BackgroundElement::setPointCount(size_t count) {
    shape.setPointCount(count);
}

void BackgroundElement::setPosition(const sf::Vector2f &position) {
    shape.setPosition(position);
}

void BackgroundElement::setColor(const sf::Color &color) {
    shape.setFillColor(color);
}

sf::CircleShape &BackgroundElement::getShape() {
    return shape;
}

const sf::CircleShape BackgroundElement::getShape() const {
    return shape;
}

size_t BackgroundElement::getRandomAngleCount() {
    return rand() % (BackgroundElementValues::MAX_ANGLE_COUNT - BackgroundElementValues::MIN_ANGLE_COUNT) + BackgroundElementValues::MIN_ANGLE_COUNT;
}

float BackgroundElement::getRandomRadius() {
    return static_cast<float>(rand() % static_cast<int>(BackgroundElementValues::MAX_RADIUS - BackgroundElementValues::MIN_RADIUS) + BackgroundElementValues::MIN_RADIUS);
}

sf::Vector2f BackgroundElement::getRandomPosition(sf::RenderWindow &window) {
    return sf::Vector2f(static_cast<float>(window.getSize().x + BackgroundElementValues::SPAWN_BORDER), static_cast<float>(rand() % window.getSize().y));
}

#endif  // BACK_GROUND_ELEMENT_HPP
