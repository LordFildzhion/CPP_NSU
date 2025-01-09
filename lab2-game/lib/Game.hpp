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
#include "GamePrinter.hpp"


// Класс игры
class Game {
public:
    Game(sf::RenderWindow &window);
    void run();

protected:
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

Game::Game(sf::RenderWindow &window):
    window(window), ship(), asteroids(), bullets(), textures(),

    mover(window, asteroids, bullets, ship, gameSpeed),
    
    spawner(window, textures, asteroids, bullets, ship),

    printer(window, ship, asteroids, bullets, score) {
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
    spawner.addAsteroidSpawnTime(-0.01f);
}

void Game::checkAsteroidShipCollision() {
    for (auto &asteroid : asteroids) {
        if (asteroid.getShape().getGlobalBounds().findIntersection (ship.getShape().getGlobalBounds())) {
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
    
    printer.printGameOverScreen();
    
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

#endif // GAME_HPP
