#ifndef FIGUREGENERATOR_HPP
#define FIGUREGENERATOR_HPP

#include <memory>
#include <random>
#include <stack>
#include <ctime>

#include "Figure.hpp"


class FigureCreator
{
 private:
    std::stack <Figure> figures;
 public:
    FigureCreator();
    
    void createFigure();
    
    Figure createFigure(uint8_t type, uint8_t color, uint8_t rotation, std::pair<int32_t, int32_t> center);
    
    Figure createFigure(Figure figure);
    
    std::vector <Figure> createFigures(size_t count);

    Figure getFigure();
    
    std::vector <Figure> getFigures();
    
    void deleteFigure();

    void deleteFigures(size_t count);
    ~FigureCreator();
};

FigureCreator::FigureCreator() {
    srand(time(NULL));
}

void FigureCreator::createFigure() {
    Figure figure(rand() % 7, rand() % 7, rand() % 4, FigureConstants::DEFAULT_CENTER);
    figures.push(figure);
}

Figure FigureCreator::createFigure(uint8_t type, uint8_t color, uint8_t rotation, std::pair<int32_t, int32_t> center) {
    Figure figure(type, color, rotation, center);
    figures.push(figure);
    return figure;
}

Figure FigureCreator::createFigure(Figure figure) {
    figures.push(figure);
    return figure;
}

std::vector <Figure> FigureCreator::createFigures(size_t count) {
    std::vector <Figure> figures_vector;
    for (size_t i = 0; i < count; i++) {
        createFigure();
        figures_vector.push_back(figures.top());
    }
    return figures_vector;
}

Figure FigureCreator::getFigure() {
    return figures.top();
}

void FigureCreator::deleteFigure() {
    figures.pop();
}

void FigureCreator::deleteFigures(size_t count) {
    for (size_t i = 0; i < count; i++) {
        deleteFigure();
    }
}

std::vector <Figure> FigureCreator::getFigures() {
    std::vector <Figure> figures_vector;
    while (!figures.empty()) {
        figures_vector.push_back(figures.top());
        figures.pop();
    }

    for (size_t i = 0; i < figures_vector.size(); i++) {
        figures.push(figures_vector[i]);
    }

    return figures_vector;
}

FigureCreator::~FigureCreator() = default;


#endif // FIGUREGENERATOR_HPP