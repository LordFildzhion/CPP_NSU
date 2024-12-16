#include "Map/Map.hpp"


#include <gtest/gtest.h>
TEST(MapTest, DefaultConstructor) {
    Map map;
    EXPECT_EQ(map.getPixel(0, 0).getColor(), color::NOT_COLOR);
    EXPECT_EQ(map.getPixel(2047, 2047).getColor(), color::NOT_COLOR);
}

TEST(MapTest, SetPixel) {
    Map map;
    map.setPixel(0, 0, color::RED);
    EXPECT_EQ(map.getPixel(0, 0).getColor(), color::RED);

    map.setPixel(std::make_pair(1, 1), color::GREEN);
    EXPECT_EQ(map.getPixel(1, 1).getColor(), color::GREEN);
}

TEST(MapTest, SetPixels) {
    Map map;
    std::vector<std::pair<int64_t, int64_t>> coords = {{0, 0}, {1, 1}, {2, 2}};
    map.setPixels(coords, color::BLUE);

    for (const auto& coord : coords) {
        EXPECT_EQ(map.getPixel(coord.first, coord.second).getColor(), color::BLUE);
    }
}

TEST(MapTest, GetPixels) {
    Map map;
    std::vector<std::pair<int64_t, int64_t>> coords = {{0, 0}, {1, 1}, {2, 2}};
    map.setPixels(coords, color::YELLOW);

    auto pixels = map.getPixels(coords);
    for (size_t i = 0; i < coords.size(); i++) {
        EXPECT_EQ(pixels[i][0].getColor(), color::YELLOW);
    }
}

TEST(MapTest, GetVisiblePixels) {
    Map map;
    auto visiblePixels = map.getVisiblePixels();
    EXPECT_EQ(visiblePixels.size(), 1024);
    EXPECT_EQ(visiblePixels[0].size(), 1024);
    EXPECT_EQ(visiblePixels[0][0].getColor(), color::NOT_COLOR);
}

TEST(MapTest, GetAllPixels) {
    Map map;
    auto allPixels = map.getAllPixels();
    EXPECT_EQ(allPixels.size(), 2048);
    EXPECT_EQ(allPixels[0].size(), 2048);
    EXPECT_EQ(allPixels[0][0].getColor(), color::NOT_COLOR);
}

TEST(MapTest, ConstructorWithParameters) {
    Map map(512, 512, 1024, 1024);
    EXPECT_EQ(map.getPixel(0, 0).getColor(), color::NOT_COLOR);
    EXPECT_EQ(map.getPixel(1023, 1023).getColor(), color::NOT_COLOR);
    EXPECT_EQ(map.getVisiblePixels().size(), 512);
    EXPECT_EQ(map.getVisiblePixels()[0].size(), 512);
}
