#include <vector>
#include <string>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "GamePrinter.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"

class GamePrinterTest : public GamePrinter {
 public:
    GamePrinterTest(sf::RenderWindow &window, Ship &ship, std::vector<Asteroid> &asteroids, std::vector<Bullet> &bullets, size_t &score, const std::string &fontPath)
        : GamePrinter(window, ship, asteroids, bullets, score, fontPath) {}

    using GamePrinter::printGameOver;
    using GamePrinter::printGameOverScore;
    using GamePrinter::printScore;
};

TEST(GamePrinterTest, PrintScoreTest) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Ship ship;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    size_t score = 100;
    std::string fontPath = "..\\rec\\fonts\\arialmt.ttf";

    GamePrinterTest gamePrinter(window, ship, asteroids, bullets, score, fontPath);

    EXPECT_NO_THROW(gamePrinter.printScore());
}

TEST(GamePrinterTest, PrintGameOverTest) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Ship ship;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    size_t score = 100;
    std::string fontPath = "..\\rec\\fonts\\arialmt.ttf";

    GamePrinterTest gamePrinter(window, ship, asteroids, bullets, score, fontPath);

    EXPECT_NO_THROW(gamePrinter.printGameOver());
}

TEST(GamePrinterTest, PrintGameOverScoreTest) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Ship ship;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    size_t score = 100;
    std::string fontPath = "..\\rec\\fonts\\arialmt.ttf";

    GamePrinterTest gamePrinter(window, ship, asteroids, bullets, score, fontPath);

    EXPECT_NO_THROW(gamePrinter.printGameOverScore());
}

TEST(GamePrinterTest, PrintGameTest) {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Test Window");
    Ship ship;
    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    size_t score = 100;
    std::string fontPath = "..\\rec\\fonts\\arialmt.ttf";

    GamePrinterTest gamePrinter(window, ship, asteroids, bullets, score, fontPath);

    EXPECT_NO_THROW(gamePrinter.printGame());
}
