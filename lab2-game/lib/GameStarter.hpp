#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Menu.hpp"
#include "Game.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

class GameStarter {
public:
    GameStarter(sf::RenderWindow &window) : window(window) {}

    void run();

private:
    sf::RenderWindow &window;
};

void GameStarter::run() {
    std::cout << "GameStarter run" << std::endl;

    // Задержка перед выходом из игры (для того, чтобы не выйти случайно при нажатии на Esc)
    const float exitTime = 0.25f;
    sf::Clock exitClock;

    Menu menu(window);
    std::cout << "Menu created" << std::endl;

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
        && exitClock.getElapsedTime().asSeconds() > exitTime) {
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
        menu.draw();
        window.display();

        if (menu.isStartButtonPressed()) {
            std::cout << "Start button pressed" << std::endl;
            window.clear();

            Game game(window);
            game.run();

            std::cout << "Game ended" << std::endl;

            exitClock.restart();
        }

        if (menu.isExitButtonPressed()) {
            std::cout << "Exit button pressed" << std::endl;
            window.close();
            std::cout << "Game closed from menu" << std::endl;
        }
    }
}

#endif // GAMEENGINE_HPP
