#ifndef TEXTURES_HPP
#define TEXTURES_HPP

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>


class Textures {
public:
    Textures() {
        loadShipTexture();
        loadAsteroidTexture();
        loadBulletTexture();
    }

    void loadShipTexture() {
        for (size_t i = 1; i <= 2; i++) {
            sf::Texture shipTexture;
            if (!shipTexture.loadFromFile("..\\rec\\ship" + std::to_string(i) + ".png")) {
                throw std::runtime_error("Can't load ship texture from file");
            }

            shipTextures.push_back(shipTexture);
        }
    }

    void loadAsteroidTexture() {
        for (size_t i = 1; i <= 3; i++) {
            sf::Texture asteroidTexture;
            if (!asteroidTexture.loadFromFile("..\\rec\\asteroid" + std::to_string(i) + ".png")) {
                throw std::runtime_error("Can't load asteroid texture from file");
            }

            asteroidTextures.push_back(asteroidTexture);
        }
    }

    void loadBulletTexture() {
        if (!bulletTexture.loadFromFile("..\\rec\\bullet.png")) {
            throw std::runtime_error("Can't load bullet texture from file");
        }
    }

    std::vector<sf::Texture> &getShipTextures() {
        return shipTextures;
    }

    std::vector<sf::Texture> &getAsteroidTextures() {
        return asteroidTextures;
    }

    sf::Texture &getBulletTexture() {
        return bulletTexture;
    }

private:
    std::vector<sf::Texture> shipTextures;
    std::vector<sf::Texture> asteroidTextures;
    sf::Texture bulletTexture;
};

#endif // TEXTURES_HPP
