#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <iostream>

enum colors{
    NOT_COLOR,
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    DARK_BLUE,
    MAGENTA
};

class pixel {
public:
    pixel(int32_t new_x = 0, int32_t new_y = 0, uint8_t new_color = NOT_COLOR);

    pixel(std::pair <int32_t, int32_t> new_coordinats, uint8_t new_color = NOT_COLOR);

    std::pair <int32_t, int32_t> get_coordinats();

    void set_coordinats (std::pair <int32_t, int32_t> new_coordinats);

    void set_coordinats (int32_t new_x, int32_t new_y);

    uint8_t get_color();

    void set_color (uint8_t new_color);

    bool operator== (const pixel &second_pixel);

    bool operator!= (const pixel &second_pixel);

    pixel &operator= (const pixel &new_value);

    ~pixel();

private:
    std::pair <int32_t, int32_t> coordinats_;
    uint8_t color_;
};

pixel::pixel(int32_t new_x = 0, int32_t new_y = 0, uint8_t new_color = NOT_COLOR) {
    coordinats_.first = new_x;
    coordinats_.second = new_y;
    color_ = new_color;
}

pixel::pixel(std::pair <int32_t, int32_t> new_coordinats, uint8_t new_color = NOT_COLOR) {
    coordinats_ = new_coordinats;
    color_ = new_color;
}

std::pair <int32_t, int32_t> pixel::get_coordinats() {
    return coordinats_;
}

void pixel::set_coordinats(std::pair <int32_t, int32_t> new_coordinats) {
    coordinats_ = new_coordinats;
}

void pixel::set_coordinats(int32_t x, int32_t y) {
    coordinats_.first = x;
    coordinats_.second = y;
}

uint8_t pixel::get_color() {
    return color_;
}

void pixel::set_color(uint8_t new_color) {
    color_ = new_color;
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
