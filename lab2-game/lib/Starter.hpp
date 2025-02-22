#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Menu.hpp"
#include "Game.hpp"
#include "Background.hpp"
#include "ResoursesLoader.hpp"
#include "Fonts.hpp"
#include "GameSpeed.hpp"

namespace StarterValues {
    const float DEFAULT_BUTTON_DELAY = 0.25f;
}

class Starter {
 public:
    explicit Starter(sf::RenderWindow &window) : window(window) {}

    void run();

 private:
    sf::RenderWindow &window;
};

void Starter::run() {
    const float buttonDelay = StarterValues::DEFAULT_BUTTON_DELAY;
    sf::Clock buttonPressClock;

    Fonts *fonts = Fonts::getInstance();
    fonts->loadFonts();

    Menu menu(window, fonts->getFonts().front());

    GameSpeed *gameSpeed = GameSpeed::getInstance();

    Background *background = Background::getInstance(window);

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)
        && buttonPressClock.getElapsedTime().asSeconds() > buttonDelay) {
            window.close();
            break;
        }

        while (std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        background->update();
        menu.draw();
        window.display();

        if (menu.isButtonPressed("Start") || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            buttonPressClock.restart();
            window.clear();

            while (!background->isCompleted()) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && buttonPressClock.getElapsedTime().asSeconds() > buttonDelay) {
                    break;
                }

                while (std::optional event = window.pollEvent()) {
                    if (event->is<sf::Event::Closed>()) {
                        window.close();
                    }
                }

                window.clear();
                background->update();
                window.display();
            }

            Game game(window);
            game.run();

            buttonPressClock.restart();
            background->restart();
        }

        if (menu.isButtonPressed("Exit")) {
            window.close();
        }
    }
}

#endif  // GAMEENGINE_HPP
