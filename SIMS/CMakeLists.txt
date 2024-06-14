cmake_minimum_required(VERSION 3.20.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options("/permissive-")
add_compile_options("/Zc:__cplusplus")


project(SIMS)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${PROJECT_SOURCE_DIR}/form)
set(CMAKE_PREFIX_PATH "F:/DevelopmentKitQT_MSVC/6.7.1/msvc2019_64"  )
set(MYSQL_CONNECTOR_CPP_DIR "F:/MySQL/MySQLConnectorC++8.4")


set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)



include_directories(${PROJECT_SOURCE_DIR}/includes
        ${PROJECT_SOURCE_DIR}/includes/form
        ${PROJECT_SOURCE_DIR}/includes/database
        ${PROJECT_SOURCE_DIR}/includes/model
        ${PROJECT_SOURCE_DIR}/includes/controller
        ${PROJECT_SOURCE_DIR}/includes/ui_filname_uic_h
        ${MYSQL_CONNECTOR_CPP_DIR}
        ${MYSQL_CONNECTOR_CPP_DIR}/include
        ${MYSQL_CONNECTOR_CPP_DIR}/lib64
        ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc
        ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc/cppconn
        ${CMAKE_CURRENT_SOURCE_DIR}

)


set(RESOURCES
        resources/icons/loginicon.png
)

set(SRC
        src/database/dbmanager.cpp
        src/database/querymodel.cpp
        src/controller/admincontroller.cpp
        src/model/student.cpp
        src/model/course.cpp
        src/model/StudentCourses.cpp
        src/controller/logincontroller.cpp
        src/controller/studentViewController.cpp
        src/model/teacherinformation.cpp
        src/database/dbmanager.cpp
        src/form/adminformAccountAndTeacherManagement.cpp
        src/controller/AccountManagementAndTeacherManagement.cpp
        src/database/dbmanagerAccountAndTeacher.cpp
        src/model/useraccount.cpp
)
set(FORM
        src/form/studentform.cpp
        includes/form/studentform.h
        form/studentform.ui
        src/form/loginform.cpp
        includes/form/loginform.h
        form/loginform.ui
        src/form/adminform.cpp
        includes/form/adminform.h
        form/adminform.ui
)
set(HEADER
        includes/database/dbmanager.h
        includes/database/querymodel.h
        includes/model/student.h
        includes/model/course.h
        includes/controller/admincontroller.h
        includes/model/StudentCourses.h
        includes/controller/logincontroller.h
        includes/controller/studentViewController.h
        includes/model/teacherinformation.h
        includes/model/teacherinformation.h
        includes/model/useraccount.h
        src/model/StudentScore.cpp
        includes/model/StudentScore.h

)



add_executable(SIMS main.cpp
        ${SRC}
        ${HEADER}
        ${FORM}
        ${RESOURCES}
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets

        REQUIRED)

target_link_libraries(SIMS
        Qt::Core
        Qt::Gui
        Qt::Widgets

)


target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR})
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/lib64)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/bin)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/include/jdbc/cppconn)
target_link_directories(${PROJECT_NAME} PRIVATE ${MYSQL_CONNECTOR_CPP_DIR}/lib64/vs14)
target_link_libraries(${PROJECT_NAME} mysqlcppconn8)
target_link_libraries(${PROJECT_NAME} mysqlcppconn)


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

    foreach (QT_LIB Core Gui Widgets Sql)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

