#ifndef GAMEPRINTER_HPP
#define GAMEPRINTER_HPP

#include <vector>
#include <string>

#include <SFML/Graphics.hpp>

#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"
#include "Textures.hpp"
#include "Text.hpp"
#include "Button.hpp"
#include "Menu.hpp"
#include "BackgroundElement.hpp"

class PrinterExceptions : public std::exception {
 public:
    explicit PrinterExceptions(const std::string &message) : message(message) {}

    const char *what() const noexcept override;
 private:
    std::string message;
};

const char* PrinterExceptions::what() const noexcept {
    return message.c_str();
}

namespace PrinterValues {
    const sf::Vector2f DEFAULT_SCORE_POSITION   = {10, 10};
    const size_t DEFAULT_SCORE_SIZE             = 30;
    const size_t DEFAULT_GAME_OVER_SIZE         = 50;
    const size_t DEFAULT_SCORE_GAME_OVER_SIZE   = 30;
    const float GAME_OVER_SCREEN_TIME           = 3.0f;
}

class Printer {
 public:
    explicit Printer(sf::RenderWindow &window);

    void printGame(sf::Font &fontScore, size_t score, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets);

    void printScore(sf::Font &fontScore, size_t score);

    void printShip(Ship &ship);

    void printAsteroids(std::vector<Asteroid> &asteroids);

    void printBullets(std::vector<Bullet> &bullets);

    void printGameOverScreen(sf::Font &fontGameOver, sf::Font &fontScore, size_t score);

    void printButton(Button &button);

    void printMenu(Menu &menu);

    void printBackground(std::vector<BackgroundElement> &background);

 protected:
    sf::RenderWindow &window;

    struct GameValues {
        sf::Vector2f scorePosition;
        size_t scoreSize;
    } gameValues;

    struct GameOverValues {
        size_t gameOverSize;
        size_t scoreSize;
    } gameOverValues;

    void printGameOver(sf::Font &fontGameOver);
    void printGameOverScore(sf::Font &fontScore, size_t score);
};

Printer::Printer(sf::RenderWindow &window): window(window) {
    gameValues.scorePosition = PrinterValues::DEFAULT_SCORE_POSITION;
    gameValues.scoreSize = PrinterValues::DEFAULT_SCORE_SIZE;

    gameOverValues.gameOverSize = PrinterValues::DEFAULT_GAME_OVER_SIZE;
    gameOverValues.scoreSize = PrinterValues::DEFAULT_SCORE_GAME_OVER_SIZE;
}

void Printer::printShip(Ship &ship) {
    window.draw(ship.getShape());
}

void Printer::printAsteroids(std::vector<Asteroid> &asteroids) {
    for (auto &asteroid : asteroids) {
        window.draw(asteroid.getShape());
    }
}

void Printer::printBullets(std::vector<Bullet> &bullets) {
    for (auto &bullet : bullets) {
        window.draw(bullet.getShape());
    }
}

void Printer::printGame(sf::Font &fontScore, size_t score, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets) {
    printShip(ship);

    printAsteroids(asteroids);

    printBullets(bullets);

    printScore(fontScore, score);
}

void Printer::printScore(sf::Font &font, size_t score) {
    sf::Text text(font, "Score: " + std::to_string(score), gameValues.scoreSize);

    text.setFillColor(sf::Color::White);
    text.setPosition(gameValues.scorePosition);

    window.draw(text);
}

void Printer::printGameOverScreen(sf::Font &fontGameOver, sf::Font &fontScore, size_t score) {
    printGameOver(fontGameOver);
    printGameOverScore(fontScore, score);
}

void Printer::printGameOver(sf::Font &font) {
    sf::Text text(font, "Game over", gameOverValues.gameOverSize);

    text.setFillColor(sf::Color::White);
    text.setPosition({window.getSize().x / 2 - text.getGlobalBounds().size.x / 2,
    window.getSize().y / 2 - text.getGlobalBounds().size.y / 2});

    window.draw(text);
}

void Printer::printGameOverScore(sf::Font &font, size_t score) {
    sf::Text scoreText(font, "Score: " + std::to_string(score), gameOverValues.scoreSize);

    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition({window.getSize().x / 2 - scoreText.getGlobalBounds().size.x / 2,
    window.getSize().y / 2 - scoreText.getGlobalBounds().size.y / 2 + gameOverValues.gameOverSize});

    window.draw(scoreText);
}

void Printer::printButton(Button &button) {
    button.draw();
}

void Printer::printMenu(Menu &menu) {
    menu.draw();
}

void Printer::printBackground(std::vector<BackgroundElement> &background) {
    for (auto &element : background) {
        window.draw(element.getShape());
    }
}

#endif  // GAMEPRINTER_HPP
