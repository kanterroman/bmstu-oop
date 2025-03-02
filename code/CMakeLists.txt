cmake_minimum_required(VERSION 3.28)
project(lab_01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_COMPILER clang++)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(main.exe
        main.cpp
        mainwindow.cpp
)
target_link_libraries(main.exe
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
