#include "Map.hpp"


Map::Map(size_t length_of_visibility, size_t width_of_visibility, int64_t length_real, int64_t width_real) {
    length_of_visibility_ = length_of_visibility;
    width_of_visibility_ = width_of_visibility;
    length_real_ = length_real;
    width_real_ = width_real;

    map_.resize(length_real);
    for (size_t i = 0; i < length_real; i++) {
        map_[i].resize(width_real);

        for (size_t j = 0; j < width_real; j++) {
            map_[i][j] = Pixel(i, j, color::NOT_COLOR);
        }
    }
}

void Map::setPixel(int64_t x, int64_t y, uint8_t color) {
    map_[x][y].setColor(color);
}

void Map::setPixel(std::pair <int64_t, int64_t> coordinats, uint8_t color) {
    map_[coordinats.first][coordinats.second].setColor(color);
}

Pixel Map::getPixel(int64_t x, int64_t y) {
    return map_[x][y];
}

Pixel Map::getPixel(std::pair <int64_t, int64_t> coordinats) {
    return map_[coordinats.first][coordinats.second];
}

void Map::setPixels(std::vector <std::pair <int64_t, int64_t>> coordinats, uint8_t color) {
    for (auto coordinat : coordinats) {
        map_[coordinat.first][coordinat.second].setColor(color);
    }
}

std::vector <std::vector <Pixel>> Map::getPixels(std::vector <std::pair <int64_t, int64_t>> coordinats) {
    std::vector <std::vector <Pixel>> pixels;
    pixels.resize(coordinats.size());

    for (size_t i = 0; i < coordinats.size(); i++) {
        pixels[i].resize(coordinats.size());
        pixels[i][0] = map_[coordinats[i].first][coordinats[i].second];
    }

    return pixels;
}

std::vector <std::vector <Pixel>> Map::getVisiblePixels() {
    std::vector <std::vector <Pixel>> pixels;
    pixels.resize(length_of_visibility_);

    for (size_t i = 0; i < length_of_visibility_; i++) {
        pixels[i].resize(width_of_visibility_);

        for (size_t j = 0; j < width_of_visibility_; j++) {
            pixels[i][j] = map_[i][j];
        }
    }

    return pixels;
}

std::vector <std::vector <Pixel>> Map::getAllPixels() {
    std::vector <std::vector <Pixel>> pixels;
    pixels.resize(length_real_);

    for (size_t i = 0; i < length_real_; i++) {
        pixels[i].resize(width_real_);

        for (size_t j = 0; j < width_real_; j++) {
            pixels[i][j] = map_[i][j];
        }
    }

    return pixels;
}

size_t Map::getLengthOfVisibility() {
    return length_of_visibility_;
}

size_t Map::getWidthOfVisibility() {
    return width_of_visibility_;
}

int64_t Map::getLengthReal() {
    return length_real_;
}

int64_t Map::getWidthReal() {
    return width_real_;
}

Map::~Map() = default;
