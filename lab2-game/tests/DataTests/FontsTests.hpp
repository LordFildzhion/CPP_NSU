#ifndef FONTS_TESTS_HPP
#define FONTS_TESTS_HPP

#include <gtest/gtest.h>
#include "Fonts.hpp"

class FontsTest : public ::testing::Test {
protected:
    void SetUp() override {
        fonts = Fonts::getInstance();
    }

    Fonts* fonts;
};

TEST_F(FontsTest, SingletonInstance) {
    Fonts* instance1 = Fonts::getInstance();
    Fonts* instance2 = Fonts::getInstance();
    ASSERT_EQ(instance1, instance2);
}

TEST_F(FontsTest, LoadFonts) {
    fonts->loadFonts("../res/fonts");
    std::vector<sf::Font>& loadedFonts = fonts->getFonts();
    ASSERT_FALSE(loadedFonts.empty());
}

TEST_F(FontsTest, GetFonts) {
    std::vector<sf::Font> loadedFonts = fonts->getFonts();
    ASSERT_FALSE(loadedFonts.empty());
}

#endif  // FONTS_TESTS_HPP