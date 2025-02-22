#include <gtest/gtest.h>

#include "CalculatesTests/GameSpeedTests.hpp"
#include "CalculatesTests/MoverTests.hpp"
#include "CalculatesTests/PrinterTests.hpp"
#include "CalculatesTests/SpawnerTests.hpp"

#include "DataTests/FontsTests.hpp"
#include "DataTests/ResoursesLoaderTests.hpp"
#include "DataTests/TexturesTests.hpp"

#include "GameObjectsTests/AsteroidTests.hpp"
#include "GameObjectsTests/BulletTests.hpp"
#include "GameObjectsTests/ShipTests.hpp"

#include "InterfaceElementsTests/ButtonTests.hpp"
#include "InterfaceElementsTests/TextTests.hpp"

#include "BackgroundTests.hpp"
#include "BacgroundElementTests.hpp"

#include "GameTests.hpp"
#include "MenuTests.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
