#ifndef MOVER_HPP
#define MOVER_HPP

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"

class Mover {
public:
    Mover(
        sf::RenderWindow &window,
        std::vector<Asteroid> &asteroids,
        std::vector<Bullet> &bullets, Ship &ship,
        float &gameSpeed
    );

    void moveBullet();

    void moveAsteroids();

    void moveShip(sf::Keyboard::Key key);

    void addGameSpeed(float increase);

private:
    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    Ship &ship;

    float asteroidSpeed;
    float bulletSpeed;
    float shipSpeed;
    float &gameSpeed;

    sf::RenderWindow &window;
};

Mover::Mover(
    sf::RenderWindow &window,
    std::vector<Asteroid> &asteroids,
    std::vector<Bullet> &bullets, Ship &ship,
    float &gameSpeed
) : window(window), asteroids(asteroids), bullets(bullets), ship(ship), gameSpeed(gameSpeed) {
    asteroidSpeed = 2.0f;
    bulletSpeed = 5.0f;
    shipSpeed = 5.0f;
}

void Mover::moveBullet() {
    for (auto &bullet : bullets) {
        bullet.move(-bulletSpeed * gameSpeed);
    }
}

void Mover::moveAsteroids() {
    for (auto &asteroid : asteroids) {
        asteroid.move(asteroidSpeed * gameSpeed);
    }
}

void Mover::moveShip(sf::Keyboard::Key key = sf::Keyboard::Key::Unknown) {
    size_t shipMoveBordersLeft = 0;
    size_t shipMoveBordersRight = window.getSize().x - ship.getShape().getRadius() * 2;

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || key == sf::Keyboard::Key::Left)
    && ship.getPosition().x > shipMoveBordersLeft) {
        ship.move(-shipSpeed * gameSpeed);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || key == sf::Keyboard::Key::Right)
    && ship.getPosition().x < shipMoveBordersRight) {
        ship.move(shipSpeed * gameSpeed);
    }
}

void Mover::addGameSpeed(float increase) {
    gameSpeed += increase;
}

#endif // MOVER_HPP
