#include "Figure/Figure.hpp"
#include "Figure/FigureCreator.hpp"


#include <gtest/gtest.h>

TEST(FigureTests, InitTest) {
    Figure fig(FigureConstants::TYPE_I, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_I);
    EXPECT_EQ(fig.getColor(), color::RED);
    EXPECT_EQ(fig.getRotation(), FigureConstants::FIRST_ROTATION);
    EXPECT_EQ(fig.getPixels().size(), 4);
}

TEST(FigureTests, SetColorTest) {
    Figure fig(FigureConstants::TYPE_O, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    fig.setColor(color::GREEN);
    EXPECT_EQ(fig.getColor(), color::GREEN);
    for (const auto &pix : fig.getPixels()) {
        EXPECT_EQ(pix.getColor(), color::GREEN);
    }
}

TEST(FigureTests, SetTypeTest) {
    Figure fig(FigureConstants::TYPE_I, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    fig.setType(FigureConstants::TYPE_T);
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_T);
    EXPECT_EQ(fig.getPixels().size(), 4);
}

TEST(FigureTests, SetRotationTest) {
    Figure fig(FigureConstants::TYPE_L, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    fig.setRotation(FigureConstants::SECOND_ROTATION);
    EXPECT_EQ(fig.getRotation(), FigureConstants::SECOND_ROTATION);
    fig.setRotation(FigureConstants::THIRD_ROTATION);
    EXPECT_EQ(fig.getRotation(), FigureConstants::THIRD_ROTATION);
    fig.setRotation(FigureConstants::FOURTH_ROTATION);
    EXPECT_EQ(fig.getRotation(), FigureConstants::FOURTH_ROTATION);
}

TEST(FigureTests, SetCenterTest) {
    Figure fig(FigureConstants::TYPE_Z, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    fig.setCenter({2, 2});
    EXPECT_EQ(fig.getCenter(), std::make_pair(2, 2));
}

TEST(FigureTests, AddPixelTest) {
    Figure fig(FigureConstants::TYPE_S, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    Pixel new_pixel({1, 1}, color::RED);
    fig.addPixel(new_pixel);
    EXPECT_EQ(fig.getPixels().size(), 5);
    EXPECT_EQ(fig.getPixels().front().getColor(), color::RED);
    EXPECT_EQ(fig.getPixels().back().getCoordinates(), std::make_pair(1, 1));
}

TEST(FigureTests, AddCoordinatesTest) {
    Figure fig(FigureConstants::TYPE_J, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    std::vector<std::pair<int32_t, int32_t>> new_coords = {{1, 1}, {2, 2}};
    fig.addCoordinates(new_coords);
    EXPECT_EQ(fig.getPixels().size(), 6);
    EXPECT_EQ(fig.getPixels().back().getCoordinates(), std::make_pair(2, 2));
}

TEST(FigureTests, SetCoordinatesTest) {
    Figure fig(FigureConstants::TYPE_I, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    std::vector<std::pair<int32_t, int32_t>> new_coords = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    fig.setCoordinates(new_coords);
    EXPECT_EQ(fig.getPixels().size(), 4);
    EXPECT_EQ(fig.getPixels()[0].getCoordinates(), std::make_pair(1, 1));
    EXPECT_EQ(fig.getPixels()[1].getCoordinates(), std::make_pair(2, 2));
    EXPECT_EQ(fig.getPixels()[2].getCoordinates(), std::make_pair(3, 3));
    EXPECT_EQ(fig.getPixels()[3].getCoordinates(), std::make_pair(4, 4));
}

TEST(FigureTests, SetPixelsTest) {
    Figure fig(FigureConstants::TYPE_I, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    std::vector<Pixel> new_pixels = {Pixel({1, 1}, color::RED), Pixel({2, 2}, color::RED), Pixel({3, 3}, color::RED), Pixel({4, 4}, color::RED)};
    fig.setPixels(new_pixels);
    EXPECT_EQ(fig.getPixels().size(), 4);
    EXPECT_EQ(fig.getPixels()[0].getCoordinates(), std::make_pair(1, 1));
    EXPECT_EQ(fig.getPixels()[1].getCoordinates(), std::make_pair(2, 2));
    EXPECT_EQ(fig.getPixels()[2].getCoordinates(), std::make_pair(3, 3));
    EXPECT_EQ(fig.getPixels()[3].getCoordinates(), std::make_pair(4, 4));
}

TEST(FigureTests, AddPixelsTest) {
    Figure fig(FigureConstants::TYPE_I, 1, FigureConstants::FIRST_ROTATION, {0, 0});
    std::vector<Pixel> new_pixels = {Pixel({1, 1}, color::RED), Pixel({2, 2}, color::RED)};
    fig.addPixels(new_pixels);
    EXPECT_EQ(fig.getPixels().size(), 6);
    EXPECT_EQ(fig.getPixels()[4].getCoordinates(), std::make_pair(1, 1));
    EXPECT_EQ(fig.getPixels()[5].getCoordinates(), std::make_pair(2, 2));
}

TEST(FigureTests, AddCoordinateTest) {
    Figure fig(FigureConstants::TYPE_I, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    fig.addCoordinate({1, 1});
    EXPECT_EQ(fig.getPixels().size(), 5);
    EXPECT_EQ(fig.getPixels().back().getCoordinates(), std::make_pair(1, 1));
}

TEST(FigureCreatorTests, CreateFigureTest) {
    FigureCreator creator;
    Figure fig = creator.createFigure(FigureConstants::TYPE_I, color::RED, FigureConstants::FIRST_ROTATION, {0, 0});
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_I);
    EXPECT_EQ(fig.getColor(), color::RED);
    EXPECT_EQ(fig.getRotation(), FigureConstants::FIRST_ROTATION);
    EXPECT_EQ(fig.getCenter(), std::make_pair(0, 0));
    EXPECT_EQ(fig.getPixels().size(), 4);
}

TEST(FigureCreatorTests, CreateFigureWithAllDefaultsTest) {
    FigureCreator creator;
    Figure fig = creator.createFigure(FigureConstants::TYPE_S);
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_S);
    EXPECT_EQ(fig.getColor(), color::NOT_COLOR);
    EXPECT_EQ(fig.getRotation(), FigureConstants::FIRST_ROTATION);
    EXPECT_EQ(fig.getCenter(), FigureConstants::DEFAULT_CENTER);
    EXPECT_EQ(fig.getPixels().size(), 4);
}
TEST(FigureCreatorTests, CreateFigureWithColorTest) {
    FigureCreator creator;
    Figure fig = creator.createFigure(FigureConstants::TYPE_L, color::BLUE, FigureConstants::FIRST_ROTATION, FigureConstants::DEFAULT_CENTER);
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_L);
    EXPECT_EQ(fig.getColor(), color::BLUE);
    EXPECT_EQ(fig.getRotation(), FigureConstants::FIRST_ROTATION);
    EXPECT_EQ(fig.getCenter(), FigureConstants::DEFAULT_CENTER);
    EXPECT_EQ(fig.getPixels().size(), 4);
}

TEST(FigureCreatorTests, CreateFigureWithRotationTest) {
    FigureCreator creator;
    Figure fig = creator.createFigure(FigureConstants::TYPE_T, color::GREEN, FigureConstants::SECOND_ROTATION, FigureConstants::DEFAULT_CENTER);
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_T);
    EXPECT_EQ(fig.getColor(), color::GREEN);
    EXPECT_EQ(fig.getRotation(), FigureConstants::SECOND_ROTATION);
    EXPECT_EQ(fig.getCenter(), FigureConstants::DEFAULT_CENTER);
    EXPECT_EQ(fig.getPixels().size(), 4);
}

TEST(FigureCreatorTests, CreateFigureWithCenterTest) {
    FigureCreator creator;
    Figure fig = creator.createFigure(FigureConstants::TYPE_Z, color::YELLOW, FigureConstants::FIRST_ROTATION, {1, 1});
    EXPECT_EQ(fig.getType(), FigureConstants::TYPE_Z);
    EXPECT_EQ(fig.getColor(), color::YELLOW);
    EXPECT_EQ(fig.getRotation(), FigureConstants::FIRST_ROTATION);
    EXPECT_EQ(fig.getCenter(), std::make_pair(1, 1));
    EXPECT_EQ(fig.getPixels().size(), 4);
}

