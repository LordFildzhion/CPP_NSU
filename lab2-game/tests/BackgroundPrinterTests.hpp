#ifndef BACKGROUND_PRINTER_TESTS_HPP
#define BACKGROUND_PRINTER_TESTS_HPP

#include <vector>

#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

#include "BackgroundPrinter.hpp"
#include "BackgroundElement.hpp"

class BackgroundPrinterTest : public ::testing::Test {
 protected:
    sf::RenderWindow window;
    std::vector<BackGroundElement> elements;
    BackGroundPrinter* printer;

    void SetUp() override {
        window.create(sf::VideoMode({800, 600}), "Test Window");
        elements.emplace_back(BackGroundElement(window));
        elements.emplace_back(BackGroundElement(window));
        printer = new BackGroundPrinter(window, elements);
    }

    void TearDown() override {
        delete printer;
        window.close();
    }
};

TEST_F(BackgroundPrinterTest, PrintElements) {
    ASSERT_NO_THROW(printer->printElements());
}

TEST_F(BackgroundPrinterTest, ElementsSize) {
    ASSERT_EQ(elements.size(), 2);
}

TEST_F(BackgroundPrinterTest, WindowIsOpen) {
    ASSERT_TRUE(window.isOpen());
}

#endif  // BACKGROUND_PRINTER_TESTS_HPP
