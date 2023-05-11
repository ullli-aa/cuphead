cmake_minimum_required(VERSION 3.24)
project(game_spaceBattle)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "D:/Qt/5.15.2/mingw81_64/lib/cmake")


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(game_spaceBattle main.cpp MainWindow.cpp MovingObject.cpp Presenter.cpp Creatures.cpp Bullet.cpp Hero.cpp Model.cpp)
target_link_libraries(game_spaceBattle
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
