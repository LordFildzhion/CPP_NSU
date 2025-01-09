#ifndef GAMEPRINTER_HPP
#define GAMEPRINTER_HPP

#include <vector>
#include <cstdlib>
#include <ctime>
#include <optional>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Textures.hpp"

class GamePrinterExceptions : public std::exception {
public:
    explicit GamePrinterExceptions(const std::string &message) : message(message) {}

    const char *what() const noexcept override;

private:
    std::string message;
};

const char* GamePrinterExceptions::what() const noexcept {
    return message.c_str();
}

class GamePrinter {
public:
    GamePrinter(sf::RenderWindow &window, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, size_t &score, const std::string &fontPath = "../rec/fonts/arialmt.ttf");

    void printGame();

    void printScore();

    void printGameOverScreen();

protected:
    sf::RenderWindow &window;
    std::string fontPath;

    struct GameValues {
        sf::Vector2f scorePosition;
        size_t scoreSize;
    } gameValues;

    struct GameOverValues {
        size_t gameOverSize;
        size_t scoreSize;
    } gameOverValues;

    Ship &ship;
    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    size_t &score;

    void printGameOver();
    void printGameOverScore();
};

GamePrinter::GamePrinter(sf::RenderWindow &window, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, size_t &score, const std::string &fontPath):
    window(window), ship(ship), asteroids(asteroids), bullets(bullets), score(score), fontPath(fontPath) {
        gameValues.scorePosition = {10, 10};
        gameValues.scoreSize = 30;

        gameOverValues.gameOverSize = 50;
        gameOverValues.scoreSize = 30;
}

void GamePrinter::printGame() {
    window.draw(ship.getShape());
    for (auto &asteroid : asteroids) {
        window.draw(asteroid.getShape());
    }

    for (auto &bullet : bullets) {
        window.draw(bullet.getShape());
    }

    printScore();
}

void GamePrinter::printScore() {
    sf::Font font;
    if (!font.openFromFile(fontPath)) {
        throw GamePrinterExceptions("ERROR!!!\nGAMEPRINTER::PRINTSCORE:Can't load font from file\n");
    }

    sf::Text text(font, "Score: " + std::to_string(score), gameValues.scoreSize);

    text.setFillColor(sf::Color::White);
    text.setPosition(gameValues.scorePosition);

    window.draw(text);
}

void GamePrinter::printGameOverScreen() {
    printGameOver();
    printGameOverScore();
}

void GamePrinter::printGameOver() {
    sf::Font font;
    if (!font.openFromFile(fontPath)) {
        throw GamePrinterExceptions("ERROR!!!\nGAMEPRINTER::PRINTGAMEOVER:Can't load font from file\n");
    }

    sf::Text text(font, "Game over", gameOverValues.gameOverSize);

    text.setFillColor(sf::Color::White);
    text.setPosition({window.getSize().x / 2 - text.getGlobalBounds().size.x / 2,
    window.getSize().y / 2 - text.getGlobalBounds().size.y / 2});

    window.draw(text);
}

void GamePrinter::printGameOverScore() {
    sf::Font font;
    if (!font.openFromFile(fontPath)) {
        throw GamePrinterExceptions("ERROR!!!\nGAMEPRINTER::PRINTGAMEOVERSCORE:Can't load font from file\n");
    }

    sf::Text scoreText(font, "Score: " + std::to_string(score), gameOverValues.scoreSize);

    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({window.getSize().x / 2 - scoreText.getGlobalBounds().size.x / 2,
    window.getSize().y / 2 - scoreText.getGlobalBounds().size.y / 2 + gameOverValues.gameOverSize});

    window.draw(scoreText);
}

#endif // GAMEPRINTER_HPP
