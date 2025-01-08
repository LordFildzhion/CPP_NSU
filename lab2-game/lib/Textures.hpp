#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <vector>
#include <string>

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

    void loadShipTexture();

    void loadAsteroidTexture();

    void loadBulletTexture();

    std::vector<sf::Texture> &getShipTextures();

    std::vector<sf::Texture> &getAsteroidTextures();

    sf::Texture &getBulletTexture();

private:
    std::vector<sf::Texture> shipTextures;
    std::vector<sf::Texture> asteroidTextures;
    sf::Texture bulletTexture;
};


Textures::Textures() {
    loadShipTexture();
    loadAsteroidTexture();
    loadBulletTexture();
}

void Textures::loadShipTexture() {
    for (size_t i = 1; i <= 2; i++) {
        sf::Texture shipTexture;
        if (!shipTexture.loadFromFile("..\\rec\\ship" + std::to_string(i) + ".png")) {
            throw std::runtime_error("ERROR!!!\nTEXTURES::LOADSHIPTEXTURE:Can't load ship texture from file\n");
        }

        shipTextures.push_back(shipTexture);
    }
}

void Textures::loadAsteroidTexture() {
    for (size_t i = 1; i <= 3; i++) {
        sf::Texture asteroidTexture;
        if (!asteroidTexture.loadFromFile("..\\rec\\asteroid" + std::to_string(i) + ".png")) {
            throw TexturesException("ERROR!!!\nTEXTURES::LOADASTEROIDTEXTURE:Can't load asteroid texture from file\n");
        }

        asteroidTextures.push_back(asteroidTexture);
    }
}

void Textures::loadBulletTexture() {
    if (!bulletTexture.loadFromFile("..\\rec\\bullet.png")) {
        throw TexturesException("ERROR!!!\nTEXTURES::LOADBULLETTEXTURE:Can't load bullet texture from file\n");
    }
}

std::vector<sf::Texture>& Textures::getShipTextures() {
    return shipTextures;
}

std::vector<sf::Texture>& Textures::getAsteroidTextures() {
    return asteroidTextures;
}

sf::Texture& Textures::getBulletTexture() {
    return bulletTexture;
}

#endif // TEXTURES_HPP
