#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Menu.hpp"
#include "Game.hpp"
#include "BackGround.hpp"

class GameStarter {
 public:
    explicit GameStarter(sf::RenderWindow &window) : window(window) {}

    void run();

 private:
    sf::RenderWindow &window;
};

void GameStarter::run() {
    std::cout << "GameStarter run" << std::endl;

    // Задержка перед выходом из игры
    // (для того, чтобы не выйти случайно при нажатии на Esc)
    const float buttonDelay = 0.25f;
    sf::Clock exitClock;
    sf::Clock startClock;

    Menu menu(window);
    BackGround background(window);
    std::cout << "Menu created" << std::endl;

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
        && exitClock.getElapsedTime().asSeconds() > buttonDelay) {
            window.close();
            std::cout << "Game closed from menu with Esc" << std::endl;
            break;
        }

        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
                std::cout << "Game closed" << std::endl;
            }
        }

        window.clear();
        background.update();
        menu.draw();
        window.display();

        if (menu.isStartButtonPressed() || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            startClock.restart();
            std::cout << "Start button pressed" << std::endl;
            window.clear();

            while (!background.backroundIsCompleted()) {

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && startClock.getElapsedTime().asSeconds() > buttonDelay) {
                    break;
                }

                while (std::optional event = window.pollEvent()) {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                        std::cout << "Game closed" << std::endl;
                    }
                }

                window.clear();
                background.update();
                window.display();
            }
            

            Game game(window, background);
            game.run();

            std::cout << "Game ended" << std::endl;

            exitClock.restart();

            background.restart();
        }

        if (menu.isExitButtonPressed()) {
            std::cout << "Exit button pressed" << std::endl;
            window.close();
            std::cout << "Game closed from menu" << std::endl;
        }
    }
}

#endif  // GAMEENGINE_HPP
