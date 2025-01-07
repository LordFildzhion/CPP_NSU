add_library(
    GameLibrary
    GameStarter.hpp

    Game.hpp
    Textures.hpp
    Asteroid.hpp
    Bullet.hpp
    Mover.hpp
    Spawner.hpp

    Menu.hpp
    Button.hpp
)

set_target_properties(GameLibrary PROPERTIES LINKER_LANGUAGE CXX)