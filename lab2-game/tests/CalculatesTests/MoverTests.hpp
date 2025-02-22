#ifndef MOVER_TESTS_HPP
#define MOVER_TESTS_HPP

#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include "Mover.hpp"

class MoverTests : public ::testing::Test {
protected:
    sf::RenderWindow window;
    Mover* mover;
    GameSpeed* gameSpeed;

    MoverTests() : window(sf::VideoMode({800, 600}), "Test Window") {
        gameSpeed = GameSpeed::getInstance();
        mover = new Mover(window);
    }

    ~MoverTests() override {
        delete mover;
    }

    void SetUp() override {
        gameSpeed->getInstance();
    }
};

TEST_F(MoverTests, MoveBulletTest) {
    std::vector<Bullet> bullets;
    bullets.emplace_back(Bullet(100, 100));

    mover->moveBullet(bullets);

    ASSERT_FLOAT_EQ(bullets.front().getPosition().y, 100 - MoverValues::DEFAULT_BULLET_MOVE_SPEED * gameSpeed->getGameSpeed());
}

TEST_F(MoverTests, MoveAsteroidsTest) {
    std::vector<Asteroid> asteroids;
    asteroids.emplace_back(Asteroid(sf::Vector2f(100, 100)));

    mover->moveAsteroids(asteroids);

    ASSERT_FLOAT_EQ(asteroids.front().getPosition().y, 100 + MoverValues::DEFAULT_ASTEROID_MOVE_SPEED * gameSpeed->getGameSpeed());
}

TEST_F(MoverTests, MoveShipLeftTest) {
    Ship ship;

    ship.setPosition(100, 100);

    mover->moveShip(ship, sf::Keyboard::Key::Left);

    ASSERT_FLOAT_EQ(ship.getPosition().x, 100 - MoverValues::DEFAULT_SHIP_MOVE_SPEED * gameSpeed->getGameSpeed());
}

TEST_F(MoverTests, MoveShipRightTest) {
    Ship ship;
    ship.setPosition(100, 100);

    mover->moveShip(ship, sf::Keyboard::Key::Right);

    ASSERT_FLOAT_EQ(ship.getPosition().x, 100 + MoverValues::DEFAULT_SHIP_MOVE_SPEED * gameSpeed->getGameSpeed());
}

TEST_F(MoverTests, AddGameSpeedTest) {
    float initialSpeed = gameSpeed->getGameSpeed();
    mover->addGameSpeed(0.5f);

    ASSERT_FLOAT_EQ(gameSpeed->getGameSpeed(), initialSpeed + 0.5f);
}

TEST_F(MoverTests, MoveBackgroundTest) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    std::vector<BackgroundElement> elements;
    elements.emplace_back(BackgroundElement(window));

    sf::Vector2f position = elements.front().getShape().getPosition();

    mover->moveBackground(elements);

    ASSERT_FLOAT_EQ(elements.front().getShape().getPosition().x, position.x - MoverValues::DEFAULT_BACKGROUND_MOVE_SPEED);
}

#endif  // MOVER_TESTS_HPP