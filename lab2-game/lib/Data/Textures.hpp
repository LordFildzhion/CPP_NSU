#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <vector>
#include <string>
#include <exception>
#include <filesystem>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

#include "ResoursesLoader.hpp"

class Textures {
 public:
    static Textures* getInstance();

    void loadShipTexture(std::string pathToShips = "../res/textures/ship");

    void loadAsteroidTexture(std::string pathToAsteroids = "../res/textures/asteroid");

    void loadBulletTexture(std::string pathToBullet = "../res/textures/bullet");

    std::vector<sf::Texture> &getShipTextures();

    std::vector<sf::Texture> &getAsteroidTextures();

    std::vector<sf::Texture> &getBulletTextures();

 private:
    Textures();
    ~Textures();

    Textures(const Textures&) = delete;
    Textures& operator=(const Textures&) = delete;

    ResourcesLoader loader;
    static std::vector<sf::Texture> shipTextures;
    static std::vector<sf::Texture> asteroidTextures;
    static std::vector<sf::Texture> bulletTextures;

    static Textures* instance;
};

Textures* Textures::instance = nullptr;

std::vector<sf::Texture> Textures::shipTextures;

std::vector<sf::Texture> Textures::asteroidTextures;

std::vector<sf::Texture> Textures::bulletTextures;

Textures::Textures() {
    loadShipTexture();
    loadAsteroidTexture();
    loadBulletTexture();
}

Textures::~Textures() {
    delete instance;
}

Textures* Textures::getInstance() {
    if (instance == nullptr) {
        instance = new Textures();
    }
    return instance;
}

void Textures::loadShipTexture(std::string pathToShips) {
    shipTextures = loader.loadShipTexture(pathToShips);
}

void Textures::loadAsteroidTexture(std::string pathToAsteroids) {
    asteroidTextures = loader.loadAsteroidTexture(pathToAsteroids);
}

void Textures::loadBulletTexture(std::string pathToBullet) {
    bulletTextures = loader.loadBulletTexture(pathToBullet);
}

std::vector<sf::Texture>& Textures::getShipTextures() {
    return shipTextures;
}

std::vector<sf::Texture>& Textures::getAsteroidTextures() {
    return asteroidTextures;
}

std::vector<sf::Texture>& Textures::getBulletTextures() {
    return bulletTextures;
}

#endif  // TEXTURES_HPP
