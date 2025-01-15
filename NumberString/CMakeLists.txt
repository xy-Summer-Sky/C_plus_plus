cmake_minimum_required(VERSION 3.28)
project(NumberString)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "F:/DevelopmentKitQT_MSVC/6.7.1/msvc2019_64")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(NumberString main.cpp
        ui/convert.cpp
        ui/convert.h)
target_link_libraries(NumberString
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)

