#ifndef BACK_GROUND_PRINTER_HPP
#define BACK_GROUND_PRINTER_HPP

#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "BackgroundElement.hpp"

class BackGroundPrinter {
 public:
    BackGroundPrinter(sf::RenderWindow &window, std::vector<BackGroundElement> &elements) : window(window), elements(elements) {}

    void printElements();

 private:
    sf::RenderWindow &window;

    std::vector<BackGroundElement> &elements;
};

void BackGroundPrinter::printElements() {
    for (auto &element : elements) {
        window.draw(element.getShape());
    }
}

#endif  // BACK_GROUND_PRINTER_HPP
