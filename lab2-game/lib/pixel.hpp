#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>
#include <utility>
#include <cstdint>

namespace color {
    enum color {
        NOT_COLOR,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        DARK_BLUE,
        MAGENTA
    };
}

class pixel {
 public:
    explicit pixel(int32_t new_x = 0, int32_t new_y = 0, uint8_t new_color = color::NOT_COLOR);

    explicit pixel(std::pair <int32_t, int32_t> new_coordinats, uint8_t new_color = color::NOT_COLOR);

    const std::pair <int32_t, int32_t> getCoordinats() const;

    void setCoordinats(std::pair <int32_t, int32_t> new_coordinats);

    void setCoordinats(int32_t new_x, int32_t new_y);

    const uint8_t getColor() const;

    void setColor(uint8_t new_color);

    int32_t getX();
    const int32_t getX() const;

    int32_t getY();
    const int32_t getY() const;

    void setX(int32_t new_x);

    void setY(int32_t new_y);

    bool operator== (const pixel &second_pixel);

    bool operator!= (const pixel &second_pixel);

    pixel &operator= (const pixel &new_value);

    ~pixel();

 private:
    std::pair <int32_t, int32_t> coordinats_;
    uint8_t color_;
};

pixel::pixel(int32_t new_x, int32_t new_y, uint8_t new_color) {
    coordinats_.first = new_x;
    coordinats_.second = new_y;
    color_ = new_color;
}

pixel::pixel(std::pair <int32_t, int32_t> new_coordinats, uint8_t new_color) {
    coordinats_ = new_coordinats;
    color_ = new_color;
}

const std::pair <int32_t, int32_t> pixel::getCoordinats() const {
    return coordinats_;
}

void pixel::setCoordinats(std::pair <int32_t, int32_t> new_coordinats) {
    coordinats_ = new_coordinats;
}

void pixel::setCoordinats(int32_t x, int32_t y) {
    coordinats_.first = x;
    coordinats_.second = y;
}

const uint8_t pixel::getColor() const {
    return color_;
}

void pixel::setColor(uint8_t new_color) {
    color_ = new_color;
}

int32_t pixel::getX() {
    return coordinats_.first;
}

const int32_t pixel::getX() const {
    return coordinats_.first;
}

int32_t pixel::getY() {
    return coordinats_.second;
}

const int32_t pixel::getY() const {
    return coordinats_.second;
}

void pixel::setX(int32_t new_x) {
    coordinats_.first = new_x;
}

void pixel::setY(int32_t new_y) {
    coordinats_.second = new_y;
}

bool pixel::operator== (const pixel &second_pixel) {
    if (coordinats_ == second_pixel.coordinats_ && color_ == second_pixel.color_) {
        return true;
    }
    return false;
}

bool pixel::operator!= (const pixel &second_pixel) {
    return (*this == second_pixel);
}

pixel &pixel::operator= (const pixel &new_value) {
    color_ = new_value.color_;
    coordinats_ = new_value.coordinats_;

    return *this;
}

pixel::~pixel() = default;


#endif
