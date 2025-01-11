#ifndef RESOURCES_LOADER_HPP
#define RESOURCES_LOADER_HPP

#include <string>
#include <vector>
#include <exception>
#include <filesystem>

#include <SFML/Graphics.hpp>

class ResourcesLoaderException : public std::exception {
 public:
    explicit ResourcesLoaderException(const std::string &message) : message(message) {}

    const char *what() const noexcept override;

 private:
    std::string message;
};

const char* ResourcesLoaderException::what() const noexcept {
    return message.c_str();
}


class ResourcesLoader {
 public:
    ResourcesLoader() = default;

    std::vector<sf::Texture> loadShipTexture(std::string pathToShips = "../res/textures/ship");

    std::vector<sf::Texture> loadAsteroidTexture(std::string pathToAsteroids = "../res/textures/asteroid");

    std::vector<sf::Texture> loadBulletTexture(std::string pathToBullet = "../res/textures/bullet");

    std::vector<sf::Font> loadFonts(std::string pathToFont = "../res/fonts");
};

std::vector<sf::Texture> ResourcesLoader::loadShipTexture(std::string pathToShips) {
    std::vector<sf::Texture> shipTextures;

    if (!std::filesystem::exists(pathToShips)) {
        throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADSHIPTEXTURE:Can't find path to ship textures\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToShips)) {
        sf::Texture texture;
        if (!texture.loadFromFile(entry.path().string())) {
            throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADSHIPTEXTURE:Can't load texture from file\n");
        }

        shipTextures.push_back(texture);
    }

    return shipTextures;
}

std::vector<sf::Texture> ResourcesLoader::loadAsteroidTexture(std::string pathToAsteroids) {
    std::vector<sf::Texture> asteroidTextures;

    if (!std::filesystem::exists(pathToAsteroids)) {
        throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADASTEROIDTEXTURE:Can't find path to asteroid textures\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToAsteroids)) {
        sf::Texture texture;
        if (!texture.loadFromFile(entry.path().string())) {
            throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADASTEROIDTEXTURE:Can't load texture from file\n");
        }

        asteroidTextures.push_back(texture);
    }

    return asteroidTextures;
}

std::vector<sf::Texture> ResourcesLoader::loadBulletTexture(std::string pathToBullet) {
    std::vector<sf::Texture> bulletTextures;

    if (!std::filesystem::exists(pathToBullet)) {
        throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADBULLETTEXTURE:Can't find path to bullet textures\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToBullet)) {
        sf::Texture texture;
        if (!texture.loadFromFile(entry.path().string())) {
            throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADBULLETTEXTURE:Can't load texture from file\n");
        }

        bulletTextures.push_back(texture);
    }

    return bulletTextures;
}

std::vector<sf::Font> ResourcesLoader::loadFonts(std::string pathToFont) {
    std::vector<sf::Font> fonts;

    if (!std::filesystem::exists(pathToFont)) {
        throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADFONTS:Can't find path to fonts\n");
    }

    for (const auto &entry : std::filesystem::directory_iterator(pathToFont)) {
        sf::Font font;
        if (!font.openFromFile(entry.path().string())) {
            throw ResourcesLoaderException("ERROR!!!\nRESOURCESLOADER::LOADFONTS:Can't load font from file\n");
        }

        fonts.push_back(font);
    }

    return fonts;
}

#endif  // RESOURCES_LOADER_HPP
