add_library(
    GameLibrary
    Pixel/Pixel.hpp
    Pixel/Pixel.cpp
    Figure/Figure.hpp
    Figure/Figure.cpp
    Map/Map.cpp
    Figure/FigureCreator.hpp
    Map/Map.hpp
)

set_target_properties(GameLibrary PROPERTIES LINKER_LANGUAGE CXX)
