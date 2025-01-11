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
    const float ASTEROID_SPAWN_TIME                     = 1.0f;
    const float ASTEROID_SPAWN_TIME_DIFFERENCE          = 0.01f;
    const float BULLET_SPAWN_TIME                       = 0.25f;
    const float DEFAULT_BORDERS_ASTEROID_SPAWN_PLACE    = 25.0f;
};

namespace BackgroundSpawnerValues {
    const size_t MAX_ELEMENT_SPAWN_TIME                 = 20;
    const size_t MIN_ELEMENT_SPAWN_TIME                 = 15;
    const size_t MAX_ELEMENT_COUNT                      = 3;
    const size_t MIN_ELEMENT_COUNT                      = 1;
    const size_t SPAWN_BORDER                           = 100;
    const float GENERATION_SPEED                        = 100.0f;
};

class Spawner {
 public:
    explicit Spawner(sf::RenderWindow &window);

    Spawner() = delete;

    void spawnAsteroid(std::vector<Asteroid> &asteroids);

    void spawnBullet(Ship &ship, std::vector<Bullet> &bullets, sf::Keyboard::Key key = sf::Keyboard::Key::Unknown);

    void spawnShip(Ship &ship);

    void spawnBackgroundElements(std::vector<BackgroundElement> &elements, int32_t elementsCount = -1, int32_t backgrondElementSpawnTimeSec = -1);

    void addAsteroidSpawnTime(float increase = -SpawnerValues::ASTEROID_SPAWN_TIME_DIFFERENCE);

    float getAsteroidSpawnTime();

 protected:
    Textures *textures;

    sf::Clock asteroidClock;
    sf::Clock bulletClock;
    sf::Clock backgrondElementSpawnTime;

    float asteroidSpawnTime;
    float bulletSpawnTime;

    float bordersAsteroidSpawnPlace;

    sf::RenderWindow &window;

    float getRandomBackgroundElementSpawnTime();

    void addBackgroundElement(std::vector<BackgroundElement> &elements, int32_t backgrondElementSpawnTimeSec = -1);

    size_t getRandomBackgroundElementCount();
};

Spawner::Spawner(sf::RenderWindow &window): window(window) {
    textures = Textures::getInstance();
    bordersAsteroidSpawnPlace = SpawnerValues::DEFAULT_BORDERS_ASTEROID_SPAWN_PLACE;
    asteroidSpawnTime = SpawnerValues::ASTEROID_SPAWN_TIME;
    bulletSpawnTime = SpawnerValues::BULLET_SPAWN_TIME;
}

void Spawner::spawnAsteroid(std::vector<Asteroid> &asteroids) {
    if (asteroidClock.getElapsedTime().asSeconds() > asteroidSpawnTime || asteroids.empty()) {

        sf::Vector2f asteroidPosition;
        asteroidPosition.x = rand() % size_t(window.getSize().x - bordersAsteroidSpawnPlace - AsteroidValues::MAX_RADIUS * 2) + bordersAsteroidSpawnPlace;
        asteroidPosition.y = -bordersAsteroidSpawnPlace;

        asteroids.push_back(Asteroid(asteroidPosition));
        asteroids.back().setRandomAsteroid(textures->getAsteroidTextures().size());
        asteroids.back().setTexture(textures->getAsteroidTextures()[asteroids.back().getType() - 1]);

        asteroidClock.restart();
    }
}

void Spawner::spawnBullet(Ship &ship, std::vector<Bullet> &bullets, sf::Keyboard::Key key) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) || key == sf::Keyboard::Key::Space) {
        if (bulletClock.getElapsedTime().asSeconds() > bulletSpawnTime || bullets.empty()) {

            bullets.push_back(Bullet(ship.getPosition().x + ship.getShape().getRadius(), ship.getPosition().y));

            bullets.back().setRandomType(textures->getBulletTextures().size());
            bullets.back().setTexture(textures->getBulletTextures()[bullets.back().getType() - 1]);

            bulletClock.restart();
        }
    }
}

void Spawner::spawnShip(Ship &ship) {
    ship.setPosition(window.getSize().x / 2, window.getSize().y - ship.getShape().getRadius() * 2);
    ship.setRandomType(textures->getShipTextures().size());
    ship.setTexture(textures->getShipTextures()[ship.getType() - 1]);
}

size_t Spawner::getRandomBackgroundElementCount() {
    return rand() % (BackgroundSpawnerValues::MAX_ELEMENT_COUNT - BackgroundSpawnerValues::MIN_ELEMENT_COUNT) + BackgroundSpawnerValues::MIN_ELEMENT_COUNT;
}

float Spawner::getRandomBackgroundElementSpawnTime() {
    return ((rand() % (BackgroundSpawnerValues::MAX_ELEMENT_SPAWN_TIME - BackgroundSpawnerValues::MIN_ELEMENT_SPAWN_TIME) + BackgroundSpawnerValues::MIN_ELEMENT_SPAWN_TIME)) / BackgroundSpawnerValues::GENERATION_SPEED;
}

void Spawner::addBackgroundElement(std::vector<BackgroundElement> &elements, int32_t backgrondElementSpawnTimeSec) {
    if (backgrondElementSpawnTimeSec >= 0) {
        if (backgrondElementSpawnTime.getElapsedTime().asSeconds() >= backgrondElementSpawnTimeSec || elements.empty()) {
            elements.push_back(BackgroundElement(window));
            backgrondElementSpawnTime.restart();
        }
        return;
    }

    if (backgrondElementSpawnTime.getElapsedTime().asSeconds() >= getRandomBackgroundElementSpawnTime() || elements.empty()) {
        elements.push_back(BackgroundElement(window));
        backgrondElementSpawnTime.restart();
    }
}

void Spawner::spawnBackgroundElements(std::vector<BackgroundElement> &elements, int32_t elementsCount, int32_t backgrondElementSpawnTimeSec) {
    if (elementsCount >= 0) {
        for (size_t i = 0; i < elementsCount; i++) {
            addBackgroundElement(elements, backgrondElementSpawnTimeSec);
        }
        return;
    }

    for (size_t i = 0; i < getRandomBackgroundElementCount(); i++) {
        addBackgroundElement(elements);
    }
}

void Spawner::addAsteroidSpawnTime(float increase) {
    asteroidSpawnTime += increase;
}

float Spawner::getAsteroidSpawnTime() {
    return asteroidSpawnTime;
}

#endif  // SPAWNER_HPP
