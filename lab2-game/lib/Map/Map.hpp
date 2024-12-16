#ifndef MAP_HPP
#define MAP_HPP


#include <cstdint>
#include <vector>
#include <utility>


#include "../Pixel/Pixel.hpp"


class Map {
 private:
    std::vector <std::vector <Pixel>> map_;
    size_t length_of_visibility_;
    size_t width_of_visibility_;
    int64_t length_real_;
    int64_t width_real_;

 public:
    Map(size_t length_of_visibility = 1024, size_t width_of_visibility = 1024, int64_t length_real = 2048, int64_t width_real = 2048);

    void setPixel(int64_t x, int64_t y, uint8_t color);

    void setPixel(std::pair <int64_t, int64_t> coordinats, uint8_t color);

    Pixel getPixel(int64_t x, int64_t y);

    Pixel getPixel(std::pair <int64_t, int64_t> coordinats);

    void setPixels(std::vector <std::pair <int64_t, int64_t>> coordinats, uint8_t color);

    std::vector <std::vector <Pixel>> getPixels(std::vector <std::pair <int64_t, int64_t>> coordinats);

    std::vector <std::vector <Pixel>> getVisiblePixels();

    std::vector <std::vector <Pixel>> getAllPixels();

    size_t getLengthOfVisibility();

    size_t getWidthOfVisibility();

    int64_t getLengthReal();

    int64_t getWidthReal();

    ~Map();
};

#endif
