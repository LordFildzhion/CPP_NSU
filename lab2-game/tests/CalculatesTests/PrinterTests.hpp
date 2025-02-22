#ifndef PRINTERTESTS_HPP
#define PRINTERTESTS_HPP

#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include "Printer.hpp"


class PrinterTests : public ::testing::Test {
 protected:
    sf::RenderWindow window;
    Printer* printer;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        printer = new Printer(window);
    }

    void TearDown() override {
        delete printer;
        window.close();
    }
};

TEST_F(PrinterTests, PrintShipTest) {
    Ship ship;
    EXPECT_NO_THROW(printer->printShip(ship));
}

TEST_F(PrinterTests, PrintAsteroidsTest) {
    std::vector<Asteroid> asteroids;
    asteroids.push_back(Asteroid(sf::Vector2f(0, 0)));
    asteroids.push_back(Asteroid(sf::Vector2f(1, 1)));
    EXPECT_NO_THROW(printer->printAsteroids(asteroids));
}

TEST_F(PrinterTests, PrintBulletsTest) {
    std::vector<Bullet> bullets;
    bullets.push_back(Bullet(sf::Vector2f(0, 0)));
    bullets.push_back(Bullet(sf::Vector2f(1, 1)));
    EXPECT_NO_THROW(printer->printBullets(bullets));
}

TEST_F(PrinterTests, PrintScoreTest) {
    sf::Font font;
    size_t score = 100;
    EXPECT_NO_THROW(printer->printScore(font, score));
}

TEST_F(PrinterTests, PrintGameOverScreenTest) {
    sf::Font fontGameOver;
    sf::Font fontScore;
    size_t score = 100;
    EXPECT_NO_THROW(printer->printGameOverScreen(fontGameOver, fontScore, score));
}

TEST_F(PrinterTests, PrintButtonTest) {
    sf::RenderWindow window;
    Button button(window, "Test", sf::Font());
    EXPECT_NO_THROW(printer->printButton(button));
}

TEST_F(PrinterTests, PrintMenuTest) {
    sf::RenderWindow window;
    sf::Font font;
    Menu menu(window, font);
    EXPECT_NO_THROW(printer->printMenu(menu));
}

TEST_F(PrinterTests, PrintBackgroundTest) {
    std::vector<BackgroundElement> background;
    background.push_back(BackgroundElement(window));
    EXPECT_NO_THROW(printer->printBackground(background));
}

#endif  // PRINTERTESTS_HPP
