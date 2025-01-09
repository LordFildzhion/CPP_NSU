#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <vector>
#include <string>
#include <exception>
#include <filesystem>
#include <iostream>
#include <fstream>

#include <SFML/Graphics.hpp>

class TexturesException : public std::exception {
public:
    explicit TexturesException(const std::string &message) : message(message) {}

    const char *what() const noexcept override;

private:
    std::string message;
};

const char* TexturesException::what() const noexcept {
    return message.c_str();
}

class Textures {
public:
    Textures();

    void loadShipTexture(std::string pathToShips = "../rec/textures/ship");

    void loadAsteroidTexture(std::string pathToAsteroids = "../rec/textures/asteroid");

    void loadBulletTexture(std::string pathToBullet = "../rec/textures/bullet");

    std::vector<sf::Texture> &getShipTextures();

    std::vector<sf::Texture> &getAsteroidTextures();

    std::vector<sf::Texture> &getBulletTextures();

private:
    std::vector<sf::Texture> shipTextures;
    std::vector<sf::Texture> asteroidTextures;
    std::vector<sf::Texture> bulletTextures;
};


Textures::Textures() {
    loadShipTexture();
    loadAsteroidTexture();
    loadBulletTexture();
}

void Textures::loadShipTexture(std::string pathToShips) {
    std::filesystem::path pathToShips_{pathToShips};
    if (!std::filesystem::exists(pathToShips_)) {
        throw TexturesException("ERROR!!!\nTEXTURES::LOADSHIPTEXTURE:Can't find path to ship textures\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToShips_)) {
        sf::Texture shipTexture;
        std::cout << entry.path().string() << std::endl;
        if (!shipTexture.loadFromFile(entry.path().string())) {
            throw TexturesException("ERROR!!!\nTEXTURES::LOADSHIPTEXTURE:Can't load ship texture from file\n");
        }

        shipTextures.push_back(shipTexture);
    }
}

void Textures::loadAsteroidTexture(std::string pathToAsteroids) {
    if (!std::filesystem::exists(pathToAsteroids)) {
        throw TexturesException("ERROR!!!\nTEXTURES::LOADASTEROIDTEXTURE:Can't find path to asteroid textures\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToAsteroids)) {
        sf::Texture asteroidTexture;
        if (!asteroidTexture.loadFromFile(entry.path().string())) {
            throw TexturesException("ERROR!!!\nTEXTURES::LOADASTEROIDTEXTURE:Can't load asteroid texture from file\n");
        }

        asteroidTextures.push_back(asteroidTexture);
    }
}

void Textures::loadBulletTexture(std::string pathToBullet) {
    if (!std::filesystem::exists(pathToBullet)) {
        throw TexturesException("ERROR!!!\nTEXTURES::LOADBULLETTEXTURE:Can't find path to bullet texture\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToBullet)) {
        sf::Texture bulletTexture;
        if (!bulletTexture.loadFromFile(entry.path().string())) {
            throw TexturesException("ERROR!!!\nTEXTURES::LOADBULLETTEXTURE:Can't load bullet texture from file\n");
        }

        bulletTextures.push_back(bulletTexture);
    }
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

#endif // TEXTURES_HPP
