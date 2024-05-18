cmake_minimum_required(VERSION 3.28)
project(FirstC__APP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "F:/qt2/6.6.0/msvc2019_64")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        Network
        REQUIRED)

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/database
        ${PROJECT_SOURCE_DIR}/include/models
        ${PROJECT_SOURCE_DIR}/include/views
        ${PROJECT_SOURCE_DIR}/include/controllers
)

# Source files
set(SOURCES
        src/main.cpp
        src/database/dbmanager.cpp
        src/models/student.cpp
        src/models/course.cpp
        src/models/enrollment.cpp
        src/views/studentview.cpp
        src/views/adminview.cpp
        src/views/loginview.cpp
        src/controllers/studentcontroller.cpp
        src/controllers/admincontroller.cpp
)

# UI files
set(FORMS

        forms/adminview.cpp
        forms/adminview.h
        forms/loginview.cpp
        forms/adminview.ui
        forms/loginview.h
        forms/loginview.ui
        forms/studentview.cpp
        forms/studentview.h
        forms/studentview.ui


)

# Resources
set(RESOURCES
        resources/icons.qrc
)

# Create the executable
add_executable(FirstC__APP ${SOURCES} ${FORMS} ${RESOURCES})

# Link the Qt6 libraries
target_link_libraries(FirstC__APP Qt::Widgets Qt::Core Qt::Gui Qt::Sql Qt::Network)


if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

