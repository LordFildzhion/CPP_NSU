#ifndef GAMESPEEDTESTS_HPP
#define GAMESPEEDTESTS_HPP

#include <gtest/gtest.h>
#include "GameSpeed.hpp"

class GameSpeedTests : public ::testing::Test {
 protected:
    void SetUp() override {
        GameSpeed::getInstance()->increaseGameSpeed(-GameSpeed::getInstance()->getGameSpeed() + GameSpeedValues::DEFAULT_GAME_SPEED);
    }
};

TEST_F(GameSpeedTests, DefaultGameSpeed) {
    GameSpeed* gameSpeed = GameSpeed::getInstance();
    EXPECT_FLOAT_EQ(gameSpeed->getGameSpeed(), GameSpeedValues::DEFAULT_GAME_SPEED);
}

TEST_F(GameSpeedTests, IncreaseGameSpeed) {
    GameSpeed* gameSpeed = GameSpeed::getInstance();
    gameSpeed->increaseGameSpeed(0.5f);
    EXPECT_FLOAT_EQ(gameSpeed->getGameSpeed(), GameSpeedValues::DEFAULT_GAME_SPEED + 0.5f);
}

TEST_F(GameSpeedTests, IncreaseGameSpeedMultipleTimes) {
    GameSpeed* gameSpeed = GameSpeed::getInstance();
    gameSpeed->increaseGameSpeed(0.5f);
    gameSpeed->increaseGameSpeed(1.0f);
    EXPECT_FLOAT_EQ(gameSpeed->getGameSpeed(), GameSpeedValues::DEFAULT_GAME_SPEED + 1.5f);
}

#endif  // GAMESPEEDTESTS_HPP
