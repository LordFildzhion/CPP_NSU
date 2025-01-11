#ifndef GAME_TESTS_HPP
#define GAME_TESTS_HPP

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>
#include "Game.hpp"

class GameTest : public ::testing::Test {
protected:
    sf::RenderWindow window;
    class TestGame : public Game {
    public:
        explicit TestGame(sf::RenderWindow &window) : Game(window) {}
        void increaseScore() { score++; }
        void increaseGameSpeed() { gameSpeedParametr += 1; }

        using Game::score;
        using Game::gameSpeedParametr;
        using Game::isGameOver;

        using Game::increaseScore;
        using Game::increaseGameSpeed;
        using Game::checkAsteroidOutOfBounds;
        using Game::checkBulletOutOfBounds;
        using Game::gameOverCheck;

        using Game::asteroids;
        using Game::bullets;
    };
    TestGame *game;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Game Test");
        game = new TestGame(window);
    }

    void TearDown() override {
        delete game;
        window.close();
    }
};

TEST_F(GameTest, InitialScoreIsZero) {
    EXPECT_EQ(game->score, GameValues::START_SCORE);
}

TEST_F(GameTest, InitialGameSpeedParametr) {
    EXPECT_FLOAT_EQ(game->gameSpeedParametr, GameValues::GAME_SPEED_PARAMETR);
}

TEST_F(GameTest, GameOverInitiallyFalse) {
    EXPECT_FALSE(game->isGameOver);
}

TEST_F(GameTest, IncreaseScore) {
    size_t initialScore = game->score;
    game->increaseScore();
    EXPECT_EQ(game->score, initialScore + 1);
}

TEST_F(GameTest, IncreaseGameSpeed) {
    float initialSpeed = game->gameSpeedParametr;
    game->increaseGameSpeed();
    EXPECT_GT(game->gameSpeedParametr, initialSpeed);
}

TEST_F(GameTest, CheckAsteroidOutOfBounds) {
    Asteroid asteroid(sf::Vector2f(0, window.getSize().y + 10));
    game->asteroids.push_back(asteroid);
    game->checkAsteroidOutOfBounds();
    EXPECT_TRUE(game->asteroids.empty());
}

TEST_F(GameTest, CheckBulletOutOfBounds) {
    Bullet bullet(sf::Vector2f(0, -10));
    game->bullets.push_back(bullet);
    game->checkBulletOutOfBounds();
    EXPECT_TRUE(game->bullets.empty());
}

TEST_F(GameTest, GameOverCheck) {
    game->isGameOver = true;
    game->gameOverCheck();
    EXPECT_TRUE(game->isGameOver);
}

#endif  // GAME_TESTS_HPP