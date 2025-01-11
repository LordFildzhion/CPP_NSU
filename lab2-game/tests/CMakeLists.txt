include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
    GameTests
    mainTests.cpp

    CalculatesTests/GameSpeedTests.hpp
    CalculatesTests/MoverTests.hpp
    CalculatesTests/PrinterTests.hpp
    CalculatesTests/SpawnerTests.hpp

    DataTests/FontsTests.hpp
    DataTests/ResoursesLoaderTests.hpp
    DataTests/TexturesTests.hpp

    GameObjectsTests/AsteroidTests.hpp
    GameObjectsTests/BulletTests.hpp
    GameObjectsTests/ShipTests.hpp

    InterfaceElementsTests/ButtonTests.hpp
    InterfaceElementsTests/TextTests.hpp

    BackgroundTests.hpp
    BacgroundElementTests.hpp

    GameTests.hpp
    MenuTests.hpp
)

target_link_libraries(
    GameTests
    PUBLIC
    GTest::gtest_main
    GameLibrary
    SFML::Graphics
)

target_include_directories(
    GameTests
    PUBLIC
    ${CMAKE_SOURCE_DIR}/lib
)

include(GoogleTest)
gtest_discover_tests(GameTests)
