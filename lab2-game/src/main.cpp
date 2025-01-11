#include "Starter.hpp"

#include <SFML/Graphics.hpp>

int main() {
    // Инициализация окна
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Astro Shooter");
    window.setFramerateLimit(60);

    // Инициализация игрового движка
    Starter start(window);
    start.run();

    return 0;
}
