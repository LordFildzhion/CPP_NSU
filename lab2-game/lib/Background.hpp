#ifndef BACK_GROUND_HPP
#define BACK_GROUND_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "BackgroundElement.hpp"
#include "BackgroundSpawner.hpp"
#include "BackgroundMover.hpp"
#include "BackgroundPrinter.hpp"

class BackGround {
 public:
    explicit BackGround(sf::RenderWindow &window);

    void setElements(std::vector<BackGroundElement> &elements);

    std::vector<BackGroundElement> &getElements();

    void update();

    bool backroundIsCompleted();

    void restart();

 protected:
    bool completed;

    sf::RenderWindow &window;

    BackGroundSpawner spawner;
    BackGroundMover mover;
    BackGroundPrinter printer;

    void spawnElements(int32_t elementsCount = -1);

    void moveElements();

    void printElements();

    void checkOutOfBounds();

    std::vector<BackGroundElement> elements;
};

BackGround::BackGround(sf::RenderWindow &window) : window(window), spawner(window, elements), mover(window, elements), printer(window, elements) {
    completed = false;
}

void BackGround::setElements(std::vector<BackGroundElement> &elements) {
    this->elements = elements;
}

std::vector<BackGroundElement> &BackGround::getElements() {
    return elements;
}

void BackGround::update() {
    spawnElements();
    moveElements();
    printElements();
    checkOutOfBounds();
}

bool BackGround::backroundIsCompleted() {
    return completed;
}

void BackGround::restart() {
    elements.clear();
    completed = false;
}

void BackGround::spawnElements(int32_t elementsCount) {
    spawner.spawnElements(elementsCount);
}

void BackGround::moveElements() {
    mover.moveElements();
}

void BackGround::printElements() {
    printer.printElements();
}

void BackGround::checkOutOfBounds() {
    for (size_t i = 0; i < elements.size(); i++) {
        if (elements.at(i).getShape().getPosition().x <= -static_cast<float>(BackGroundElementValues::SPAWN_BORDER)) {
            elements.erase(elements.begin() + i);
            completed = true;
        }
    }
}

#endif  // BACK_GROUND_HPP
