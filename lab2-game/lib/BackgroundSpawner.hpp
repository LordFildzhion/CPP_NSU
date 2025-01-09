#ifndef BACK_GROUND_SPAWNER_HPP
#define BACK_GROUND_SPAWNER_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "BackgroundElement.hpp"

namespace BackGroundSpawnerValues {
    const size_t MAX_ELEMENT_SPAWN_TIME = 20;
    const size_t MIN_ELEMENT_SPAWN_TIME = 15;
    const size_t MAX_ELEMENT_COUNT = 3;
    const size_t MIN_ELEMENT_COUNT = 1;
    const size_t SPAWN_BORDER = 100;
    const float GENERATION_SPEED = BackGroundElementValues::SPAWN_BORDER;
};

class BackGroundSpawner {
 public:
    BackGroundSpawner(sf::RenderWindow &window, std::vector<BackGroundElement> &elements) : window(window), elements(elements) {}

    void addElement(int32_t elementSpawnTimeSec = -1);

    void spawnElements(int32_t elementsCount = -1, int32_t elementSpawnTimeSec = -1);

 protected:
    float getRandomElementSpawnTime();

    size_t getRandomElementCount();

    sf::RenderWindow &window;

    std::vector<BackGroundElement> &elements;
    sf::Clock elementSpawnTime;
};

size_t BackGroundSpawner::getRandomElementCount() {
    return rand() % (BackGroundSpawnerValues::MAX_ELEMENT_COUNT - BackGroundSpawnerValues::MIN_ELEMENT_COUNT) + BackGroundSpawnerValues::MIN_ELEMENT_COUNT;
}

float BackGroundSpawner::getRandomElementSpawnTime() {
    return ((rand() % (BackGroundSpawnerValues::MAX_ELEMENT_SPAWN_TIME - BackGroundSpawnerValues::MIN_ELEMENT_SPAWN_TIME) + BackGroundSpawnerValues::MIN_ELEMENT_SPAWN_TIME)) / BackGroundSpawnerValues::GENERATION_SPEED;
}

void BackGroundSpawner::addElement(int32_t elementSpawnTimeSec) {
    if (elementSpawnTimeSec >= 0) {
        if (elementSpawnTime.getElapsedTime().asSeconds() >= elementSpawnTimeSec || elements.empty()) {
            elements.push_back(BackGroundElement(window));
            elementSpawnTime.restart();
        }

        return;
    }

    if (elementSpawnTime.getElapsedTime().asSeconds() >= getRandomElementSpawnTime() || elements.empty()) {
        elements.push_back(BackGroundElement(window));
        elementSpawnTime.restart();
    }
}

void BackGroundSpawner::spawnElements(int32_t elementsCount, int32_t elementSpawnTimeSec) {
    if (elementsCount >= 0) {
        for (size_t i = 0; i < elementsCount; i++) {
            addElement(elementSpawnTimeSec);
        }

        return;
    }

    for (size_t i = 0; i < getRandomElementCount(); i++) {
        addElement();
    }
}

#endif  // BACK_GROUND_SPAWNER_HPP
