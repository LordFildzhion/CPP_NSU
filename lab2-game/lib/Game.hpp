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
    GamePrinter(sf::RenderWindow &window, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, size_t &score) : window(window), ship(ship), asteroids(asteroids), bullets(bullets), score(score) {}

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
        if (!font.openFromFile("D:\\Progs\\CC++\\CPP_NSU\\lab2-game\\rec\\arialmt.ttf")) {
            throw std::runtime_error("Can't load font from file");
        }
        sf::Text text(font, "Score: " + std::to_string(score), 30);
        text.setFillColor(sf::Color::White);
        text.setPosition({10, 10});
        window.draw(text);
    }

private:

    sf::RenderWindow &window;
    Ship &ship;
    std::vector<Asteroid> &asteroids;
    std::vector<Bullet> &bullets;
    size_t &score;
};

class GameOverPrinter {
public:
    GameOverPrinter(sf::RenderWindow &window, size_t &score) : window(window), score(score) {}

    void printGameOver() {
        sf::Font font;
        if (!font.openFromFile("D:\\Progs\\CC++\\CPP_NSU\\lab2-game\\rec\\arialmt.ttf")) {
            throw std::runtime_error("Can't load font from file");
        }
        sf::Text text(font, "Game over", 50);
        text.setFillColor(sf::Color::White);
        text.setPosition({window.getSize().x / 2 - text.getGlobalBounds().size.x / 2, window.getSize().y / 2 - text.getGlobalBounds().size.y / 2});
        window.draw(text);
    }

    void printGameOverScore() {
        sf::Font font;
        if (!font.openFromFile("D:\\Progs\\CC++\\CPP_NSU\\lab2-game\\rec\\arialmt.ttf")) {
            throw std::runtime_error("Can't load font from file");
        }
        sf::Text scoreText(font, "Score: " + std::to_string(score), 30);
        scoreText.setFillColor(sf::Color::White);
        scoreText.setPosition({window.getSize().x / 2 - scoreText.getGlobalBounds().size.x / 2, window.getSize().y / 2 - scoreText.getGlobalBounds().size.y / 2 + 50});
        window.draw(scoreText);
    }

private:
    sf::RenderWindow &window;
    size_t &score;
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

    sf::Clock asteroidClock;
    sf::Clock bulletClock;

    size_t score;
    float gameSpeed;
    float asteroidSpeed;
    float bulletSpeed;
    float shipSpeed;
    float asteroidSpawnTime;
    float bulletSpawnTime;
    float gameSpeedParametr;

    bool isGameOver;

    Mover mover;
    Spawner spawner;
    GamePrinter printer;
    GameOverPrinter gameOverPrinter;

    void checkCollisions();

    void increaseGameSpeed();
    void increaseScore();

    void checkAsteroidShipCollision();
    void checkAsteroidBulletCollision();

    void checkAsteroidOutOfBounds();
    void checkBulletOutOfBounds();

    void gameOver();
    void gameOverCheck();

    void moveBulletToAsteroid(Bullet &bullet, Asteroid &asteroid);
    void moveAsteroidOutOfBounds(Asteroid &asteroid);
    void moveBulletOutOfBounds(Bullet &bullet);
    void moveAsteroidToShip(Asteroid &asteroid);
};

void Game::checkCollisions() {
    checkAsteroidShipCollision();
    checkAsteroidBulletCollision();
    checkBulletOutOfBounds();
    checkAsteroidOutOfBounds();
}

void Game::increaseGameSpeed() {
    gameSpeed += score / gameSpeedParametr;
}

void Game::increaseScore() {
    score++;
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
                asteroidSpawnTime -= 0.01f;
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
    window(window), ship(), asteroids(), bullets(), textures(), asteroidClock(), bulletClock(),
    score(0), isGameOver(false), asteroidSpeed(2.0f), bulletSpeed(5.0f), shipSpeed(5.0f),
    gameSpeed(1.0f), asteroidSpawnTime(1.0f), bulletSpawnTime(0.25f), gameSpeedParametr(1000.0f),

    mover(window, textures, asteroids, bullets, ship, asteroidSpeed,
    bulletClock, bulletSpeed, shipSpeed, gameSpeed, asteroidSpawnTime, bulletSpawnTime, gameSpeedParametr),
    
    spawner(window, textures, asteroids, bullets, ship, asteroidSpeed, asteroidClock,
    bulletClock, bulletSpeed, shipSpeed, gameSpeed, asteroidSpawnTime, bulletSpawnTime, gameSpeedParametr),

    printer(window, ship, asteroids, bullets, score),

    gameOverPrinter(window, score) {
    
    srand(time(nullptr));
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

void Game::moveBulletToAsteroid(Bullet &bullet, Asteroid &asteroid) {
    bullet.setPosition(asteroid.getPosition().x, asteroid.getPosition().y);
}

void Game::moveAsteroidOutOfBounds(Asteroid &asteroid) {
    asteroid.setPosition(0, window.getSize().y + 1);
    
}

void Game::moveBulletOutOfBounds(Bullet &bullet) {
    bullet.setPosition(0, -1);
    
}

void Game::moveAsteroidToShip(Asteroid &asteroid) {
    asteroid.setPosition(ship.getPosition().x, ship.getPosition().y);
}

#endif // GAME_HPP
