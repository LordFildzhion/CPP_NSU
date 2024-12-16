#ifndef SHIFTER_HPP
#define SHIFTER_HPP

#include "Map/Map.hpp"
#include "Figure/Figure.hpp"

#include <cstdint>
#include <utility>
#include <vector>

class Shifter {
 private:
    Map map;
    Figure figure;
    int32_t speed;

 public:
    Shifter();

    ~Shifter();

    void shiftLeft();

    void shiftRight();

    void shiftDown();

    void setMap(Map &map);

    void setFigure(Figure &figure);

    void setSpeed(int32_t speed);

    Map &getMap();

    int32_t getSpeed();

}

Shifter::Shifter() {
    speed = 1;
}

Shifter::~Shifter() = default;

void Shifter::shiftLeft() {
    for (auto &pixel : figure.getPixels()) {
        if (pixel.getCoordinates().first - 1 < 0) {
            return;
        }

        if (map.getPixel(pixel.getCoordinates().first - 1, pixel.getCoordinates().second).getColor() != color::NOT_COLOR) {
            return;
        }
    }

    figure.setCenter(std::pair<int32_t, int32_t>(figure.getCenter().first - 1, figure.getCenter().second));
}

void Shifter::shiftRight() {
    for (auto &pixel : figure.getPixels()) {
        if (pixel.getCoordinates().first + 1 >= map.getWidthReal()) {
            return;
        }

        if (map.getPixel(pixel.getCoordinates().first + 1, pixel.getCoordinates().second).getColor() != color::NOT_COLOR) {
            return;
        }
    }

    figure.setCenter(std::pair<int32_t, int32_t>(figure.getCenter().first + 1, figure.getCenter().second));
}

void Shifter::shiftDown() {
    for (auto &pixel : figure.getPixels()) {
        if (pixel.getCoordinates().second + 1 >= map.getLengthReal()) {
            return;
        }

        if (map.getPixel(pixel.getCoordinates().first, pixel.getCoordinates().second + 1).getColor() != color::NOT_COLOR) {
            return;
        }
    }

    figure.setCenter(std::pair<int32_t, int32_t>(figure.getCenter().first, figure.getCenter().second + 1));
}

void Shifter::setMap(Map &map) {
    this->map = map;
}

void Shifter::setFigure(Figure &figure) {
    this->figure = figure;
}

void Shifter::setSpeed(int32_t speed) {
    this->speed = speed;
}

Map &Shifter::getMap() {
    return map;
}

int Shifter::getSpeed() {
    return speed;
}

#endif // SHIFTER_HPP
