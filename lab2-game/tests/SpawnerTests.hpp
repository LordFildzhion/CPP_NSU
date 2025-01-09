#include <vector>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "Spawner.hpp"
#include "Textures.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"

class TestSpawner: public Spawner {
 public:
    TestSpawner(
        sf::RenderWindow &window,
        std::vector<Asteroid> &asteroids,
        std::vector<Bullet> &bullets,
        Ship &ship):
    Spawner(window, asteroids, bullets, ship) {}

    void setAsteroids(std::vector<Asteroid> &asteroids) {
        this->asteroids = asteroids;
    }

    void setBullets(std::vector<Bullet> &bullets) {
        this->bullets = bullets;
    }

    void setShip(Ship &ship) {
        this->ship = ship;
    }

    float getAsteroidSpawnTime() {
        return asteroidSpawnTime;
    }

    float getBulletSpawnTime() {
        return bulletSpawnTime;
    }

    float getBordersAsteroidSpawnPlace() {
        return bordersAsteroidSpawnPlace;
    }

    void setAsteroidSpawnTime(float time) {
        asteroidSpawnTime = time;
    }

    void setBulletSpawnTime(float time) {
        bulletSpawnTime = time;
    }

    void setBordersAsteroidSpawnPlace(float place) {
        bordersAsteroidSpawnPlace = place;
    }

    void addAsteroidSpawnTime(float increase) {
        asteroidSpawnTime += increase;
    }

    void addBulletSpawnTime(float increase) {
        bulletSpawnTime += increase;
    }

    using Spawner::spawnAsteroid;

    using Spawner::spawnShip;

    using Spawner::spawnBullet;
};

TEST(SpawnerTest, SpawnAsteroid) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    TestSpawner spawner(window, asteroids, bullets, ship);

    size_t initialSize = asteroids.size();
    spawner.spawnAsteroid();
    EXPECT_EQ(asteroids.size(), initialSize + 1);
}

TEST(SpawnerTest, SpawnBullet) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    TestSpawner spawner(window, asteroids, bullets, ship);

    size_t initialSize = bullets.size();
    spawner.spawnBullet(sf::Keyboard::Key::Space);
    EXPECT_EQ(bullets.size(), initialSize + 1);
}

TEST(SpawnerTest, SpawnShip) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    TestSpawner spawner(window, asteroids, bullets, ship);
    EXPECT_NO_THROW(spawner.spawnShip());
}

TEST(SpawnerTest, AddAsteroidSpawnTime) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    TestSpawner spawner(window, asteroids, bullets, ship);

    float initialSpawnTime = spawner.getAsteroidSpawnTime();
    spawner.addAsteroidSpawnTime(0.5f);
    EXPECT_EQ(spawner.getAsteroidSpawnTime(), initialSpawnTime + 0.5f);
}

TEST(SpawnerTest, AddBulletSpawnTime) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    TestSpawner spawner(window, asteroids, bullets, ship);

    float initialSpawnTime = spawner.getBulletSpawnTime();
    spawner.addBulletSpawnTime(0.5f);
    EXPECT_EQ(spawner.getBulletSpawnTime(), initialSpawnTime + 0.5f);
}

TEST(SpawnerTest, BordersAsteroidSpawnPlace) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    TestSpawner spawner(window, asteroids, bullets, ship);

    EXPECT_EQ(spawner.getBordersAsteroidSpawnPlace(), SpawnerValues::DEFAULT_BORDERS_ASTEROID_SPAWN_PLACE);
}
