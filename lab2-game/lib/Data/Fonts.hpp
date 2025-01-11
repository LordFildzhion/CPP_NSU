#ifndef FONTS_HPP
#define FONTS_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "ResoursesLoader.hpp"

class Fonts {
 public:
    static Fonts* getInstance();

    void loadFonts(std::string pathToFont = "../res/fonts");

    std::vector<sf::Font>& getFonts();

 private:
    Fonts() = default;
    ~Fonts();
    Fonts(const Fonts&) = delete;
    Fonts& operator=(const Fonts&) = delete;

    static Fonts *instance;

    ResourcesLoader loader;
    static std::vector<sf::Font> fonts;
};

Fonts* Fonts::getInstance() {
    if (instance == nullptr) {
        instance = new Fonts();
    }

    return instance;
}

Fonts::~Fonts() {
    delete instance;
}

void Fonts::loadFonts(std::string pathToFont) {
    fonts = loader.loadFonts(pathToFont);
}

std::vector<sf::Font>& Fonts::getFonts() {
    return fonts;
}

std::vector<sf::Font> Fonts::fonts;

Fonts *Fonts::instance = nullptr;

#endif  // FONTS_HPP
