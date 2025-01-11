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
#include "Printer.hpp"
#include "Background.hpp"
#include "Fonts.hpp"

#include "GameSpeed.hpp"

namespace GameValues {
    const float GAME_SPEED_PARAMETR     = 1000.0f;
    const size_t GAME_OVER_SCREEN_TIME  = 3;
    const size_t START_SCORE            = 0;
}

class Game {
 public:
    explicit Game(sf::RenderWindow &window);

    void run();

 protected:
    sf::RenderWindow &window;

    Ship ship;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;

    size_t score;
    float gameSpeedParametr;

    bool isGameOver;

    Mover mover;
    Spawner spawner;
    Printer printer;

    Background *background;
    Fonts* fonts;

    void increaseGame();
    void increaseGameSpeed();
    void increaseScore();
    void increaseAsteroidSpawnTime();

    void checkCollisions();
    void checkAsteroidShipCollision();
    void checkAsteroidBulletCollision();
    void checkAsteroidOutOfBounds();
    void checkBulletOutOfBounds();

    void gameOver();
    void gameOverCheck();
};

Game::Game(sf::RenderWindow &window): window(window), mover(window), spawner(window), printer(window) {
    background = Background::getInstance(window);

    fonts = Fonts::getInstance();

    srand(time(nullptr));

    score = GameValues::START_SCORE;
    gameSpeedParametr = GameValues::GAME_SPEED_PARAMETR;
    isGameOver = false;
}

void Game::run() {
    spawner.spawnShip(ship);

    while (window.isOpen() && !isGameOver) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.clear();
            break;
        }

        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                return;
            }
        }

        window.clear();

        mover.moveShip(ship);

        spawner.spawnBullet(ship, bullets);
        mover.moveBullet(bullets);

        spawner.spawnAsteroid(asteroids);
        mover.moveAsteroids(asteroids);

        checkCollisions();

        gameOverCheck();

        background->update();

        printer.printGame(fonts->getFonts().front(), score, ship, asteroids, bullets);

        window.display();
    }
}

void Game::increaseGame() {
    increaseGameSpeed();
    increaseScore();
    increaseAsteroidSpawnTime();
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
    spawner.addAsteroidSpawnTime();
}

void Game::checkAsteroidShipCollision() {
    for (auto &asteroid : asteroids) {
        if (asteroid.getShape().getGlobalBounds().findIntersection(ship.getShape().getGlobalBounds())) {
            window.clear();
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
                increaseGame();
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

    printer.printGameOverScreen(fonts->getFonts().front(), fonts->getFonts().front(), score);

    window.display();

    sf::sleep(sf::seconds(GameValues::GAME_OVER_SCREEN_TIME));
    window.clear();
}

void Game::gameOverCheck() {
    if (isGameOver) {
        window.clear();
        gameOver();
    }
}

#endif  // GAME_HPP
