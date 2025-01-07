#include <gtest/gtest.h>

#include "Game.hpp"

class GameTest: public ::testing::Test {
protected:
    sf::RenderWindow window;
    Game* game;

    void SetUp() override {
        window.create(sf::VideoMode(800, 600), "Test Window");
        game = new Game(window);
    }

    void TearDown() override {
        delete game;
        window.close();
    }
};

TEST_F(GameTest, InitialScoreIsZero) {
    EXPECT_EQ(game->getScore(), 0);
}

TEST_F(GameTest, GameOverWhenShipCollidesWithAsteroid) {
    game->spawnShip();
    game->spawnAsteroid();
    game->moveShipToAsteroid();
    game->checkCollisions();
    EXPECT_TRUE(game->isGameOver());
}

TEST_F(GameTest, ScoreIncreasesWhenBulletHitsAsteroid) {
    game->spawnBullet();
    game->spawnAsteroid();
    game->moveBulletToAsteroid();
    game->checkCollisions();
    EXPECT_EQ(game->getScore(), 1);
}

TEST_F(GameTest, AsteroidRemovedWhenOutOfBounds) {
    game->spawnAsteroid();
    game->moveAsteroidOutOfBounds();
    game->checkAsteroidOutOfBounds();
    EXPECT_TRUE(game->getAsteroids().empty());
}

TEST_F(GameTest, BulletRemovedWhenOutOfBounds) {
    game->spawnBullet();
    game->moveBulletOutOfBounds();
    game->checkBulletOutOfBounds();
    EXPECT_TRUE(game->getBullets().empty());
}

TEST_F(GameTest, GameSpeedIncreasesWithScore) {
    int initialSpeed = game->getGameSpeed();
    game->increaseScore();
    game->increaseGameSpeed();
    EXPECT_GT(game->getGameSpeed(), initialSpeed);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}