#ifndef SPAWNER_TESTS_HPP
#define SPAWNER_TESTS_HPP

#include <vector>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "Spawner.hpp"

class SpawnerTests : public ::testing::Test {
protected:
    sf::RenderWindow window;
    Spawner* spawner;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        spawner = new Spawner(window);
    }

    void TearDown() override {
        delete spawner;
        window.close();
    }
};

TEST_F(SpawnerTests, SpawnAsteroid) {
    std::vector<Asteroid> asteroids;
    spawner->spawnAsteroid(asteroids);
    ASSERT_EQ(asteroids.size(), 1);
}

TEST_F(SpawnerTests, SpawnBullet) {
    Ship ship;
    std::vector<Bullet> bullets;
    spawner->spawnBullet(ship, bullets, sf::Keyboard::Key::Space);
    ASSERT_EQ(bullets.size(), 1);
}

TEST_F(SpawnerTests, SpawnShip) {
    Ship ship;
    spawner->spawnShip(ship);
    ASSERT_EQ(ship.getPosition().x, window.getSize().x / 2);
    ASSERT_EQ(ship.getPosition().y, window.getSize().y - ship.getShape().getRadius() * 2);
}

TEST_F(SpawnerTests, SpawnBackgroundElements) {
    std::vector<BackgroundElement> elements;
    spawner->spawnBackgroundElements(elements, 2, 0);
    ASSERT_EQ(elements.size(), 2);
}

TEST_F(SpawnerTests, AddAsteroidSpawnTime) {
    float initialTime = spawner->getAsteroidSpawnTime();
    spawner->addAsteroidSpawnTime();
    ASSERT_LT(spawner->getAsteroidSpawnTime(), initialTime);
}

#endif  // SPAWNER_TESTS_HPP