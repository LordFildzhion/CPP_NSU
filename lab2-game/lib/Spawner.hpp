#ifndef SPAWNER_HPP
#define SPAWNER_HPP

#include <vector>
#include <utility>

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Textures.hpp"

namespace SpawnerValues {
    const float ASTEROID_SPAWN_TIME = 1.0f;
    const float BULLET_SPAWN_TIME = 0.25f;
    const float DEFAULT_BORDERS_ASTEROID_SPAWN_PLACE = 25.0f;
};

class Spawner {
public:
    Spawner(
        sf::RenderWindow &window,
        std::vector<Asteroid> &asteroids,
        std::vector<Bullet> &bullets,
        Ship &ship
    );

    Spawner() = delete;

    void setAsteroids(std::vector<Asteroid> &asteroids) {
        this->asteroids = asteroids;
    }

    void setBullets(std::vector<Bullet> &bullets) {
        this->bullets = bullets;
    }

    void setShip(Ship &ship) {
        this->ship = ship;
    }

    void spawnAsteroid();

    void spawnBullet(sf::Keyboard::Key key = sf::Keyboard::Key::Unknown);

    void spawnShip();

    void addAsteroidSpawnTime(float increase);

    void addBulletSpawnTime(float increase);

protected:
    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    Ship &ship;

    Textures textures;

    sf::Clock asteroidClock;
    sf::Clock bulletClock;

    float asteroidSpawnTime;
    float bulletSpawnTime;

    float bordersAsteroidSpawnPlace;

    sf::RenderWindow &window;
};

Spawner::Spawner(
    sf::RenderWindow &window,
    std::vector<Asteroid> &asteroids,
    std::vector<Bullet> &bullets,
    Ship &ship
):
window(window), asteroids(asteroids), bullets(bullets), ship(ship) {
    bordersAsteroidSpawnPlace = SpawnerValues::DEFAULT_BORDERS_ASTEROID_SPAWN_PLACE;
    asteroidSpawnTime = SpawnerValues::ASTEROID_SPAWN_TIME;
    bulletSpawnTime = SpawnerValues::BULLET_SPAWN_TIME;
}

void Spawner::spawnAsteroid() {
    if (asteroidClock.getElapsedTime().asSeconds() > asteroidSpawnTime || asteroids.empty()) {
        sf::Vector2f asteroidPosition;
        asteroidPosition.x = rand() % size_t(window.getSize().x - bordersAsteroidSpawnPlace - AsteroidValues::MAX_RADIUS * 2) + bordersAsteroidSpawnPlace;
        asteroidPosition.y = -bordersAsteroidSpawnPlace;

        asteroids.push_back(Asteroid(asteroidPosition));
        asteroids.back().setRandomAsteroid(textures.getAsteroidTextures().size());
        asteroids.back().setTexture(textures.getAsteroidTextures()[asteroids.back().getType() - 1]);

        asteroidClock.restart();
    }
}

void Spawner::spawnBullet(sf::Keyboard::Key key) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || key == sf::Keyboard::Key::Space) {
        if (bulletClock.getElapsedTime().asSeconds() > bulletSpawnTime || bullets.empty()) {
            bullets.push_back(Bullet(ship.getPosition().x + ship.getShape().getRadius(), ship.getPosition().y));

            bullets.back().setRandomType(textures.getBulletTextures().size());
            bullets.back().setTexture(textures.getBulletTextures()[bullets.back().getType() - 1]);

            bulletClock.restart();
        }
    }
}

void Spawner::spawnShip() {
    ship.setPosition(window.getSize().x / 2, window.getSize().y - ship.getShape().getRadius() * 2);
    ship.setRandomType(textures.getShipTextures().size());
    ship.setTexture(textures.getShipTextures()[ship.getType() - 1]);
}

void Spawner::addAsteroidSpawnTime(float increase) {
    asteroidSpawnTime += increase;
}

void Spawner::addBulletSpawnTime(float increase) {
    bulletSpawnTime += increase;
}

#endif  // SPAWNER_HPP
