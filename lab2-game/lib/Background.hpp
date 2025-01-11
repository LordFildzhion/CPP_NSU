#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "BackgroundElement.hpp"
#include "Spawner.hpp"
#include "Mover.hpp"
#include "Printer.hpp"

class Background {
 public:
    static Background* getInstance(sf::RenderWindow &window);

    void setElements(std::vector<BackgroundElement> &elements);

    std::vector<BackgroundElement> &getElements();

    void update();

    bool isCompleted();

    void restart();

 private:
    explicit Background(sf::RenderWindow &window);

    static Background *instance;

    bool completed;

    sf::RenderWindow &window;

    Spawner spawner;
    Mover mover;
    Printer printer;

    void spawnElements(int32_t elementsCount = -1);

    void moveElements();

    void printElements();

    void checkOutOfBounds();

    std::vector<BackgroundElement> elements;

    Background(const Background&) = delete;
    Background& operator=(const Background&) = delete;
};

Background* Background::instance = nullptr;

Background* Background::getInstance(sf::RenderWindow &window) {
    if (instance == nullptr) {
        instance = new Background(window);
    }

    return instance;
}

Background::Background(sf::RenderWindow &window) : window(window), spawner(window), printer(window), mover(window) {
    completed = false;
}

void Background::setElements(std::vector<BackgroundElement> &elements) {
    this->elements = elements;
}

std::vector<BackgroundElement> &Background::getElements() {
    return elements;
}

void Background::update() {
    spawnElements();
    moveElements();
    printElements();
    checkOutOfBounds();
}

bool Background::isCompleted() {
    return completed;
}

void Background::restart() {
    elements.clear();
    completed = false;
}

void Background::spawnElements(int32_t elementsCount) {
    spawner.spawnBackgroundElements(elements, elementsCount);
}

void Background::moveElements() {
    mover.moveBackground(elements);
}

void Background::printElements() {
    printer.printBackground(elements);
}

void Background::checkOutOfBounds() {
    for (size_t i = 0; i < elements.size(); i++) {
        if (elements.at(i).getShape().getPosition().x <= -static_cast<float>(BackgroundElementValues::SPAWN_BORDER)) {
            elements.erase(elements.begin() + i);
            completed = true;
        }
    }
}

#endif  // BACKGROUND_HPP
