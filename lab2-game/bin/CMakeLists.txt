add_executable(${PROJECT_NAME}
                main.cpp
                ../lib/Pixel/Pixel.hpp
                ../lib/Pixel/Pixel.cpp
                ../lib/Figure/Figure.hpp
                ../lib/Figure/Figure.cpp
                ../lib/Figure/FigureCreator.hpp
                ../lib/Map/Map.cpp
                ../lib/Map/Map.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE GameLibrary)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})