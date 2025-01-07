#ifndef MOVER_HPP
#define MOVER_HPP

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Textures.hpp"

class Mover {
public:
    Mover(
        sf::RenderWindow &window, Textures &textures,
        std::vector<Asteroid> &asteroids,
        std::vector<Bullet> &bullets, Ship &ship,
        float &asteroidSpeed, sf::Clock &bulletClock,
        float &bulletSpeed, float &shipSpeed,
        float &gameSpeed, float &asteroidSpawnTime,
        float &bulletSpawnTime, float &gameSpeedParametr
    ):
    window(window), textures(textures), asteroids(asteroids), bullets(bullets), ship(ship),
    asteroidSpeed(asteroidSpeed), bulletClock(bulletClock),
    bulletSpeed(bulletSpeed), shipSpeed(shipSpeed),
    gameSpeed(gameSpeed), asteroidSpawnTime(asteroidSpawnTime),
    bulletSpawnTime(bulletSpawnTime), gameSpeedParametr(gameSpeedParametr) {}

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
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)
        && ship.getPosition().x > 0) {
            ship.move(-shipSpeed * gameSpeed);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)
        && ship.getPosition().x < window.getSize().x - ship.getShape().getRadius() * 2) {
            ship.move(shipSpeed * gameSpeed);
        }
    }

private:
    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    Ship &ship;

    Textures &textures;

    sf::Clock &bulletClock;

    float &asteroidSpeed;
    float &bulletSpeed;
    float &shipSpeed;
    float &gameSpeed;
    float &asteroidSpawnTime;
    float &bulletSpawnTime;
    float &gameSpeedParametr;

    sf::RenderWindow &window;
};

#endif // MOVER_HPP
