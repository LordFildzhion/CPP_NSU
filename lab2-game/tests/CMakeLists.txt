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
    FigureTests.cpp
    PixelTests.cpp
    MapTests.cpp
    ../lib/Pixel/Pixel.cpp
    ../lib/Pixel/Pixel.hpp
    ../lib/Figure/Figure.hpp
    ../lib/Figure/Figure.cpp
    ../lib/Figure/FigureCreator.hpp
    ../lib/Map/Map.cpp
    ../lib/Map/Map.hpp
)

target_link_libraries(
    GameTests
    PUBLIC
    GTest::gtest_main
)

target_include_directories(
    GameTests
    PUBLIC ${CMAKE_SOURCE_DIR}/lib
)

include(GoogleTest)
gtest_discover_tests(GameTests)
