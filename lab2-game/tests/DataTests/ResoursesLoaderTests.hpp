#ifndef RESOURCES_LOADER_TESTS_HPP
#define RESOURCES_LOADER_TESTS_HPP

#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include "ResoursesLoader.hpp"

class ResourcesLoaderTests : public ::testing::Test {
 protected:
    ResourcesLoader loader;

    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

TEST_F(ResourcesLoaderTests, LoadShipTexture_ValidPath) {
    std::string validPath = "../res/textures/ship";
    ASSERT_NO_THROW({
        auto textures = loader.loadShipTexture(validPath);
        ASSERT_FALSE(textures.empty());
    });
}

TEST_F(ResourcesLoaderTests, LoadShipTexture_InvalidPath) {
    std::string invalidPath = "../res/textures/invalid_ship";
    ASSERT_THROW(loader.loadShipTexture(invalidPath), ResourcesLoaderException);
}

TEST_F(ResourcesLoaderTests, LoadAsteroidTexture_ValidPath) {
    std::string validPath = "../res/textures/asteroid";
    ASSERT_NO_THROW({
        auto textures = loader.loadAsteroidTexture(validPath);
        ASSERT_FALSE(textures.empty());
    });
}

TEST_F(ResourcesLoaderTests, LoadAsteroidTexture_InvalidPath) {
    std::string invalidPath = "../res/textures/invalid_asteroid";
    ASSERT_THROW(loader.loadAsteroidTexture(invalidPath), ResourcesLoaderException);
}

TEST_F(ResourcesLoaderTests, LoadBulletTexture_ValidPath) {
    std::string validPath = "../res/textures/bullet";
    ASSERT_NO_THROW({
        auto textures = loader.loadBulletTexture(validPath);
        ASSERT_FALSE(textures.empty());
    });
}

TEST_F(ResourcesLoaderTests, LoadBulletTexture_InvalidPath) {
    std::string invalidPath = "../res/textures/invalid_bullet";
    ASSERT_THROW(loader.loadBulletTexture(invalidPath), ResourcesLoaderException);
}

TEST_F(ResourcesLoaderTests, LoadFonts_ValidPath) {
    std::string validPath = "../res/fonts";
    ASSERT_NO_THROW({
        auto fonts = loader.loadFonts(validPath);
        ASSERT_FALSE(fonts.empty());
    });
}

TEST_F(ResourcesLoaderTests, LoadFonts_InvalidPath) {
    std::string invalidPath = "../res/fonts/invalid";
    ASSERT_THROW(loader.loadFonts(invalidPath), ResourcesLoaderException);
}

#endif // RESOURCES_LOADER_TESTS_HPP