#ifndef TEXTURESTESTS_HPP
#define TEXTURESTESTS_HPP

#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>

#include "Textures.hpp"

class TexturesTests : public ::testing::Test {
 protected:
    void SetUp() override {
        textures = Textures::getInstance();
    }

    Textures* textures;
};

TEST_F(TexturesTests, SingletonInstance) {
    Textures* instance1 = Textures::getInstance();
    Textures* instance2 = Textures::getInstance();
    ASSERT_EQ(instance1, instance2);
}

TEST_F(TexturesTests, LoadShipTextures) {
    textures->loadShipTexture();
    auto shipTextures = textures->getShipTextures();
    ASSERT_FALSE(shipTextures.empty());
}

TEST_F(TexturesTests, LoadAsteroidTextures) {
    textures->loadAsteroidTexture();
    auto asteroidTextures = textures->getAsteroidTextures();
    ASSERT_FALSE(asteroidTextures.empty());
}

TEST_F(TexturesTests, LoadBulletTextures) {
    textures->loadBulletTexture();
    auto bulletTextures = textures->getBulletTextures();
    ASSERT_FALSE(bulletTextures.empty());
}

TEST_F(TexturesTests, LoadShipTexturesWithInvalidPath) {
    EXPECT_THROW(textures->loadShipTexture("invalid/path"), ResourcesLoaderException);
}

TEST_F(TexturesTests, LoadAsteroidTexturesWithInvalidPath) {
    ASSERT_THROW(textures->loadAsteroidTexture("invalid/path"), ResourcesLoaderException);
}

TEST_F(TexturesTests, LoadBulletTexturesWithInvalidPath) {
    ASSERT_THROW(textures->loadBulletTexture("invalid/path"), ResourcesLoaderException);
}

#endif  // TEXTURESTESTS_HPP
