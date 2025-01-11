#ifndef BULLET_HPP
#define BULLET_HPP

#include <utility>

#include <SFML/Graphics.hpp>

namespace BulletValues {
    const size_t BULLET_SCATTER         = 10;
    const float BULLET_RADIUS           = 10.0f;
    const size_t BULLET_COUNT_ANGLE     = 5;
    const size_t BULLET_TYPE_DEFAULT    = 1;
    const int8_t BULLET_SCATTER_DEFAULT = -1;
};

class Bullet {
 public:
    Bullet(float x, float y, size_t typeOther = BulletValues::BULLET_TYPE_DEFAULT, int8_t scatterOther = BulletValues::BULLET_SCATTER_DEFAULT);

    Bullet(sf::Vector2f position, size_t typeOther = BulletValues::BULLET_TYPE_DEFAULT, int8_t scatterOther = BulletValues::BULLET_SCATTER_DEFAULT);

    void move(float distanceY);

    sf::CircleShape getShape();

    const sf::CircleShape& getShape() const;

    sf::Vector2f getPosition();

    sf::Vector2f getPositionWithoutScatter();

    void setPosition(float x, float y);

    void setTexture(const sf::Texture &textureOther);

    void setScatter(int8_t scatterOther);

    int8_t getScatter();

    void setType(size_t type);

    size_t getType();

    void setRandomType(size_t typesCount);

 private:
    sf::CircleShape shape;
    int8_t scatter;
    size_t type;
};

Bullet::Bullet(float x, float y, size_t typeOther, int8_t scatterOther) : shape(BulletValues::BULLET_RADIUS, BulletValues::BULLET_COUNT_ANGLE) {
    if (scatterOther < 0) {
        scatterOther = (rand() % BulletValues::BULLET_SCATTER) - (rand() % BulletValues::BULLET_SCATTER);
    }

    this->type = typeOther;
    this->scatter = scatterOther;
    shape.setPosition({x + scatter, y});
}

Bullet::Bullet(sf::Vector2f position, size_t typeOther, int8_t scatterOther) : shape(BulletValues::BULLET_RADIUS, BulletValues::BULLET_COUNT_ANGLE) {
    if (scatterOther < 0) {
        scatterOther = (rand() % BulletValues::BULLET_SCATTER) - (rand() % BulletValues::BULLET_SCATTER);
    }

    this->type = typeOther;
    this->scatter = scatterOther;
    shape.setPosition({position.x + scatter, position.y});
}

void Bullet::move(float distanceY) {
    shape.move({0, distanceY});
}

sf::CircleShape Bullet::getShape() {
    return shape;
}

const sf::CircleShape& Bullet::getShape() const {
    return shape;
}

sf::Vector2f Bullet::getPosition() {
    return shape.getPosition();
}

sf::Vector2f Bullet::getPositionWithoutScatter() {
    return {shape.getPosition().x - scatter, shape.getPosition().y};
}

void Bullet::setPosition(float x, float y) {
    shape.setPosition({x, y});
}

void Bullet::setTexture(const sf::Texture &texture) {
    shape.setTexture(&texture);
}

void Bullet::setScatter(int8_t scatterOther) {
    shape.setPosition({shape.getPosition().x - scatter + scatterOther, shape.getPosition().y});
    this->scatter = scatterOther;
}

int8_t Bullet::getScatter() {
    return scatter;
}

void Bullet::setType(size_t type) {
    this->type = type;
}

size_t Bullet::getType() {
    return type;
}

void Bullet::setRandomType(size_t typesCount) {
    type = rand() % typesCount + 1;
}

#endif  // BULLET_HPP
