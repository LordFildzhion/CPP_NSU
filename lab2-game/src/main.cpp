#include "../lib/GameStarter.hpp"

#include <SFML/Graphics.hpp> 

#include <vector> 
#include <cstdlib> 
#include <ctime> 
#include <optional>
#include <iostream>
 
int main() { 
    // Инициализация окна 
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Astro Shooter");
    window.setFramerateLimit(60);

    // Инициализация игрового движка
    GameEngine engine(window);
    engine.run();

    return 0;
}
