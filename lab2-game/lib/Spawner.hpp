#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Textures.hpp"


class Spawner {
public:
    Spawner(
        sf::RenderWindow &window, Textures &textures,
        std::vector<Asteroid> &asteroids,
        std::vector<Bullet> &bullets, Ship &ship
    ):
    window(window), textures(textures), asteroids(asteroids), bullets(bullets),
    ship(ship),asteroidClock(asteroidClock), bulletClock(bulletClock),
    asteroidSpawnTime(asteroidSpawnTime), bulletSpawnTime(bulletSpawnTime){
        bordersAsteroidSpawnPlace = 100.0f;
        asteroidSpawnTime = 1.0f;
        bulletSpawnTime = 0.25f;
    }

    void spawnAsteroid() {
        if (asteroidClock.getElapsedTime().asSeconds() > asteroidSpawnTime) {
            asteroids.push_back(Asteroid(rand() % size_t(window.getSize().x - bordersAsteroidSpawnPlace) + bordersAsteroidSpawnPlace, -bordersAsteroidSpawnPlace));
            asteroids.back().setRandomSpeed();
            asteroids.back().setRandomRadius();
            asteroids.back().setRandomType();
            asteroids.back().setTexture(textures.getAsteroidTextures()[asteroids.back().getType() - 1]);
            asteroidClock.restart();
        }
    }

    void spawnBullet() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            if (bulletClock.getElapsedTime().asSeconds() > bulletSpawnTime) {
                bullets.push_back(Bullet(textures.getBulletTexture(), ship.getPosition().x + ship.getShape().getRadius(), ship.getPosition().y));
                bulletClock.restart();
            }
        }
    }

    void spawnShip() {
        ship.setPosition(window.getSize().x / 2, window.getSize().y - ship.getShape().getRadius() * 2);
        ship.setRandomType();
        ship.setTexture(textures.getShipTextures()[ship.getType() - 1]);
    }

    void addAsteroidSpawnTime(float increase) {
        asteroidSpawnTime += increase;
    }

    void addBulletSpawnTime(float increase) {
        bulletSpawnTime += increase;
    }

private:

    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    Ship &ship;

    Textures &textures;

    sf::Clock asteroidClock;
    sf::Clock bulletClock;

    float asteroidSpawnTime;
    float bulletSpawnTime;

    float bordersAsteroidSpawnPlace;

    sf::RenderWindow &window;
};

#endif // SPAWNER_HPP
