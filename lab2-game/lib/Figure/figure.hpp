#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <vector>
#include <utility>

#include "../Pixel/Pixel.hpp"

namespace FigureConstants {
    const std::pair<int32_t, int32_t> DEFAULT_CENTER = std::pair<int, int>(3, -3);

    enum ROTATIONS_OF_FIGURE {
        FIRST_ROTATION, // Default rotation
        SECOND_ROTATION,
        THIRD_ROTATION,
        FOURTH_ROTATION
    };

    enum TYPES_OF_FIGURE {
        TYPE_I, // Default type
        TYPE_J,
        TYPE_O,
        TYPE_L,
        TYPE_Z,
        TYPE_T,
        TYPE_S
    };
}

class Figure {
 public:
    Figure(uint8_t new_type = FigureConstants::TYPE_I, uint8_t new_color = color::NOT_COLOR,
    uint8_t new_rotation = FigureConstants::FIRST_ROTATION, std::pair <int32_t, int32_t> new_center = FigureConstants::DEFAULT_CENTER);

    void setColor(const uint8_t &color = color::NOT_COLOR);

    void setType(const uint8_t &type = FigureConstants::TYPE_I);

    void setRotation(const uint8_t &rotation = FigureConstants::FIRST_ROTATION);

    void setCenter(const std::pair<int32_t, int32_t> &new_center = FigureConstants::DEFAULT_CENTER);

    void setCoordinates(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates);

    void setPixels(const std::vector <Pixel> &new_pixels);

    void addPixels(const std::vector <Pixel> &new_pixels);

    void addPixel(const Pixel &new_pixel);

    void addCoordinates(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates);

    void addCoordinate(const std::pair<int32_t, int32_t> &new_coordinate);

    const uint8_t getColor() const;

    const uint8_t getType() const;

    const std::pair<int32_t, int32_t> getCenter() const;

    const uint8_t getRotation() const;

    const std::vector <Pixel> getPixels() const;

    const std::vector <std::pair <int32_t, int32_t> > getCoordinates() const;

    ~Figure();

 private:
    uint8_t type_;

    uint8_t color_;

    uint8_t rotation_;

    std::vector <Pixel> pixels_;

    std::pair <int32_t, int32_t> center_;

    void createJ();

    void createI();

    void createO();

    void createL();

    void createZ();

    void createT();

    void createS();

    void leftTwist();

    void rightTwist();

    void upTwist();

    void downTwist();
};

#endif
