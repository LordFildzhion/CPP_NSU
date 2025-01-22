#ifndef MOVER_HPP
#define MOVER_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "BackgroundElement.hpp"
#include "GameSpeed.hpp"

namespace MoverValues {
    static const float DEFAULT_BACKGROUND_MOVE_SPEED   = 1.0f;
    static const float DEFAULT_BULLET_MOVE_SPEED       = 5.0f;
    static const float DEFAULT_ASTEROID_MOVE_SPEED     = 2.0f;
    static const float DEFAULT_SHIP_MOVE_SPEED         = 5.0f;
    static const float DEFAULT_GAME_SPEED              = 1.0f;
};

class Mover {
 public:
    explicit Mover(sf::RenderWindow &window);

    void moveBullet(std::vector<Bullet> &asteroids);

    void moveAsteroids(std::vector<Asteroid> &asteroids);

    void moveShip(Ship &ship, sf::Keyboard::Key key);

    void addGameSpeed(float increase);

    void moveBackground(std::vector<BackgroundElement> &elements);

 private:
    float asteroidSpeed;
    float bulletSpeed;
    float shipSpeed;
    float backgroundSpeed;

    GameSpeed *gameSpeed;

    sf::RenderWindow &window;

    bool checkLeftButtonPressed(sf::Keyboard::Key key);
    bool checkRightButtonPressed(sf::Keyboard::Key key);
    bool canShipMoveLeft(Ship &ship);
    bool canShipMoveRight(Ship &ship);
};

Mover::Mover(sf::RenderWindow &window) : window(window) {
    asteroidSpeed = MoverValues::DEFAULT_ASTEROID_MOVE_SPEED;
    bulletSpeed = MoverValues::DEFAULT_BULLET_MOVE_SPEED;
    shipSpeed = MoverValues::DEFAULT_SHIP_MOVE_SPEED;
    backgroundSpeed = MoverValues::DEFAULT_BACKGROUND_MOVE_SPEED;
    gameSpeed = GameSpeed::getInstance();
}

void Mover::moveBullet(std::vector<Bullet> &bullets) {
    for (auto &bullet : bullets) {
        bullet.move(-bulletSpeed * gameSpeed->getGameSpeed());
    }
}

void Mover::moveAsteroids(std::vector<Asteroid> &asteroids) {
    for (auto &asteroid : asteroids) {
        asteroid.move(asteroidSpeed * gameSpeed->getGameSpeed());
    }
}

void Mover::moveShip(Ship &ship, sf::Keyboard::Key key = sf::Keyboard::Key::Unknown) {
    if (canShipMoveLeft(ship) && checkLeftButtonPressed(key)) {
        ship.move(-shipSpeed * gameSpeed->getGameSpeed());
    }

    if (canShipMoveRight(ship) && checkRightButtonPressed(key)) {
        ship.move(shipSpeed * gameSpeed->getGameSpeed());
    }
}

void Mover::addGameSpeed(float increase) {
    gameSpeed->increaseGameSpeed(increase);
}

void Mover::moveBackground(std::vector<BackgroundElement> &elements) {
    for (auto &element : elements) {
        element.move(-backgroundSpeed);
    }
}

bool Mover::checkLeftButtonPressed(sf::Keyboard::Key key) {
    return key == sf::Keyboard::Key::Left || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
}

bool Mover::checkRightButtonPressed(sf::Keyboard::Key key) {
    return key == sf::Keyboard::Key::Right || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
}

bool Mover::canShipMoveLeft(Ship &ship) {
    return ship.getPosition().x > 0;
}

bool Mover::canShipMoveRight(Ship &ship) {
    return ship.getPosition().x < window.getSize().x - ship.getShape().getRadius() * 2;
}

#endif  // MOVER_HPP
