#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <vector>


#include "pixel.hpp"


enum ROTATIONS_OF_FIGURE{
    FIRST_ROTATION,
    SECOND_ROTATION,
    THIRD_ROTATION,
    FOURTH_ROTATION
};

enum TYPES_OF_FIGURE {
    TYPE_J,
    TYPE_I,
    TYPE_O,
    TYPE_L,
    TYPE_Z,
    TYPE_T,
    TYPE_S
};

class figure {
public:
    figure(uint8_t new_type = TYPE_I, uint8_t new_color = color::NOT_COLOR,
    uint8_t new_rotation = FIRST_ROTATION, std::pair <int32_t, int32_t> new_center = std::pair<int,int>(3, -3));

    void setColor(const uint8_t &color = color::NOT_COLOR);

    void set_type(const uint8_t &type = TYPE_I);

    void set_rotation(const uint8_t &rotation = FIRST_ROTATION);

    void set_center(const std::pair<int32_t, int32_t> &new_center = std::pair<int,int>(3, -3));

    void setCoordinats(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates);

    void set_pixels(const std::vector <pixel> &new_pixels);

    void add_pixels(const std::vector <pixel> &new_pixels);

    void add_pixel(const pixel &new_pixel);

    void add_coordinates(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates);

    void add_coordinate(const std::pair<int32_t, int32_t> &new_coordinate);

    const uint8_t get_color() const;

    const uint8_t get_type() const;

    const uint8_t get_rotation() const;

    const std::vector <pixel> get_pixels() const;

    const std::vector <std::pair <int32_t, int32_t> > getCoordinats() const;

    ~figure();

private:

    uint8_t type_;

    uint8_t color_;

    uint8_t rotation_;

    std::vector <pixel> pixels_;

    std::pair <int32_t, int32_t> center_;

    void create_J();

    void create_I();

    void create_O();

    void create_L();

    void create_Z();

    void create_T();

    void create_S();

    void left_twist();

    void right_twist();

    void up_twist();

    void down_twist();
};


void figure::setColor(const uint8_t &color) {
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
void figure::create_J() {
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
void figure::create_I() {
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
void figure::create_O() {
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
void figure::create_L() {
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
void figure::create_Z() {
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
void figure::create_T() {
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
void figure::create_S() {
    pixels_.resize(4);

    pixels_[0].setCoordinats(center_.first, center_.second);
    pixels_[1].setCoordinats(center_.first + 1, center_.second);
    pixels_[2].setCoordinats(center_.first, center_.second + 1);
    pixels_[3].setCoordinats(center_.first, center_.second + 1);

}

void figure::set_type(const uint8_t &type) {
    type_ = type;

    switch (type_) {
    case TYPE_J:
        create_J();
        break;

    case TYPE_I:
        create_I();
        break;

    case TYPE_O:
        create_O();
        break;

    case TYPE_L:
        create_L();
        break;

    case TYPE_Z:
        create_Z();
        break;

    case TYPE_T:
        create_T();
        break;

    case TYPE_S:
        create_S();
        break;

    default:
        break;
    }

}

void figure::left_twist() {
    for (auto &pix : pixels_) {
        pix.setCoordinats(pix.getCoordinats().second - center_.second, -(pix.getCoordinats().first - center_.first));
    }
}

void figure::right_twist() {
    for (auto &pix : pixels_) {
        pix.setCoordinats(-(pix.getCoordinats().second - center_.second), (pix.getCoordinats().first - center_.first));
    }
}

void figure::up_twist() {
    for (auto &pix : pixels_) {
        pix.setCoordinats(-(pix.getCoordinats().first - center_.first), -(pix.getCoordinats().second - center_.second));
    }
}

void figure::down_twist() {
    set_type(type_);
}

void figure::set_rotation(const uint8_t &rotation) {

    rotation_ = rotation;

    set_type(type_);

    switch (rotation_) {
    case SECOND_ROTATION:
        left_twist();
        break;
    
    case THIRD_ROTATION:
        up_twist();
        break;

    case FOURTH_ROTATION:
        right_twist();
        break;
    
    default:
        break;
    }

}

figure::figure (uint8_t new_type,
                uint8_t new_color,
                uint8_t new_rotation,
                std::pair <int32_t, int32_t> new_center) {
    
    type_ = new_type;
    color_ = new_color;
    rotation_ = new_rotation;
    center_ = new_center;

    set_type(type_);

    set_rotation(rotation_);

    setColor(color_);

}

void figure::set_center(const std::pair<int,int> &new_center) {
    for (auto &pix : pixels_) {
        pix.setCoordinats(pix.getCoordinats().second - center_.first, pix.getCoordinats().second - center_.second);
        pix.setCoordinats(pix.getCoordinats().second - new_center.first, pix.getCoordinats().second - new_center.second);
    }

    center_ = new_center;
}

void figure::setCoordinats(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates) {
    
    pixels_.clear();

    for (auto &coord : new_coordinates) {
        pixels_.push_back(pixel(coord, color_));
    }

}

void figure::set_pixels(const std::vector <pixel> &new_pixels) {
    pixels_ = new_pixels;
}

void figure::add_pixels(const std::vector <pixel> &new_pixels) {
    for (auto &new_pixel : new_pixels) {
        pixels_.push_back(new_pixel);
    }
}

void figure::add_pixel(const pixel &new_pixel) {
    pixels_.push_back(new_pixel);
}

void figure::add_coordinates(const std::vector <std::pair <int32_t, int32_t> > &new_coordinates) {

    for (auto &new_coordinate : new_coordinates) {
        pixels_.push_back(pixel(new_coordinate, color_));
    }

}

void figure::add_coordinate(const std::pair<int32_t, int32_t> &new_coordinate) {
    pixels_.push_back(pixel(new_coordinate, color_));
}

const uint8_t figure::get_color() const{
    return color_;
}

const uint8_t figure::get_type() const{
    return type_;
}

const uint8_t figure::get_rotation() const{
    return rotation_;
}

const std::vector <pixel> figure::get_pixels() const {
    return pixels_;
}

const std::vector <std::pair <int32_t, int32_t> > figure::getCoordinats() const{
    std::vector <std::pair <int32_t, int32_t>> coordinats;

    for (auto &pix : pixels_) {
        coordinats.push_back(pix.getCoordinats());
    }

    return coordinats;
}

figure::~figure () {

}


#endif