#include <gtest/gtest.h>

#include "GameStarter.hpp"

TEST(GameStarter, GameStarterRun) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Game");
    GameStarter GameStarter(window);
    GameStarter.run();
}
