#include "GameStarter.hpp"

#include "MenuTests.hpp"
#include "ButtonTests.hpp"

#include "GameTests.hpp"

#include "TexturesTests.hpp"

#include "AsteroidTests.hpp"
#include "ShipTests.hpp"
#include "BulletTests.hpp"

#include "SpawnerTests.hpp"
#include "MoverTests.hpp"

#include "GamePrinterTests.hpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
