cmake_minimum_required(VERSION 3.28)
project(FirstC__APP)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "F:/Qt/6.7.0/mingw_64")

find_package(Qt6 COMPONENTS Core Gui Widgets Sql Network REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/include/database
        ${PROJECT_SOURCE_DIR}/include/models
        ${PROJECT_SOURCE_DIR}/include/views
        ${PROJECT_SOURCE_DIR}/include/controllers
)

set(INCLUDES
        include/database/dbmanager.h
        include/database/querymodel.h
        include/models/student.h
        include/models/course.h
        include/models/enrollment.h
        include/views/ui_studentview.h
        include/views/ui_adminview.h
        include/views/ui_loginview.h
        include/controllers/studentcontroller.h
        include/controllers/admincontroller.h
)


set(SOURCES
        src/main.cpp
        src/database/dbmanager.cpp
        src/database/querymodel.cpp
        src/models/student.cpp
        src/models/course.cpp
        src/models/enrollment.cpp
        src/views/studentview.cpp
        src/views/adminview.cpp
        src/views/loginview.cpp
        src/controllers/studentcontroller.cpp
        src/controllers/admincontroller.cpp
)

set(UI_FILES
        forms/adminview.ui
        forms/loginview.ui
        forms/studentview.ui
)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})

set(RESOURCES
        resources/FirstC++APP.qrc
)

add_executable(FirstC__APP ${SOURCES} ${UI_HEADERS} ${RESOURCES})

target_link_libraries(FirstC__APP Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Sql Qt6::Network)

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