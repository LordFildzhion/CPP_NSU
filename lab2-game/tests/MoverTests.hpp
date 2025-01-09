#include <vector>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "Mover.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include "Ship.hpp"

class MoverTest : public ::testing::Test {
 protected:
    sf::RenderWindow window;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    Ship ship;
    float gameSpeed;
    Mover *mover;

    MoverTest() : window(sf::VideoMode({800, 600}), "Test Window"), ship(), gameSpeed(1.0f) {
        mover = new Mover(window, asteroids, bullets, ship, gameSpeed);
    }

    ~MoverTest() override {
        delete mover;
    }

    void SetUp() override {
        asteroids.push_back(Asteroid(10, 10));
        bullets.push_back(Bullet(10, 10));
    }

    void TearDown() override {
        asteroids.clear();
        bullets.clear();
    }
};

TEST_F(MoverTest, MoveBullet) {
    float initialY = bullets[0].getPosition().y;
    mover->moveBullet();
    EXPECT_LT(bullets[0].getPosition().y, initialY);
}

TEST_F(MoverTest, MoveAsteroids) {
    float initialY = asteroids[0].getPosition().y;
    mover->moveAsteroids();
    EXPECT_GT(asteroids[0].getPosition().y, initialY);
}

TEST_F(MoverTest, MoveShipLeft) {
    ship.setPosition(400, 500);
    sf::Keyboard::setVirtualKeyboardVisible(true);
    mover->moveShip(sf::Keyboard::Key::Left);
    EXPECT_LT(ship.getPosition().x, 400);
}

TEST_F(MoverTest, MoveShipRight) {
    ship.setPosition(400, 500);
    sf::Keyboard::setVirtualKeyboardVisible(true);
    mover->moveShip(sf::Keyboard::Key::Right);
    EXPECT_GT(ship.getPosition().x, 400);
}

TEST_F(MoverTest, AddGameSpeed) {
    float initialSpeed = gameSpeed;
    mover->addGameSpeed(0.5f);
    EXPECT_GT(gameSpeed, initialSpeed);
}
