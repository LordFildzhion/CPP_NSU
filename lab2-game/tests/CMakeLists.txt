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
    GameTests.cpp
    GameStarterTests.cpp

    ../lib/GameStarter.hpp

    ../lib/Game.hpp
    ../lib/Textures.hpp
    ../lib/Asteroid.hpp
    ../lib/Bullet.hpp
    ../lib/Mover.hpp
    ../lib/Spawner.hpp

    ../lib/Menu.hpp
    ../lib/Button.hpp
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
