cmake_minimum_required(VERSION 3.24)
project(cuphead)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake")


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)

file(GLOB_RECURSE SOURCES sources/*.cpp)

add_executable(cuphead ${SOURCES} resources.qrc includes/Graphics/GameWindows.h)

INCLUDE_DIRECTORIES(cuphead includes includes/MovingObjects includes/MovingObjects/Creatures includes/Graphics)

target_link_libraries(cuphead
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Multimedia
        )
