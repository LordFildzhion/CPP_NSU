#ifndef GAME_HPP
#define GAME_HPP

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
#include "Mover.hpp"
#include "Spawner.hpp"

class GamePrinter {
public:
    GamePrinter(sf::RenderWindow &window, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, size_t &score, const std::string &fontPath):
    window(window), ship(ship), asteroids(asteroids), bullets(bullets), score(score), fontPath(fontPath) {
        scorePosition = {10, 10};
        scoreSize = 30;
    }

    void printGame() {
        window.draw(ship.getShape());
        for (auto &asteroid : asteroids) {
            window.draw(asteroid.getShape());
        }

        for (auto &bullet : bullets) {
            window.draw(bullet.getShape());
        }

        printScore();
    }

    void printScore() {
        sf::Font font;
        if (!font.openFromFile(fontPath)) {
            throw std::runtime_error("Can't load font from file");
        }

        sf::Text text(font, "Score: " + std::to_string(score), scoreSize);

        text.setFillColor(sf::Color::White);
        text.setPosition(scorePosition);

        window.draw(text);
    }

private:
    sf::RenderWindow &window;
    std::string fontPath;

    sf::Vector2f scorePosition;
    size_t scoreSize;

    Ship &ship;
    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    size_t &score;
};

class GameOverPrinter {
public:
    GameOverPrinter(sf::RenderWindow &window, size_t &score, const std::string &fontPath) : window(window), score(score), fontPath(fontPath) {
        scoreSize = 30;
        gameOverSize = 50;
    }

    void printGameOver() {
        sf::Font font;
        if (!font.openFromFile(fontPath)) {
            throw std::runtime_error("Can't load font from file");
        }

        sf::Text text(font, "Game over", gameOverSize);

        text.setFillColor(sf::Color::White);
        text.setPosition({window.getSize().x / 2 - text.getGlobalBounds().size.x / 2,
        window.getSize().y / 2 - text.getGlobalBounds().size.y / 2});

        window.draw(text);
    }

    void printGameOverScore() {
        sf::Font font;
        if (!font.openFromFile(fontPath)) {
            throw std::runtime_error("Can't load font from file");
        }

        sf::Text scoreText(font, "Score: " + std::to_string(score), scoreSize);

        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition({window.getSize().x / 2 - scoreText.getGlobalBounds().size.x / 2,
        window.getSize().y / 2 - scoreText.getGlobalBounds().size.y / 2 + gameOverSize});

        window.draw(scoreText);
    }

private:
    sf::RenderWindow &window;
    std::string fontPath;
    size_t &score;
    size_t scoreSize;
    size_t gameOverSize;
};

// Класс игры
class Game {
public:
    Game(sf::RenderWindow &window);
    void run();

private:
    sf::RenderWindow &window;

    Ship ship;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;

    Textures textures;

    size_t score;
    float gameSpeed;
    float gameSpeedParametr;

    bool isGameOver;

    Mover mover;
    Spawner spawner;
    GamePrinter printer;
    GameOverPrinter gameOverPrinter;

    void checkCollisions();

    void increaseGameSpeed();
    void increaseScore();
    void increaseAsteroidSpawnTime();

    void checkAsteroidShipCollision();
    void checkAsteroidBulletCollision();

    void checkAsteroidOutOfBounds();
    void checkBulletOutOfBounds();

    void gameOver();
    void gameOverCheck();

    size_t getScore();
};

size_t Game::getScore() {
    return score;
}

void Game::checkCollisions() {
    checkAsteroidShipCollision();
    checkAsteroidBulletCollision();
    checkBulletOutOfBounds();
    checkAsteroidOutOfBounds();
}

void Game::increaseGameSpeed() {
    mover.addGameSpeed(score / gameSpeedParametr);
}

void Game::increaseScore() {
    score++;
}

void Game::increaseAsteroidSpawnTime() {
    spawner.addAsteroidSpawnTime(-0.01f);
}

void Game::checkAsteroidShipCollision() {
    for (auto &asteroid : asteroids) {
        if (asteroid.getShape().getGlobalBounds().findIntersection (ship.getShape().getGlobalBounds())) {
            window.clear();
            std::cout << "Game over" << std::endl;
            isGameOver = true;
            break;
        }
    }
}

void Game::checkAsteroidBulletCollision() {
    for (size_t i = 0; i < asteroids.size(); i++) {
        for (size_t j = 0; j < bullets.size(); j++) {
            if (asteroids[i].getShape().getGlobalBounds().findIntersection(bullets[j].getShape().getGlobalBounds())) {
                asteroids.erase(asteroids.begin() + i);
                bullets.erase(bullets.begin() + j);
                increaseScore();
                increaseGameSpeed();
                increaseAsteroidSpawnTime();
                break;
            }
        }
    }
}

void Game::checkAsteroidOutOfBounds() {
    for (size_t i = 0; i < asteroids.size(); i++) {
        if (asteroids[i].getPosition().y > window.getSize().y) {
            asteroids.erase(asteroids.begin() + i);
        }
    }
}

void Game::checkBulletOutOfBounds() {
    for (size_t i = 0; i < bullets.size(); i++) {
        if (bullets[i].getPosition().y < 0) {
            bullets.erase(bullets.begin() + i);
        }
    }
}

void Game::gameOver() {
    window.clear();
    
    gameOverPrinter.printGameOver();
    gameOverPrinter.printGameOverScore();
    
    window.display();

    sf::sleep(sf::seconds(3));
    window.clear();
}

void Game::gameOverCheck() {
    if (isGameOver) {
        window.clear();
        std::cout << "Game over" << std::endl;
        gameOver();
    }
}

Game::Game(sf::RenderWindow &window):
    window(window), ship(), asteroids(), bullets(), textures(),

    mover(window, asteroids, bullets, ship, gameSpeed),
    
    spawner(window, textures, asteroids, bullets, ship),

    printer(window, ship, asteroids, bullets, score, "..\\rec\\arialmt.ttf"),

    gameOverPrinter(window, score, "..\\rec\\arialmt.ttf") {
        srand(time(nullptr));
        score = 0;
        gameSpeed = 1.0f;
        gameSpeedParametr = 1000.0f;
        isGameOver = false;
}

void Game::run() {
    std::cout << "Game started" << std::endl;

    spawner.spawnShip();

    while (window.isOpen() && !isGameOver) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.clear();
            std::cout << "Game closed to menu" << std::endl;
            break;
        }

        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                std::cout << "Game closed" << std::endl;
                return;
            }
        }

        window.clear();

        mover.moveShip();

        spawner.spawnBullet();
        mover.moveBullet();

        spawner.spawnAsteroid();
        mover.moveAsteroids();

        checkCollisions();
        
        gameOverCheck();

        printer.printGame();
        printer.printScore();

        window.display();
    }
}

#endif // GAME_HPP
