include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(GameTests
    figureCreationTests.hpp
    figureTests.hpp
    pixelTests.hpp
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
add_test(NAME tests COMMAND tests)
