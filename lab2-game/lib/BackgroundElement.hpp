#ifndef BACK_GROUND_ELEMENT_HPP
#define BACK_GROUND_ELEMENT_HPP

#include <utility>

#include <SFML/Graphics.hpp>

namespace BackGroundElementValues {
    const size_t MAX_ANGLE_COUNT = 10;
    const size_t MIN_ANGLE_COUNT = 5;
    const float MAX_RADIUS = 7.0f;
    const float MIN_RADIUS = 3.0f;
    const sf::Color DEFAULT_COLOR = sf::Color::White;
    const size_t SPAWN_BORDER = 100;
}

class BackGroundElement {
 public:
    explicit BackGroundElement(sf::RenderWindow &window);

    void move(float speed);

    void setFillColor(const sf::Color &color);

    void setRadius(float radius);

    void setPointCount(size_t count);

    void setPosition(const sf::Vector2f &position);

    sf::CircleShape &getShape();

    const sf::CircleShape getShape() const;

 private:
    size_t getRandomAngleCount();

    float getRandomRadius();

    sf::Vector2f getRandomPosition(sf::RenderWindow &window);

    sf::CircleShape shape;
};

BackGroundElement::BackGroundElement(sf::RenderWindow &window) {
    shape.setFillColor(BackGroundElementValues::DEFAULT_COLOR);
    shape.setRadius(getRandomRadius());
    shape.setPointCount(getRandomAngleCount());
    shape.setPosition(getRandomPosition(window));
}

void BackGroundElement::move(float speed) {
    shape.move({speed, 0});
}

void BackGroundElement::setFillColor(const sf::Color &color) {
    shape.setFillColor(color);
}

void BackGroundElement::setRadius(float radius) {
    shape.setRadius(radius);
}

void BackGroundElement::setPointCount(size_t count) {
    shape.setPointCount(count);
}

void BackGroundElement::setPosition(const sf::Vector2f &position) {
    shape.setPosition(position);
}

sf::CircleShape &BackGroundElement::getShape() {
    return shape;
}

const sf::CircleShape BackGroundElement::getShape() const {
    return shape;
}

size_t BackGroundElement::getRandomAngleCount() {
    return rand() % (BackGroundElementValues::MAX_ANGLE_COUNT - BackGroundElementValues::MIN_ANGLE_COUNT) + BackGroundElementValues::MIN_ANGLE_COUNT;
}

float BackGroundElement::getRandomRadius() {
    return static_cast<float>(rand() % static_cast<int>(BackGroundElementValues::MAX_RADIUS - BackGroundElementValues::MIN_RADIUS) + BackGroundElementValues::MIN_RADIUS);
}

sf::Vector2f BackGroundElement::getRandomPosition(sf::RenderWindow &window) {
    return sf::Vector2f(static_cast<float>(window.getSize().x + BackGroundElementValues::SPAWN_BORDER), static_cast<float>(rand() % window.getSize().y));
}

#endif  // BACK_GROUND_ELEMENT_HPP
