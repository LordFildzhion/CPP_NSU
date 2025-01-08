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
    );

    void spawnAsteroid();

    void spawnBullet();

    void spawnShip();

    void addAsteroidSpawnTime(float increase);

    void addBulletSpawnTime(float increase);

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

Spawner::Spawner(
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

void Spawner::spawnAsteroid() {
    if (asteroidClock.getElapsedTime().asSeconds() > asteroidSpawnTime) {
        std::pair <float, float> asteroidPosition;
        asteroidPosition.first = rand() % size_t(window.getSize().x - bordersAsteroidSpawnPlace) + bordersAsteroidSpawnPlace;
        asteroidPosition.second = -bordersAsteroidSpawnPlace;

        asteroids.push_back(Asteroid(asteroidPosition.first, asteroidPosition.second));
        asteroids.back().setRandomAsteroid();
        asteroids.back().setTexture(textures.getAsteroidTextures()[asteroids.back().getType() - 1]);

        asteroidClock.restart();
    }
}

void Spawner::spawnBullet() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        if (bulletClock.getElapsedTime().asSeconds() > bulletSpawnTime) {
            bullets.push_back(Bullet(textures.getBulletTexture(), ship.getPosition().x + ship.getShape().getRadius(), ship.getPosition().y));
            bulletClock.restart();
        }
    }
}

void Spawner::spawnShip() {
    ship.setPosition(window.getSize().x / 2, window.getSize().y - ship.getShape().getRadius() * 2);
    ship.setRandomType();
    ship.setTexture(textures.getShipTextures()[ship.getType() - 1]);
}

void Spawner::addAsteroidSpawnTime(float increase) {
    asteroidSpawnTime += increase;
}

void Spawner::addBulletSpawnTime(float increase) {
    bulletSpawnTime += increase;
}

#endif // SPAWNER_HPP
