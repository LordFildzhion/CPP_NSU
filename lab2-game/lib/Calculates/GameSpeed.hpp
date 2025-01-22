#ifndef GAMESPEED_HPP
#define GAMESPEED_HPP

#include <SFML/Graphics.hpp>

namespace GameSpeedValues {
    static const float DEFAULT_GAME_SPEED = 1.0f;
}

class GameSpeed {
 public:
    static GameSpeed* getInstance();

    void increaseGameSpeed(float increase);

    float getGameSpeed() const;

 private:
    GameSpeed();
    ~GameSpeed();

    GameSpeed(const GameSpeed&) = delete;
    GameSpeed& operator=(const GameSpeed&) = delete;

    float gameSpeed;

    static GameSpeed *instance;
};

GameSpeed* GameSpeed::instance = nullptr;

GameSpeed::GameSpeed() {
    gameSpeed = GameSpeedValues::DEFAULT_GAME_SPEED;
}

GameSpeed* GameSpeed::getInstance() {
    if (instance == nullptr) {
        instance = new GameSpeed();
    }
    return instance;
}

void GameSpeed::increaseGameSpeed(float increase) {
    gameSpeed += increase;
}

float GameSpeed::getGameSpeed() const {
    return gameSpeed;
}

GameSpeed::~GameSpeed() {
    delete instance;
}

#endif  // GAMESPEED_HPP
