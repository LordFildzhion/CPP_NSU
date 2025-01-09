#ifndef BACKGROUND_SPAWNER_TESTS_HPP
#define BACKGROUND_SPAWNER_TESTS_HPP

#include <vector>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "BackgroundSpawner.hpp"
#include "BackgroundElement.hpp"

class BackgroundSpawnerTests : public ::testing::Test {
 protected:
    class TestableBackGroundSpawner : public BackGroundSpawner {
     public:
        TestableBackGroundSpawner(sf::RenderWindow &window, std::vector<BackGroundElement> &elements) : BackGroundSpawner(window, elements) {}

        using BackGroundSpawner::getRandomElementCount;

        using BackGroundSpawner::getRandomElementSpawnTime;
    };

    sf::RenderWindow window;
    std::vector<BackGroundElement> elements;
    TestableBackGroundSpawner *spawner;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        spawner = new TestableBackGroundSpawner(window, elements);
    }

    void TearDown() override {
        delete spawner;
        window.close();
    }
};

TEST_F(BackgroundSpawnerTests, AddElementIncreasesElementCount) {
    size_t initialCount = elements.size();
    spawner->addElement();
    EXPECT_EQ(elements.size(), initialCount + 1);
}

TEST_F(BackgroundSpawnerTests, SpawnElementsWithSpecificCount) {
    size_t initialCount = elements.size();
    spawner->spawnElements(2, 0);
    EXPECT_EQ(elements.size(), initialCount + 2);
}

TEST_F(BackgroundSpawnerTests, SpawnElementsWithRandomCount) {
    size_t initialCount = elements.size();
    spawner->spawnElements();
    EXPECT_GE(elements.size(), initialCount + BackGroundSpawnerValues::MIN_ELEMENT_COUNT);
    EXPECT_LE(elements.size(), initialCount + BackGroundSpawnerValues::MAX_ELEMENT_COUNT);
}

TEST_F(BackgroundSpawnerTests, GetRandomElementCountWithinRange) {
    size_t count = spawner->getRandomElementCount();
    EXPECT_GE(count, BackGroundSpawnerValues::MIN_ELEMENT_COUNT);
    EXPECT_LE(count, BackGroundSpawnerValues::MAX_ELEMENT_COUNT);
}

TEST_F(BackgroundSpawnerTests, GetRandomElementSpawnTimeWithinRange) {
    float time = spawner->getRandomElementSpawnTime();
    EXPECT_GE(time, static_cast<float>(BackGroundSpawnerValues::MIN_ELEMENT_SPAWN_TIME) / BackGroundSpawnerValues::GENERATION_SPEED);
    EXPECT_LE(time, static_cast<float>(BackGroundSpawnerValues::MAX_ELEMENT_SPAWN_TIME) / BackGroundSpawnerValues::GENERATION_SPEED);
}

#endif  // BACKGROUND_SPAWNER_TESTS_HPP
