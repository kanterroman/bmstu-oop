cmake_minimum_required(VERSION 3.28)
project(lab_01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_COMPILER clang++)

set(APP_NAME "app1.exe")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
)

add_executable(${APP_NAME}
        Doors.cpp
        Doors.hpp
        Config.hpp
        Cabin.cpp
        Cabin.hpp
        Controller.cpp
        Controller.hpp
        Elevator.cpp
        Elevator.hpp
        mainwindow.cpp
        mainwindow.h
        main.cpp
)

include_directories(
)

target_link_libraries(${APP_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
