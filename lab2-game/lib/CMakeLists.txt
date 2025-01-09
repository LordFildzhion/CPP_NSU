add_library(
    GameLibrary
    GameStarter.hpp

    Game.hpp

    Textures.hpp

    Asteroid.hpp
    Bullet.hpp
    Ship.hpp

    Mover.hpp
    Spawner.hpp

    GamePrinter.hpp

    Menu.hpp
    Button.hpp

    Background.hpp
    BackgroundPrinter.hpp
    BackgroundMover.hpp
    BackgroundSpawner.hpp
    BackgroundElement.hpp
)

set_target_properties(GameLibrary PROPERTIES LINKER_LANGUAGE CXX)
