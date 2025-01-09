#ifndef BACK_GROUND_MOVER_HPP
#define BACK_GROUND_MOVER_HPP

#include <vector>

#include <SFML/Graphics.hpp>

#include "BackgroundElement.hpp"

namespace BackGroundMoverValues {
    const float MOVE_SPEED = -1.0f;
};

class BackGroundMover {
 public:
    BackGroundMover(sf::RenderWindow &window, std::vector<BackGroundElement> &elements) : window(window), elements(elements) {}

    void moveElements();

 private:
    sf::RenderWindow &window;

    std::vector<BackGroundElement> &elements;
};

void BackGroundMover::moveElements() {
    for (auto &element : elements) {
        element.move(BackGroundMoverValues::MOVE_SPEED);
    }
}

#endif  // BACK_GROUND_MOVER_HPP
