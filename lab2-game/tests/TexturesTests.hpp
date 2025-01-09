#include <gtest/gtest.h>
#include "Textures.hpp"

TEST(TexturesTest, LoadShipTextures) {
    Textures textures;
    auto shipTextures = textures.getShipTextures();
    ASSERT_EQ(shipTextures.size(), 2);
    for (const auto& texture : shipTextures) {
        EXPECT_GT(texture.getSize().x, 0);
        EXPECT_GT(texture.getSize().y, 0);
    }
}

TEST(TexturesTest, LoadAsteroidTextures) {
    Textures textures;
    auto asteroidTextures = textures.getAsteroidTextures();
    ASSERT_EQ(asteroidTextures.size(), 3);
    for (const auto& texture : asteroidTextures) {
        EXPECT_GT(texture.getSize().x, 0);
        EXPECT_GT(texture.getSize().y, 0);
    }
}

TEST(TexturesTest, LoadBulletTexture) {
    Textures textures;
    auto& bulletTexture = textures.getBulletTextures();
    EXPECT_GT(bulletTexture.size(), 0);
    EXPECT_GT(bulletTexture.back().getSize().x, 0);
    EXPECT_GT(bulletTexture.back().getSize().y, 0);
}

TEST(TexturesTest, LoadShipTextureException) {
    Textures textures;
    EXPECT_NO_THROW({
        Textures texturesWithException;
        texturesWithException.loadShipTexture();
    });
}

TEST(TexturesTest, LoadAsteroidTextureException) {
    Textures textures;
    EXPECT_NO_THROW({
        Textures texturesWithException;
        texturesWithException.loadAsteroidTexture();
    });
}

TEST(TexturesTest, LoadBulletTextureException) {
    Textures textures;
    EXPECT_NO_THROW({
        Textures texturesWithException;
        texturesWithException.loadBulletTexture();
    });
}
