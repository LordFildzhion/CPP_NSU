#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Figure/figure.hpp"
#include "Map/map.hpp"
#include "Pixel/pixel.hpp"

class Engine {
public:
    Engine();
    ~Engine();

    void start();
    void stop();

    void update();

    void render();

    void setMap(Map* map);

    void setFigure(Figure* figure);

    void setPixel(Pixel* pixel);

    void setSpeed(int speed);

    void setScore(int score);

    void setGameOver(bool gameOver);

    void setPause(bool pause);

    void setWin(bool win);

    Map getMap();

    int getSpeed();

    int getScore();

    bool getGameOver();

    bool getPause();

    bool getWin();

 private:
    Map map;
    std::vector <Figure> figures;

    int32_t speed;
    size_t score;

    bool game_over;

    bool pause;
    bool win;
};

Engine::Engine() {
    speed = 1;
    score = 0;
    game_over = false;
    pause = false;
    win = false;
}

Engine::~Engine() = default;

void Engine::start() {
    
}

#endif // ENGINE_HPP