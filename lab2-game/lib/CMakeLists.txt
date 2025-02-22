add_library(
    GameLibrary
    Starter.hpp

    Game.hpp
    Menu.hpp
    Background.hpp
    BackgroundElement.hpp

    Data/Textures.hpp
    Data/Fonts.hpp
    Data/ResoursesLoader.hpp

    GameObjects/Asteroid.hpp
    GameObjects/Bullet.hpp
    GameObjects/Ship.hpp

    Calculates/Mover.hpp
    Calculates/Spawner.hpp
    Calculates/Printer.hpp
    Calculates/GameSpeed.hpp
    InterfaceElements/Button.hpp
    InterfaceElements/Text.hpp
)

target_include_directories(
    GameLibrary
    PUBLIC
    ${PROJECT_SOURCE_DIR}/lib/Calculates
    ${PROJECT_SOURCE_DIR}/lib/GameObjects
    ${PROJECT_SOURCE_DIR}/lib/Data
    ${PROJECT_SOURCE_DIR}/lib/InterfaceElements
)

set_target_properties(GameLibrary PROPERTIES LINKER_LANGUAGE CXX)
