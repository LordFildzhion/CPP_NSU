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
    ):
    window(window), asteroids(asteroids), bullets(bullets), ship(ship),
    gameSpeed(gameSpeed) {
        shipSpeed = 5.0f;
        bulletSpeed = 5.0f;
        asteroidSpeed = 2.0f;
    }

    void moveBullet() {
        for (auto &bullet : bullets) {
            bullet.move(-bulletSpeed * gameSpeed);
        }
    }

    void moveAsteroids() {
        for (auto &asteroid : asteroids) {
            asteroid.move(asteroidSpeed * gameSpeed);
        }
    }

    void moveShip() {
        size_t shipMoveBordersLeft = 0;
        size_t shipMoveBordersRight = window.getSize().x - ship.getShape().getRadius() * 2;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
        && ship.getPosition().x > shipMoveBordersLeft) {
            ship.move(-shipSpeed * gameSpeed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
        && ship.getPosition().x < shipMoveBordersRight) {
            ship.move(shipSpeed * gameSpeed);
        }
    }

    void addGameSpeed(float increase) {
        gameSpeed += increase;
    }

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

#endif // MOVER_HPP
