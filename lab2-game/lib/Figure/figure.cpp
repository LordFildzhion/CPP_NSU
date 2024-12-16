#include "Figure.hpp"

void Figure::setColor(const uint8_t &color) {
    color_ = color;

    for (auto &pix : pixels_) {
        pix.setColor(color_);
    }
}

/*
#####.
#####.
##1##.
##2##.
#30##.
#####.
*/
void Figure::createJ() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first, center_.second - 2);
    pixels_[2].setCoordinats(center_.first, center_.second - 1);
    pixels_[3].setCoordinats(center_.first - 1, center_.second);
}

/*
#####.
##1##.
##2##.
##0##.
##3##.
#####.
*/
void Figure::createI() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first, center_.second - 2);
    pixels_[2].setCoordinats(center_.first, center_.second - 1);
    pixels_[3].setCoordinats(center_.first, center_.second + 1);
}

/*
#####.
#####.
#13##.
#02##.
#####.
#####.
*/
void Figure::createO() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first, center_.second - 1);
    pixels_[2].setCoordinats(center_.first + 1, center_.second);
    pixels_[3].setCoordinats(center_.first + 1, center_.second - 1);
}

/*
#####.
#####.
#1###.
#2###.
#03##.
#####.
*/
void Figure::createL() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first, center_.second - 2);
    pixels_[2].setCoordinats(center_.first, center_.second - 1);
    pixels_[3].setCoordinats(center_.first + 1, center_.second);
}

/*
#####.
#####.
#10##.
##23#.
#####.
#####.
*/
void Figure::createZ() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first - 1, center_.second);
    pixels_[2].setCoordinats(center_.first, center_.second + 1);
    pixels_[3].setCoordinats(center_.first + 1, center_.second + 1);
}

/*
#####.
#####.
#102#.
##3##.
#####.
#####.
*/
void Figure::createT() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first - 1, center_.second);
    pixels_[2].setCoordinats(center_.first + 1, center_.second);
    pixels_[3].setCoordinats(center_.first, center_.second + 1);
}

/*
#####.
#####.
##01#.
#32##.
#####.
#####.
*/
void Figure::createS() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first + 1, center_.second);
    pixels_[2].setCoordinats(center_.first, center_.second + 1);
    pixels_[3].setCoordinats(center_.first, center_.second + 1);
}

void Figure::setType(const uint8_t &type) {
    type_ = type;

    switch (type_) {
    case FigureConstants::TYPE_J:
        createJ();
        break;

    case FigureConstants::TYPE_I:
        createI();
        break;

    case FigureConstants::TYPE_O:
        createO();
        break;

    case FigureConstants::TYPE_L:
        createL();
        break;

    case FigureConstants::TYPE_Z:
        createZ();
        break;

    case FigureConstants::TYPE_T:
        createT();
        break;

    case FigureConstants::TYPE_S:
        createS();
        break;

    default:
        break;
    }
}

void Figure::leftTwist() {
    for (auto &pix : pixels_) {
        pix.setCoordinats(pix.getCoordinates().second - center_.second, -(pix.getCoordinates().first - center_.first));
    }
}

void Figure::rightTwist() {
    for (auto &pix : pixels_) {
        pix.setCoordinats(-(pix.getCoordinates().second - center_.second), (pix.getCoordinates().first - center_.first));
    }
}

void Figure::upTwist() {
    for (auto &pix : pixels_) {
        pix.setCoordinats(-(pix.getCoordinates().first - center_.first), -(pix.getCoordinates().second - center_.second));
    }
}

void Figure::downTwist() {
    setType(type_);
}

void Figure::setRotation(const uint8_t &rotation) {
    rotation_ = rotation;

    setType(type_);

    switch (rotation_) {
    case FigureConstants::SECOND_ROTATION:
        leftTwist();
        break;

    case FigureConstants::THIRD_ROTATION:
        upTwist();
        break;

    case FigureConstants::FOURTH_ROTATION:
        rightTwist();
        break;

    default:
        break;
    }
}

Figure::Figure(uint8_t new_type, uint8_t new_color, uint8_t new_rotation, std::pair <int32_t, int32_t> new_center) {
    type_ = new_type;
    color_ = new_color;
    rotation_ = new_rotation;
    center_ = new_center;

    setType(type_);

    setRotation(rotation_);

    setColor(color_);
}

void Figure::setCenter(const std::pair<int, int> &new_center) {
    for (auto &pix : pixels_) {
        pix.setCoordinats(pix.getCoordinates().second - center_.first, pix.getCoordinates().second - center_.second);
        pix.setCoordinats(pix.getCoordinates().second - new_center.first, pix.getCoordinates().second - new_center.second);
    }

    center_ = new_center;
}

void Figure::setCoordinates(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates) {
    pixels_.clear();

    for (auto &coord : new_coordinates) {
        pixels_.push_back(Pixel(coord, color_));
    }
}

void Figure::setPixels(const std::vector <Pixel> &new_pixels) {
    pixels_ = new_pixels;
}

void Figure::addPixels(const std::vector <Pixel> &new_pixels) {
    for (auto &new_pixel : new_pixels) {
        pixels_.push_back(new_pixel);
    }
}

void Figure::addPixel(const Pixel &new_pixel) {
    pixels_.push_back(new_pixel);
}

void Figure::addCoordinates(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates) {
    for (auto &new_coordinate : new_coordinates) {
        pixels_.push_back(Pixel(new_coordinate, color_));
    }
}

void Figure::addCoordinate(const std::pair<int32_t, int32_t> &new_coordinate) {
    pixels_.push_back(Pixel(new_coordinate, color_));
}

const uint8_t Figure::getColor() const {
    return color_;
}

const uint8_t Figure::getType() const {
    return type_;
}

const uint8_t Figure::getRotation() const {
    return rotation_;
}

const std::pair <int32_t, int32_t> Figure::getCenter() const {
    return center_;
}

const std::vector <Pixel> Figure::getPixels() const {
    return pixels_;
}

const std::vector <std::pair <int32_t, int32_t> > Figure::getCoordinates() const {
    std::vector <std::pair <int32_t, int32_t>> coordinats;

    for (auto &pix : pixels_) {
        coordinats.push_back(pix.getCoordinates());
    }

    return coordinats;
}

Figure::~Figure() = default;
