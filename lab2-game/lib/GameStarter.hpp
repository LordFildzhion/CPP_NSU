#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include "Menu.hpp"
#include "Game.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>

class GameEngine {
public:
    GameEngine(sf::RenderWindow &window) : window(window) {}

    void run() {
        std::cout << "GameEngine run" << std::endl;

        const float exitTime = 0.25f;

        sf::Clock exitClock;

        Menu menu(window);
        std::cout << "Menu created" << std::endl;

        while (window.isOpen()) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
            && exitClock.getElapsedTime().asSeconds() > exitTime) {
                std::cout << "Exit button pressed" << std::endl;
                window.close();
                std::cout << "Game closed from menu" << std::endl;
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

                exitClock.restart();
            }

            if (menu.isExitButtonPressed()) {
                window.close();
            }
        }
    }

private:
    sf::RenderWindow &window;
};


#endif // GAMEENGINE_HPP