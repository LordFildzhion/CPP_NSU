#include "Pixel.hpp"


Pixel::Pixel(int32_t new_x, int32_t new_y, uint8_t new_color) {
    coordinats_.first = new_x;
    coordinats_.second = new_y;
    color_ = new_color;
}

Pixel::Pixel(std::pair <int32_t, int32_t> new_coordinats, uint8_t new_color) {
    coordinats_ = new_coordinats;
    color_ = new_color;
}

const std::pair <int32_t, int32_t> Pixel::getCoordinates() const {
    return coordinats_;
}

void Pixel::setCoordinats(std::pair <int32_t, int32_t> new_coordinats) {
    coordinats_ = new_coordinats;
}

void Pixel::setCoordinats(int32_t x, int32_t y) {
    coordinats_.first = x;
    coordinats_.second = y;
}

const uint8_t Pixel::getColor() const {
    return color_;
}

void Pixel::setColor(uint8_t new_color) {
    color_ = new_color;
}

int32_t Pixel::getX() {
    return coordinats_.first;
}

const int32_t Pixel::getX() const {
    return coordinats_.first;
}

int32_t Pixel::getY() {
    return coordinats_.second;
}

const int32_t Pixel::getY() const {
    return coordinats_.second;
}

void Pixel::setX(int32_t new_x) {
    coordinats_.first = new_x;
}

void Pixel::setY(int32_t new_y) {
    coordinats_.second = new_y;
}

bool Pixel::operator== (const Pixel &second_pixel) {
    if (coordinats_ == second_pixel.coordinats_ && color_ == second_pixel.color_) {
        return true;
    }

    return false;
}

bool Pixel::operator!= (const Pixel &second_pixel) {
    return !(*this == second_pixel);
}

Pixel &Pixel::operator= (const Pixel &new_value) {
    color_ = new_value.color_;
    coordinats_ = new_value.coordinats_;

    return *this;
}

Pixel::~Pixel() = default;
