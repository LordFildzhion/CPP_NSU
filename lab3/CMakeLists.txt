cmake_minimum_required(VERSION 3.20.0)
project(lab3)

set(BOOST_ROOT "C:/boost")
set(BOOST_INCLUDER "C:/boost/boost-build/include/boost-1_87/")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(boost_program_options_FOUND TRUE)

find_package(Boost 1.87 REQUIRED COMPONENTS program_options )

add_executable(lab3 main.cpp ConfigReader.h Consts.h Converter.h Exceptions.h ProcessManager.h WAVEdit.h)

target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} )
