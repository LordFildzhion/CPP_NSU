#ifndef PIXEL_HPP
#define PIXEL_HPP

#include <utility>
#include <cstdint>

namespace color {
    enum color {
        NOT_COLOR, //Default color
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        DARK_BLUE,
        MAGENTA
    };
}

class Pixel {
 public:
    explicit Pixel(int32_t new_x = 0, int32_t new_y = 0, uint8_t new_color = color::NOT_COLOR);

    explicit Pixel(std::pair <int32_t, int32_t> new_coordinats, uint8_t new_color = color::NOT_COLOR);

    const std::pair <int32_t, int32_t> getCoordinates() const;

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

    bool operator== (const Pixel &second_pixel);

    bool operator!= (const Pixel &second_pixel);

    Pixel &operator= (const Pixel &new_value);

    ~Pixel();

 private:
    std::pair <int32_t, int32_t> coordinats_;
    uint8_t color_;
};

#endif
