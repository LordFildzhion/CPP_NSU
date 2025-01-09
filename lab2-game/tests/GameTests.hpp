#include <vector>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "Game.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Textures.hpp"

// Mock classes for dependencies
class MockWindow : public sf::RenderWindow {
 public:
    bool isOpen() const { return true; }
    bool pollEvent(sf::Event& event) { return false; }
    void clear() {}
    void display() {}
};

class MockShip : public Ship {
 public:
    sf::FloatRect getGlobalBounds() const { return sf::FloatRect({0, 0}, {50, 50}); }
};

class MockAsteroid : public Asteroid {
 public:
    MockAsteroid() : Asteroid(50, 50) {}

    MockAsteroid(float x, float y) : Asteroid(x, y) {}

    sf::FloatRect getGlobalBounds() const { return sf::FloatRect({0, 0}, {50, 50}); }
    sf::Vector2f getPosition() const { return sf::Vector2f({0, 0}); }
};

class MockBullet : public Bullet {
 public:
    MockBullet(sf::Texture &texture, float x, float y) : Bullet(x, y) {}

    sf::FloatRect getGlobalBounds() const { return sf::FloatRect({0, 0}, {10, 10}); }
    sf::Vector2f getPosition() const { return sf::Vector2f({0, 0}); }
};

class MockGame : public Game {
 public:
    explicit MockGame(sf::RenderWindow &window) : Game(window) {}

    void addAsteroid(Asteroid &asteroid) {
        asteroids.push_back(asteroid);
    }

    void addBullet(Bullet &bullet) {
        bullets.push_back(bullet);
    }

    std::vector<Asteroid> &getAsteroids() {
        return asteroids;
    }

    std::vector<Bullet> &getBullets() {
        return bullets;
    }

    Ship &getShip() {
        return ship;
    }

    int getScore() {
        return score;
    }

    float getGameSpeed() {
        return gameSpeed;
    }

    bool checkGameOver() {
        return isGameOver;
    }

    void increaseScore() {
        Game::increaseScore();
    }

    void increaseGameSpeed() {
        Game::increaseGameSpeed();
    }

    void checkAsteroidShipCollision() {
        Game::checkAsteroidShipCollision();
    }

    void checkAsteroidBulletCollision() {
        Game::checkAsteroidBulletCollision();
    }

    void checkAsteroidOutOfBounds() {
        Game::checkAsteroidOutOfBounds();
    }

    void checkBulletOutOfBounds() {
        Game::checkBulletOutOfBounds();
    }

    void setGameOver(bool value) {
        isGameOver = value;
    }

    void setGameSpeed(float value) {
        gameSpeed = value;
    }

    void setScore(int value) {
        score = value;
    }

    void setAsteroids(std::vector<Asteroid> value) {
        asteroids = value;
    }

    void setBullets(std::vector<Bullet> value) {
        bullets = value;
    }
};

TEST(GameTest, InitialState) {
    MockWindow window;
    MockGame game(window);

    EXPECT_EQ(game.getScore(), 0);
    EXPECT_EQ(game.getGameSpeed(), 1.0f);
    EXPECT_FALSE(game.checkGameOver());
}

TEST(GameTest, IncreaseScore) {
    MockWindow window;
    MockGame game(window);

    game.increaseScore();
    EXPECT_EQ(game.getScore(), 1);
}

TEST(GameTest, IncreaseGameSpeed) {
    MockWindow window;
    MockGame game(window);

    game.increaseGameSpeed();
    EXPECT_GT(game.getGameSpeed(), 0.0f);
}

TEST(GameTest, CheckAsteroidShipCollision) {
    MockWindow window;
    MockGame game(window);

    MockAsteroid asteroid;
    asteroid.setPosition(game.getShip().getPosition());
    game.addAsteroid(asteroid);

    game.checkAsteroidShipCollision();
    EXPECT_TRUE(game.checkGameOver());
}

TEST(GameTest, CheckAsteroidBulletCollision) {
    MockWindow window;
    MockGame game(window);

    sf::Texture texture({10, 10});
    MockAsteroid asteroid(10, 10);
    MockBullet bullet(texture, 10, 10);
    game.addAsteroid(asteroid);
    game.addBullet(bullet);

    game.checkAsteroidBulletCollision();
    EXPECT_EQ(game.getAsteroids().size(), 0);
    EXPECT_EQ(game.getBullets().size(), 0);
    EXPECT_EQ(game.getScore(), 1);
}

TEST(GameTest, CheckAsteroidOutOfBounds) {
    MockWindow window;
    MockGame game(window);

    MockAsteroid asteroid;
    game.addAsteroid(asteroid);

    game.checkAsteroidOutOfBounds();
    EXPECT_EQ(game.getAsteroids().size(), 0);
}

TEST(GameTest, CheckBulletOutOfBounds) {
    MockWindow window;
    MockGame game(window);
    sf::Texture texture({10, 10});
    MockBullet bullet(texture, -100, -100);
    game.addBullet(bullet);

    game.checkBulletOutOfBounds();
    EXPECT_EQ(game.getBullets().size(), 0);
}
